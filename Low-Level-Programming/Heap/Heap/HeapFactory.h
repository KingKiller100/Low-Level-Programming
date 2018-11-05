#pragma once
#include "Heap.h"
#include <vector>

class HeapFactory
{
private:
	static Heap *_defaultHeap;
	static std::vector<Heap*> heapContainer;
public:
	HeapFactory();
	~HeapFactory();

	static Heap *CreateHeap(std::string szName);
	static Heap* GetDefaultHeap();
};

