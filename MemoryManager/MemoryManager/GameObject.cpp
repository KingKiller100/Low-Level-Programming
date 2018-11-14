#include "GameObject.h"
#include <iostream>

Heap *GameObject::_heap = nullptr;

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
	std::cout << "GameObject Destructor Called\n" << std::endl;
}

void GameObject::Update()
{
	int* x = (int*) ::operator new(sizeof(int), _heap);

	std::cin.get();

	::operator delete(x);
}

