#pragma once
#include "HeapFactory.h"

struct AllocHeader
{
	int iSignature;
	Heap *pHeap;
	int iSize;
	AllocHeader *_next;
	AllocHeader *_prev;
};

class MemoryManagement
{
public:
	static void * operator new(size_t size);
	static void * operator new(size_t size, Heap *pHeap);
	static void operator delete (void *pMem);

};


