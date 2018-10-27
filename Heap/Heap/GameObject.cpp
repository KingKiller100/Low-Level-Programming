#include "stdafx.h"
#include "GameObject.h"
#include "Structures.h"
#include <iostream>

Heap *GameObject::s_pHeap = nullptr;
int GameObject::count = 0;

GameObject::GameObject(int id) : m_id(id) 
{
	std::cout << "GameObject Constructor Called" << std::endl;
}

GameObject::~GameObject()
{
	std::cout << "GameObject Destructor Called" << std::endl;
}

void * GameObject::operator new(size_t size)
{
	if (s_pHeap == nullptr)
		s_pHeap = HeapFactory::CreateHeap("Game Object" + count);

	count++;

	return MemoryManagement::operator new(sizeof(GameObject));
}

void GameObject::operator delete(void* pMem, size_t size)
{
	MemoryManagement::operator delete(pMem);
}
