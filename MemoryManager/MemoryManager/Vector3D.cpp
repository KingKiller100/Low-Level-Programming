#include "Vector3D.h"
#include <iostream>

Heap *Vector3D::_heap = nullptr;

Vector3D::Vector3D()
{
	x = y = z = 0.0;

	std::cout << "V3D Constructor Called\n" << std::endl;
}

Vector3D::Vector3D(const double & x, const double & y, const double & z) : x(x), y(y), z(z) 
{
	std::cout << "V3D Constructor Called\n" << std::endl;
}

Vector3D::~Vector3D()
{
	std::cout << "V3D Destroyed\n" << std::endl;
}

void Vector3D::Update()
{
	const unsigned char *it		= new (_heap) unsigned char();
	const unsigned char *it1	= new (_heap) unsigned char();
	const unsigned char *it2	= new (_heap) unsigned char();
	const unsigned char *it3	= new (_heap) unsigned char();

	delete it;
	delete it1;
	delete it2;
	delete it3;
}
