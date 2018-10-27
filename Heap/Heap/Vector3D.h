#pragma once
#include "Heap.h"

class Vector3D
{
private:
	double x;
	double y;
	double z;
	static Heap *s_Heap;

public:
	Vector3D();
	Vector3D(const double &x, const double &y, const double &z);

	~Vector3D();

	void *operator new(size_t size);
	void operator delete (void *pMem, size_t size);
};

