#pragma once
#include <cstdio>
#include <string>


class Heap
{
private:
	std::string m_name;

public:
	size_t m_allocatedBytes;
	void *_previousAddress;

public:
	Heap();
	Heap(std::string name);

	void Initialise(std::string n);

	void SetName(std::string n)							{ m_name = (char*)n.c_str();	}
	std::string GetName() const							{ return m_name; };
	
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() const						{ return m_allocatedBytes; }
};

