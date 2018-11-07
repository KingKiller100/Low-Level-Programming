#pragma once
#include "HeapFactory.h"
#include <cassert>

void * operator new(size_t size, Heap * pHeap);
void * operator new(size_t size);
void operator delete(void * pMem);

