#pragma once
#include <cstdio>


#define MEMSYSTEM_SIGNATURE 0xdeadc0de //233495774
#define MEMSYSTEM_ENDMARKER 0xdeadbeef //218815710

class Heap
{
private:
	char* m_name;

public:
	size_t m_allocatedBytes;
	void *_previousAddress;

public:
	Heap();
	Heap(char* name);

	void Initialise(const char* n);

	void SetName(char* n)							{ m_name = n; }
	char* GetName() const							{ return m_name; };
	
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() const					{ return m_allocatedBytes; }

	void WalkHeap();

};

struct AllocHeader
{
	int iSignature;
	Heap *pHeap;
	int iSize;
	AllocHeader *_next;
	AllocHeader *_prev;
};

