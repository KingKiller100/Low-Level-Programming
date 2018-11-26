  
#include "Heap.h"
#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t iObjectsize)
{
	
}


MemoryPool::~MemoryPool()
{
}

void * MemoryPool::Alloc(size_t iSize)
{
	return nullptr;
}

void MemoryPool::Free(void * pMem, size_t i_size)
{
	::operator delete(pMem);
}
