#include "stdafx.h"
#include "Vector3D.h"
#include "Structures.h"
#include <iostream>

Heap *Vector3D::v_Heap = nullptr;

Vector3D::Vector3D()
{
	x = y = z = 0.0;

	std::cout << "V3D Constructor Called" << std::endl;
}

Vector3D::Vector3D(const double & x, const double & y, const double & z) : x(x), y(y), z(z) 
{
	std::cout << "V3D Constructor Called" << std::endl;
}


Vector3D::~Vector3D()
{
	std::cout << "V3D Destroyed" << std::endl;
}

void * Vector3D::operator new(size_t size)
{
	if (!v_Heap)
		v_Heap = HeapFactory::CreateHeap("V3D");

	return MemoryManagement::operator new(sizeof(Vector3D));
}

void Vector3D::operator delete(void * pMem, size_t size)
{
	MemoryManagement::operator delete(pMem);
}
