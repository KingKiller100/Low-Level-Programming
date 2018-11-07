#pragma once

#include "HeapFactory.h"
#include <cassert>

#define MEMSYSTEM_SIGNATURE 0xdeadc0de //233495774
#define MEMSYSTEM_ENDMARKER 0xdeadbeef //218815710

struct AllocHeader
{
	int iSignature;
	Heap *pHeap;
	int iSize;
	AllocHeader *_next;
	AllocHeader *_prev;
};

void * operator new(size_t size, Heap * pHeap);
void * operator new(size_t size);
void operator delete(void * pMem);

