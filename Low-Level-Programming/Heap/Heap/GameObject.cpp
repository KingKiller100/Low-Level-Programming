#include "stdafx.h"
#include "GameObject.h"
#include <iostream>

Heap *GameObject::g_Heap = nullptr;

GameObject::GameObject()
{
	m_id = 0;
	std::cout << "GameObject Constructor Called" << std::endl;
}

GameObject::GameObject(int id) : m_id(id)
{
	std::cout << "GameObject Constructor Called" << std::endl;
}

GameObject::~GameObject()
{
	std::cout << "GameObject Destructor Called" << std::endl;
}

//void * GameObject::operator new(size_t size)
//{
//	if (go_pHeap == nullptr)
//	{
//		go_pHeap = HeapFactory::CreateHeap("Game Object");
//	}
//	
//	return MemManagement::operator new(size, go_pHeap);
//}
//
//void GameObject::operator delete(void* pMem, size_t size)
//{
//	MemManagement::operator delete(pMem);
//}
