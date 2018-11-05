#include "stdafx.h"
#include "Structures.h"
#include <iostream>
#include <string>
#include "MemoryOverride.h"
#include "Vector3D.h"

//Heap *MemoryOverride::_classHeap = nullptr;

int main()
{
	//GameObject* _g		= new GameObject(0);
	//GameObject* _g2		= new GameObject(1);

	//std::cout << "GameObject Size" << sizeof(GameObject)<< std::endl;

	Vector3D* _v = new Vector3D(rand() % 10, rand() % 10, rand() % 10);
	Vector3D* _v2 = new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	std::cout << "Vector3D Size " << sizeof(Vector3D) << std::endl;
	
	std::cin.get();
	
	//delete _g;

	std::cin.get();

	delete _v;
	delete _v2;


	std::cin.get();

	return 0;
}

