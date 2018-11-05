#pragma once
#include "Heap.h"
#include "MemoryOverride.h"

class Vector3D : public MemoryOverride<Vector3D>
{
private:
	double x;
	double y;
	double z;
public:
	static Heap* Heap;
	Vector3D();
	Vector3D(const double &x, const double &y, const double &z);
	~Vector3D();

	//static void *operator new(size_t size);
	//static void operator delete (void *pMem, size_t size);
};

