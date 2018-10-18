#include "stdafx.h"
#include <iostream>
#include "HeapFactory.h"

std::vector<Heap*> HeapFactory::heapContainer;
Heap* HeapFactory::defaultHeap = nullptr;

HeapFactory::HeapFactory()
{
	CreateDefaultHeap();
}

HeapFactory::~HeapFactory()
{
	free(defaultHeap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	Heap *newHeap = (Heap*)malloc(sizeof(Heap(szName)));

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
