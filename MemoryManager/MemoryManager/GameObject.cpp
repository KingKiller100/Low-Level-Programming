#include "GameObject.h"
#include <iostream>

Heap *GameObject::heap = nullptr;

GameObject::GameObject()
{
	m_id = 0;
	std::cout << "GameObject Constructor Called" << std::endl;
}

GameObject::GameObject(int id) : m_id(id)
{
	std::cout << "GameObject Constructor Called\n" << std::endl;
}

GameObject::~GameObject()
{
	std::cout << "GameObject Destructor Called" << std::endl;
}

void GameObject::Update()
{
	int* x = (int*)MemManagement::operator new(sizeof(int), heap);

	std::cin.get();

	MemManagement::operator delete(x);
}

