 
#include "HeapFactory.h"
#include <utility>
#include <iostream>
Heap* HeapFactory::_defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer;

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{
	free(_defaultHeap);
}

Heap * HeapFactory::CreateHeap(std::string szName)
{
	std::cout << "Creating Heap " << szName << "\n" << std::endl;
	
	Heap* newHeap = new Heap(szName);

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
