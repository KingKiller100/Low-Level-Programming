 
#include "Vector3D.h"
#include <iostream>

Heap *Vector3D::Heap = nullptr;

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
