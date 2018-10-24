#include "stdafx.h"
#include "GameObject.h"
#include "Structures.h"
#include<iostream>

Heap *GameObject::s_pHeap = nullptr;

GameObject::GameObject(int id)
{
	m_id = id;

	//int *x = new (s_pHeap) int;

	std::cout << "GameObject Created" << std::endl;
}

GameObject::~GameObject()
{
}

void * GameObject::operator new(size_t size)
{
	if (s_pHeap == nullptr)
		s_pHeap = HeapFactory::CreateHeap("Game Object");

	return MemoryManagement::operator new(sizeof(GameObject));
}

void GameObject::operator delete(void* pMem, size_t size)
{
	//s_pHeap->RemoveAllocation(size);
	MemoryManagement::operator delete(pMem);
	std::cout << "GameObject is deleted" << std::endl;
}


