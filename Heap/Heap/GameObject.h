#pragma once
#include "Heap.h"

class GameObject
{
private:
	int m_id;
	static  Heap *s_pHeap;

public:
	GameObject(int id);
	~GameObject();

	void *operator new(size_t size);
	void operator delete (void *pMem, size_t size);
};

