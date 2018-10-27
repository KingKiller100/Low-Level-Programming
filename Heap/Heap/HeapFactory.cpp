#include "stdafx.h"
#include "HeapFactory.h"

Heap* HeapFactory::_defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer;

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{
	free(_defaultHeap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	Heap *newHeap = new Heap(szName);

	heapContainer.push_back(newHeap);

	return newHeap;
}

void HeapFactory::CreateDefaultHeap()
{
	_defaultHeap = new Heap("Heap");
	heapContainer.push_back(_defaultHeap);
}

Heap * HeapFactory::GetDefaultHeap()
{
	if (_defaultHeap == nullptr)
		CreateDefaultHeap();

	return _defaultHeap;
}
