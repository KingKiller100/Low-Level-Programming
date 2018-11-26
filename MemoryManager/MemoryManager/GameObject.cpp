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
	const unsigned char* x	= new(_heap) unsigned char();
	const unsigned char* x2 = new(_heap) unsigned char();
	const unsigned char* x3 = new(_heap) unsigned char();

	//delete x;
	//delete x2;
	//delete x3;
}
