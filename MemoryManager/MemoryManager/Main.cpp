 
#include <iostream>
#include <string>
#include "MemoryOverride.h"
#include "Vector3D.h"
#include "GameObject.h"
#include "Structures.h"

int main()
{
	HeapFactory::GetDefaultHeap();

	GameObject* _g		= new GameObject(0);
	Vector3D* _v		= new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	Vector3D* _v2		= new Vector3D(rand() % 10, rand() % 10, rand() % 10);
	GameObject* _g2		= new GameObject(1);

	std::cin.get();

	_g->Update();
	_g2->Update();
	
	std::cin.get();

	HeapFactory::WalkHeap(0);
	HeapFactory::WalkHeap(1);
	HeapFactory::WalkHeap(2);

	std::cin.get();
	
	delete _g;
	delete _g2;

	std::cin.get();

	delete _v;
	delete _v2;
	
	std::cin.get();

	return 0;
}

