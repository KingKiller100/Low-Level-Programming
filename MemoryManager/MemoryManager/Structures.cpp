#include "Structures.h"
#include <iostream>

void * operator new(size_t size, Heap * pHeap)
{
	size_t iRequestedBytes = size + sizeof(AllocHeader) + sizeof(int);
	auto *pMem = (char*)malloc(iRequestedBytes);
	auto *pHeader = (AllocHeader*)pMem;
	
	pHeader->pHeap = pHeap;
	pHeader->iSize = (int)size;
	
	pHeader->_prev = pHeader->_next = nullptr;

	if (pHeader->pHeap->_prevAddress)
	{
		pHeader->_next = nullptr;
		auto* copy = static_cast<AllocHeader*>(pHeader->pHeap->_prevAddress);
		pHeader->_prev = copy;
		copy->_next = pHeader;
		pHeader->pHeap->_prevAddress = pHeader; // Points at itself
	}
	else
	{
		pHeader->_next = nullptr;
		auto* copy = static_cast<AllocHeader*>(pHeader->pHeap->_prevAddress);
		pHeader->_prev = copy;
		pHeader->pHeap->_prevAddress = pHeader; // Points at itself
	}

	pHeader->iSignature = MEMSYSTEM_SIGNATURE;

	auto *pStartMemBlock = pMem + sizeof(AllocHeader);
	auto*pEndMarker = reinterpret_cast<int*>(static_cast<char*>(pStartMemBlock) + size);
	*pEndMarker = MEMSYSTEM_ENDMARKER;

	pHeap->AddAllocation(iRequestedBytes);

	return pStartMemBlock;
}

void * operator new(size_t size)
{
 	return operator new(size, HeapFactory::GetDefaultHeap());
}

void operator delete(void * pMem)
{
	auto *pHeader = reinterpret_cast<AllocHeader*>(static_cast<char*>(pMem) - sizeof(AllocHeader));

	auto heap = pHeader->pHeap;
	auto size = pHeader->iSize;
	int sig = pHeader->iSignature;
	auto next = pHeader->_next;
	auto prev = pHeader->_prev;

	assert(sig == MEMSYSTEM_SIGNATURE);

	if (next)
	{
		next->_prev = prev;
		heap->_prevAddress = next->pHeap->_prevAddress;
	}

	if (prev)
	{
		prev->_next = next;
		
		if(!next)
			heap->_prevAddress = prev->pHeap->_prevAddress;
	}

	if (!prev && !next)
		heap->_prevAddress = nullptr;


	auto *pEndMarker = static_cast<int*>(reinterpret_cast<int*>(static_cast<char*>(pMem) + size));

	assert(*pEndMarker == MEMSYSTEM_ENDMARKER);

	heap->RemoveAllocation(size + sizeof(AllocHeader) + sizeof(int));
	free(pHeader);

	std::cin.get();
}