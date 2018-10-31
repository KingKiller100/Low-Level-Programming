#include "stdafx.h"
#include "HeapFactory.h"
#include <utility>
#include <iostream>
Heap* HeapFactory::_defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer = std::vector<Heap*>();

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{
	free(_defaultHeap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	std::cout << "Creating Heap" << szName << std::endl;
	
	auto newHeap = (Heap*)malloc(sizeof(Heap));
	newHeap->SetName(szName);
	newHeap->m_allocatedBytes = 0;

	heapContainer.push_back(newHeap);
	
	return newHeap;
}

Heap* HeapFactory::GetDefaultHeap()
{
	std::cout << "Creating Default Heap" << std::endl;

	if (_defaultHeap)
		return _defaultHeap;

	_defaultHeap = (Heap*)malloc(sizeof(Heap));
	_defaultHeap->SetName("default");
	_defaultHeap->m_allocatedBytes = 0;

	return _defaultHeap;
}
