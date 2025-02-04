 
#include "Structures.h"
#include <iostream>
#include "Vector3D.h"
#include "GameObject.h"

#define GetInput std::cin.get();

int main()
{

	GameObject* _g		= new GameObject(0);
	Vector3D* _v		= new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	Vector3D* _v2		= new Vector3D();
	GameObject* _g2		= new GameObject(2);

	Vector3D* _v3		= new Vector3D();
	GameObject* _g3		= new GameObject(3);
	
	GetInput

	_g->Update();
	_g2->Update();
	_g3->Update();


	GetInput

	_v->Update();
	_v2->Update();
	_v3->Update();
	
	delete _g2;

	GetInput

	HeapFactory::WalkTheHeap(1);
	HeapFactory::WalkTheHeap(2);
	HeapFactory::WalkTheHeap(0);

	// memPool.Status();

	GetInput
	
	delete _g;
	delete _g3;
	
	std::cin.get();

	delete _v;
	delete _v2;
	delete _v3;

	// memPool.Status();

	GetInput

	return 0;
}


