 
#include "Heap.h"
#include <iostream>

Heap::Heap() : m_name(""), m_allocatedBytes(0), _previousAddress(nullptr)
{}

Heap::Heap(std::string name) : m_name(name), m_allocatedBytes(0), _previousAddress(nullptr)
{}

void Heap::Initialise(std::string n)
{
	m_name = (char*)n.c_str();
	m_allocatedBytes = 0;
	_previousAddress = nullptr;
}

void Heap::AddAllocation(size_t size)
{
	m_allocatedBytes += size;

	std::cout << GetName() << ": " << m_allocatedBytes << " bytes allocated!" << std::endl;
}

void Heap::RemoveAllocation(size_t size)
{
	std::cout << GetName() << ": " << m_allocatedBytes << " bytes before deletion!" << std::endl;

	m_allocatedBytes -= size;

	std::cout << GetName() << ": " << m_allocatedBytes << " bytes left after deletion!\n" << std::endl;
}
