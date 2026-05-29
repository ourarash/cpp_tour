#include <iostream>

template <size_t blockSize>
class PoolAlloc {
 public:
  // Construct Pool Allocator with requested number of blocks
  PoolAlloc(size_t numBlocks);
  // Destruct the Pool Allocator
  ~PoolAlloc();
  // Allocates a block, if possible
  void* Allocate(size_t size);
  // Puts a block back into the free list
  void Free(void* ptr);
  // Disallow copy construction, assignment, and moves
  // ...
 private:
  union PoolBlock {
    // Usable memory of the block
    char mMemory[blockSize];
    // Pointer to next block that's free
    PoolBlock* mNext;
  };
  PoolBlock* mHead;       // Pointer to head of free list
  PoolBlock* mAllBlocks;  // Pointer to array of all blocks
  size_t mFreeBlocks;     // Tracks the number of free blocks
  size_t mTotalBlocks;    // Tracks the total number of blocks
};

template <size_t blockSize>
PoolAlloc<blockSize>::PoolAlloc(size_t numBlocks)
    : mHead(nullptr),
      mAllBlocks(nullptr),
      mFreeBlocks(numBlocks),
      mTotalBlocks(numBlocks) {
  // First, allocate "all blocks" as an array of numBlocks blocks
  mAllBlocks = new PoolBlock[numBlocks];

  // Set the "next pointer" for all blocks
  // (Initially, this is just to the block at the next index)
  for (unsigned i = 0; i < mTotalBlocks - 1; i++) {
    mAllBlocks[i].mNext = &mAllBlocks[i + 1];
  }

  // The next for the last block is null (end of list)
  mAllBlocks[mTotalBlocks - 1].mNext = nullptr;
  // The head of the free list is just the first block in "all blocks"
  mHead = &mAllBlocks[0];
}

template <size_t blockSize>
void* PoolAlloc<blockSize>::Allocate(size_t size) {
  // Only return a block if the alloc request fits,
  // and there are blocks available
  if (mFreeBlocks > 0 && size <= blockSize) {
    // Save the address of the head
    PoolBlock* oldHead = mHead;
    // Advance the head
    mHead = mHead->mNext;
    // One less block is free
    mFreeBlocks--;
    // Return the old head block
    return oldHead;
  } else {
    return nullptr;
  }
}

template <size_t blockSize>
void PoolAlloc<blockSize>::Free(void* ptr) {
  // NOTE: In a professional-grade allocator, we should verify that
  // ptr is actually a block in this pool!

  // Cast to the block pointer type
  PoolBlock* reclaimed = static_cast<PoolBlock*>(ptr);
  // Make the reclaimed block the head of the free list
  reclaimed->mNext = mHead;
  mHead = reclaimed;
  // One more block is free
  mFreeBlocks++;
}

template <size_t blockSize>
PoolAlloc<blockSize>::~PoolAlloc() {
  // Delete all the blocks
  delete[] mAllBlocks;
  // Clean up member variables, just in case
  mHead = nullptr;
  mAllBlocks = nullptr;
  mFreeBlocks = 0;
  mTotalBlocks = 0;
}

//-----------------------------------------------------
class MyClass {
 public:
  MyClass() { std::cout << "Constructor!" << std::endl; }
  ~MyClass() { std::cout << "Destructor!" << std::endl; }

  void Talk() { std::cout << "My name is MyClass!" << std::endl; }

  // Override operator "new" to allocate from pool
  static void* operator new(size_t size) { return sTestPool.Allocate(size); }
  // Override operator "delete" to free back to pool
  static void operator delete(void* ptr) { sTestPool.Free(ptr); }
  // Note: Should also overload new[] and delete[], which are similar
 private:
  // Static PoolAllocator that's shared by all instances of MyClass!
  static PoolAlloc<8> sTestPool;
  double a;
};
PoolAlloc<sizeof(MyClass)> MyClass::sTestPool(1000);

int main(int argc, char const* argv[]) {
  {
    MyClass* myTest = new MyClass();
    myTest->Talk();
    std::cout << "sizeof(myTest): " << sizeof(myTest) << std::endl;
    delete myTest;
  }

  return 0;
}