#pragma once

class Heap
{
private:
	char* m_name;
	size_t m_allocatedBytes;

public:
	Heap();
	Heap(char *name);
	char *GetName() const					{ return m_name; };
	
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() const				{ return m_allocatedBytes; }
};

