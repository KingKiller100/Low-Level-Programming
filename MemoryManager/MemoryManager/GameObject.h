#pragma once
#include "Heap.h"
#include "MemoryOverride.h"

class GameObject : public MemoryOverride<GameObject>
{
private:
	int m_id;

public:
	static Heap* _heap;
	GameObject();
	GameObject(int id);

	~GameObject();

	void Update();
};
