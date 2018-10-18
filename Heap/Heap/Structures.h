#pragma once
#include "HeapFactory.h"

struct AllocHeader
{
	Heap* pHeap;
	int iSize;
};

void * operator new(size_t size);
void * operator new(size_t size, Heap *pHeap);
void operator delete (void *pMem);

