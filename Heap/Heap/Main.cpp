#include "stdafx.h"
#include <iostream>
#include <string>
#include "Structures.h"
#include "GameObject.h"
#include "Vector3D.h"

int main()
{
	Heap *_h = HeapFactory::GetDefaultHeap();

	GameObject* _g = new GameObject(0);
	GameObject* _g2 = new GameObject(1);

	Heap *h2 = new Heap("V3D Heap");
	Vector3D* _v = new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	std::cin.get();

	delete _g;
	delete _g2;

	std::cin.get();

	delete _v;

	std::cin.get();

	return 0;
}

