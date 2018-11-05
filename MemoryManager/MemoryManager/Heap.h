#pragma once
#include <cstdio>
#include <string>


class Heap
{
private:
	std::string m_name;
public:
	size_t m_allocatedBytes;

public:
	Heap();
	Heap(std::string name);

	void Initialise(std::string n);

	void SetName(std::string n);
	
	

	std::string GetName() const							{ return m_name; };
	
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() const						{ return m_allocatedBytes; }
};

