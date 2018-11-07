#pragma once 
#include <typeinfo>
#include "HeapFactory.h"
#include "Structures.h"

template<class X>
class MemoryOverride
{	
public:
	void * operator new(size_t size)
	{
		if (!X::heap)
			X::heap = HeapFactory::CreateHeap(typeid(X).name());

		return ::operator new(size, X::heap);
	}

	void operator delete(void *pMem, size_t size)
	{
		::operator delete(pMem);
	}
};

