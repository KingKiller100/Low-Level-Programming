#pragma once
#include "HeapFactory.h"

struct AllocHeader
{
	Heap* pHeap;
	int iSize;
};

class MemoryManagement
{
public:
	static void * operator new(size_t size);
	static void * operator new(size_t size, Heap *pHeap);
	static void operator delete (void *pMem);

};


