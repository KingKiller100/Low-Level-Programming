 
#include "Structures.h"
#include <iostream>
#include "Vector3D.h"
#include "GameObject.h"

int main()
{
	GameObject* _g		= new GameObject(0);
	Vector3D* _v		= new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	Vector3D* _v2		= new Vector3D();
	GameObject* _g2		= new GameObject(2);

	Vector3D* _v3		= new Vector3D();
	GameObject* _g3		= new GameObject(3);


	std::cout << _g << std::endl;
	std::cout << _g2 << std::endl;
	std::cout << _g3 << std::endl;

	_g->Update();
	_g2->Update();
	_g3->Update();

	std::cin.get();

	_v->Update();
	_v2->Update();
	_v3->Update();

	std::cin.get();

	HeapFactory::WalkHeap(1);
	HeapFactory::WalkHeap(0);
	HeapFactory::WalkHeap(2);

	std::cin.get();
	
	delete _g;
	delete _g2;
	delete _g3;
	
	std::cin.get();

	delete _v;
	delete _v2;
	delete _v3;
	
	std::cin.get();

	return 0;
}


