#include "Structures.h"

void * operator new(size_t size, Heap * pHeap)
{
	size_t iRequestedBytes = size + sizeof(AllocHeader) + sizeof(int);
	char *pMem = (char*)malloc(iRequestedBytes);
	AllocHeader *pHeader = (AllocHeader*)pMem;
	pHeader->iSignature = MEMSYSTEM_SIGNATURE;
	pHeader->pHeap = pHeap;
	pHeader->iSize = (int)size;
	
	pHeader->_prev = pHeader->_next = nullptr;
	pHeader->pHeap->_prevAddress = pHeader; //Points at itself

	if (pHeader->pHeap->_prevAddress)
	{
		pHeader->_next = nullptr;
		AllocHeader* copy = (AllocHeader*)pHeader->pHeap->_prevAddress;
		pHeader->_prev = copy;
		copy->_next = pHeader;
		pHeader->pHeap->_prevAddress = pHeader;
	}

	auto *pStartMemBlock = pMem + sizeof(AllocHeader);
	int *pEndMarker = (int*)((char*)pStartMemBlock + size);
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
	auto *pHeader = (AllocHeader*)((char*)pMem - sizeof(AllocHeader));

	auto heap = pHeader->pHeap;
	auto size = pHeader->iSize;
	auto sig = pHeader->iSignature;
	auto next = pHeader->_next;
	auto prev = pHeader->_prev;

	assert(sig == MEMSYSTEM_SIGNATURE);

	if (next)
		next->_prev = prev;

	if (prev)
		prev->_next = next;

	if (!prev && !next)
		heap->_prevAddress = nullptr;

	auto *pEndMarker = (int*)((char*)pMem + size);

	assert(*pEndMarker == MEMSYSTEM_ENDMARKER);

	heap->RemoveAllocation(size + sizeof(AllocHeader) + sizeof(int));
	free(pHeader);
}