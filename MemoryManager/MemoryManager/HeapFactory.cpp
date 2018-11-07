#include "HeapFactory.h"
#include <iostream>

Heap* HeapFactory::_defaultHeap = nullptr;
std::vector<Heap*> HeapFactory::heapContainer;

HeapFactory::HeapFactory() {}

HeapFactory::~HeapFactory()
{
	for (Heap* heap : heapContainer)
		free(heap);
}

Heap * HeapFactory::CreateHeap(const char * szName)
{
	std::cout << "Creating Heap " << szName << "\n" << std::endl;
	
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	//Heap* newHeap = new Heap(szName);
	newHeap->Initialise(szName);
	heapContainer.emplace_back(newHeap);	
	return newHeap;
}

Heap* HeapFactory::GetDefaultHeap()
{
	std::cout << "Getting Default Heap" << std::endl;

	if (_defaultHeap)
		return _defaultHeap;

	std::cout << "Create Default Heap" << std::endl;

	_defaultHeap = (Heap*)malloc(sizeof(Heap));
	//_defaultHeap = new Heap("Default");

	_defaultHeap->Initialise("default");
	heapContainer.emplace_back(_defaultHeap);

	return _defaultHeap;
}

void HeapFactory::WalkHeap(int id)
{
	if (heapContainer.at(id))
	{
		heapContainer.at(id)->WalkHeap();
	}
}
