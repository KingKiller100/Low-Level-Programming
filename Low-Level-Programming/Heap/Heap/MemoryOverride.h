#pragma once
#include "stdafx.h"
#include <typeinfo>
#include "HeapFactory.h"
#include "Structures.h"

template<class X>
class MemoryOverride
{	
public:
	void * operator new(size_t size)
	{
		if (!X::Heap)
			X::Heap = HeapFactory::CreateHeap(typeid(X).name());

		return MemManagement::operator new(size, X::Heap);
	}

	void operator delete(void *pMem, size_t size)
	{
		MemManagement::operator delete(pMem);
	}
};

