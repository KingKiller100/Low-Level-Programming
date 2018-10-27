#include "stdafx.h"
#include "Structures.h"
#include <cassert>

#define MEMSYSTEM_SIGNATURE 3735929054
#define MEMSYSTEM_ENDMARKER 3735928559

void * MemoryManagement::operator new(size_t size)
{
	Heap *h = HeapFactory::GetDefaultHeap();

	if (h == NULL)
	{
		size_t nRequestedBytes = size + sizeof(AllocHeader);
		char *pMem = (char*)malloc(nRequestedBytes);
		AllocHeader* pheader = (AllocHeader*)pMem;
		pheader->pHeap = NULL;
		void *pStartMemBlock = pMem + sizeof(AllocHeader);
		
		return pStartMemBlock;
	}

	return MemoryManagement::operator new(size, h);
}

void MemoryManagement::operator delete(void * pMem)
{
	AllocHeader *pHeader = (AllocHeader*)((char*)pMem - sizeof(AllocHeader));

	assert(pHeader->iSignature == MEMSYSTEM_SIGNATURE);
	int *pEndMarker = (int *)(sizeof(pMem) + pHeader->iSize);
	assert(*pEndMarker == MEMSYSTEM_ENDMARKER);

	if (pHeader->pHeap != NULL)
		pHeader->pHeap->RemoveAllocation(pHeader->iSize);

	free(pHeader);
}

void * MemoryManagement::operator new(size_t size, Heap * pHeap)
{
	size_t iRequestedBytes = size + sizeof(AllocHeader) + sizeof(int);
	char *pMem = (char*)malloc(iRequestedBytes);
	AllocHeader *pHeader = (AllocHeader*)pMem;
	pHeader->iSignature = MEMSYSTEM_SIGNATURE;
	pHeader->pHeap = pHeap;
	pHeader->iSize = (int)size;

	auto *pStartMemBlock = pMem + sizeof(AllocHeader);
	int *pEndMarker = (int*)(pStartMemBlock + size);
	*pEndMarker = MEMSYSTEM_ENDMARKER;
	pHeap->AddAllocation(size);
	
	return pStartMemBlock;
}