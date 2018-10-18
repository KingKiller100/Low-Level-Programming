#include "stdafx.h"
#include "Structures.h"

void * operator new(size_t size)
{
	Heap *h = HeapFactory::GetDefaultHeap();

	if (h == nullptr)
	{
		size_t nRequestedBytes = size + sizeof(AllocHeader);
		char *pMem = (char*)malloc(nRequestedBytes);
		AllocHeader* pheader = (AllocHeader*)pMem;
		pheader->pHeap = NULL;
		void *pStartMemBlock = pMem + sizeof(AllocHeader);
		
		return pStartMemBlock;
	}

	return operator new(size, h);
}

void operator delete(void * pMem)
{
	AllocHeader *pHeader = (AllocHeader*)((char*)pMem - sizeof(AllocHeader));

if (pHeader->pHeap != NULL)
	pHeader->pHeap->RemoveAllocation(pHeader->iSize);

	free(pHeader);
}

void * operator new(size_t size, Heap * pHeap)
{
	size_t nRequestedBytes = size + sizeof(AllocHeader);
	char *pMem = (char*)malloc(nRequestedBytes);
	AllocHeader *pHeader = (AllocHeader*)pMem;
	pHeader->pHeap = pHeap;
	pHeader->iSize = (int)size;
	pHeap->AddAllocation(size);
	void * pStartMemBlock = pMem + sizeof(AllocHeader);
	
	return pStartMemBlock;
}