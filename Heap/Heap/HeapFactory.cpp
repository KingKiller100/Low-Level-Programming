#include "stdafx.h"
#include "HeapFactory.h"

Heap* HeapFactory::defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer = { HeapFactory::defaultHeap };

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{
	free(defaultHeap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	Heap *newHeap = new Heap(szName);

	heapContainer.push_back(newHeap);

	return newHeap;
}

void HeapFactory::CreateDefaultHeap()
{
	defaultHeap = (Heap*)malloc(sizeof(Heap));
	heapContainer.push_back(defaultHeap);
}

Heap * HeapFactory::GetDefaultHeap()
{
	if (heapContainer.empty())
		CreateDefaultHeap();

	return heapContainer.front();
}
