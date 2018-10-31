#pragma once
#include <string>

class Heap
{
private:
	std::string m_name;
public:
	size_t m_allocatedBytes;

public:
	Heap();
	Heap(const std::string nname);

	void Initialise(const std::string n);

	void SetName(const char *n)					{ m_name = (char*)n; }
	std::string GetName() const					{ return m_name; };
	
	void AddAllocation(size_t size);
	void RemoveAllocation(size_t size);
	size_t TotalAllocation() const				{ return m_allocatedBytes; }
};

