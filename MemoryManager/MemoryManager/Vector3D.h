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
	static Heap* _heap;
	Vector3D();
	Vector3D(const double &x, const double &y, const double &z);
	~Vector3D();
};

