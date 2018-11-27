#include "HeapFactory.h"
#include <iostream>

Heap* HeapFactory::_defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer;

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{

	if (_defaultHeap)
		free(_defaultHeap);
	for (Heap* heap : heapContainer)
		free(heap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	std::cout << "Creating Heap " << szName << "\n" << std::endl;
	
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	newHeap->Initialize(szName);

	heapContainer.emplace_back(newHeap);	
	return newHeap;
}

Heap* HeapFactory::GetDefaultHeap()
{
	if (_defaultHeap)
		return _defaultHeap;

	_defaultHeap = (Heap*)malloc(sizeof(Heap));
	_defaultHeap->Initialize("default");

	heapContainer.emplace_back(_defaultHeap);

	return heapContainer.at(0);
}

void HeapFactory::WalkTheHeap(const size_t &id)
{
	if (id == 0)
	{
		_defaultHeap->WalkHeap();
		return;
	}

	if (id < heapContainer.size())
		heapContainer.at(id)->WalkHeap();
	else
		std::cout << "outside heap container scope \n" << std::endl;
}
