#include <iostream>
#include <memory_resource>

int main()
{
	// All memory_resources have an allocate and deallocate function
	
	// Use pool_options to configure the pool
	std::pmr::pool_options options;
	// Maximum of 1024 blocks
	options.max_blocks_per_chunk = 1024;
	// Largest block size required in bytes
	options.largest_required_pool_block = 16;

	// This is a non-thread safe pool allocator
	std::pmr::unsynchronized_pool_resource poolAlloc(options);
	// Allocate 12 bytes
	void* ptr = poolAlloc.allocate(12);
	// Deallocate the memory
	poolAlloc.deallocate(ptr, 12);

	// A monotonic_buffer_resource is like the "stack allocator"
	std::pmr::monotonic_buffer_resource stackAlloc;
	
	// Allocate 50 bytes
	void* ptr2 = stackAlloc.allocate(50);

	// Deallocate won't do anything in this case!
	stackAlloc.deallocate(ptr2, 50);

	// To release all the memory use the release function
	// (Also happens when the destructor is called)
	stackAlloc.release();

	return 0;
}
