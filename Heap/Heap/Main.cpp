#include "stdafx.h"
#include <iostream>
#include <string>
#include "Structures.h"
#include "GameObject.h"
#include "Vector3D.h"

int main()
{
	std::vector<GameObject*> g;

	g.resize(10);

	for (size_t i = 0; i < g.size(); i++)
		g.at(i) = new GameObject(i);

	std::vector<Vector3D*> v;

	v.resize(5);

	for (size_t i = 0; i < v.size(); i++)
		v.at(i) = new Vector3D(rand() % 10, rand() % 10, rand() % 10);

	for (GameObject* object : g)
		delete object;

	std::cin.get();

	for (Vector3D* object : v)
		delete object;

	std::cin.get();

	return 0;
}

