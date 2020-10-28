class BasicStackAlloc {
 public:
  // Constructs the stack allocator to requested size
  BasicStackAlloc(size_t size);
  // Destructor
  ~BasicStackAlloc();
  // Gets how many bytes are left in the stack
  size_t GetBytesRemaining() const;
  // Allocates the specified number of bytes, if available,
  // and returns a pointer to this allocation
  // Returns nullptr if not enough bytes are left
  void* Allocate(size_t size);
  // Disallow copy construction, assignment, and moves
  BasicStackAlloc(const BasicStackAlloc&) = delete;
  BasicStackAlloc& operator=(const BasicStackAlloc&) = delete;
  BasicStackAlloc(BasicStackAlloc&&) = delete;
  BasicStackAlloc& operator=(BasicStackAlloc&&) = delete;

 private:
  // Pointer to the beginning of the usable memory area of the stack
  char* mMemoryBuffer;
  // Pointer to top of stack
  char* mTop;
};

BasicStackAlloc::BasicStackAlloc(size_t size)
    : mMemoryBuffer(nullptr), mTop(nullptr) {
  // Allocate specified bytes
  mMemoryBuffer = new char[size];
  // The "top" should be at the end of the buffer
  // (pointer arithmetic)
  mTop = mMemoryBuffer + size;
}

BasicStackAlloc::~BasicStackAlloc() {
  delete[] mMemoryBuffer;
  mMemoryBuffer = nullptr;
  mTop = nullptr;
}
size_t BasicStackAlloc::GetBytesRemaining() const {
  return (mTop - mMemoryBuffer);
}

void* BasicStackAlloc::Allocate(size_t size) {
  // If we have enough space, move the top by the size
  // and return this address
  if (GetBytesRemaining() >= size) {
    mTop -= size;
    return mTop;
  } else {
    // Not enough space, so return null
    return nullptr;
  }
}
