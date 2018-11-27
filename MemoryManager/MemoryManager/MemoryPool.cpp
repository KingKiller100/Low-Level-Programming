#include <cassert>
#include "MemoryPool.h"

MemoryPool::MemoryPool() : _currentAddress(memBlock)
{}

void MemoryPool::Initialize()
{
	if (!_currentAddress)

		_currentAddress = memBlock;
}

MemoryPool::~MemoryPool()
{}

void* MemoryPool::Alloc(size_t iSize)
{
	assert(_currentAddress + iSize <= memBlock + sizeof(memBlock) && "Full");
	void* _newAddress = _currentAddress;
	_currentAddress += iSize;
	return _newAddress;

	void* newMem;
}

void MemoryPool::FreeMemory(void* pMem, size_t i_size)
{
	
}
