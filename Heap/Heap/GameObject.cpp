#include "stdafx.h"
#include "GameObject.h"
#include "Structures.h"
#include <iostream>

Heap *GameObject::go_pHeap = nullptr;
int GameObject::count = 0;

GameObject::GameObject(int id) : m_id(id) 
{
	int* x = new (go_pHeap) int;
	std::cout << "GameObject Constructor Called" << std::endl;
}

GameObject::~GameObject()
{
	std::cout << "GameObject Destructor Called" << std::endl;
}

void * GameObject::operator new(size_t size)
{
	if (go_pHeap == nullptr)
		go_pHeap = HeapFactory::CreateHeap("Game Object" + count);

	count++;

	return MemoryManagement::operator new(sizeof(GameObject));
}

void GameObject::operator delete(void* pMem, size_t size)
{
	MemoryManagement::operator delete(pMem);
}
