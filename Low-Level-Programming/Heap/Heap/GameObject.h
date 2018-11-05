#pragma once
#include "Heap.h"
#include "MemoryOverride.h"

class GameObject : public MemoryOverride<GameObject>
{
private:
	int m_id;
	static Heap* Heap;
public:
	GameObject();
	GameObject(int id);
	~GameObject();

	/*void* operator new(size_t size);
	void operator delete (void *pMem, size_t size);*/
};
