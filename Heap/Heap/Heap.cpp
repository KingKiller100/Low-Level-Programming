#include "stdafx.h"
#include "Heap.h"
#include <iostream>

Heap::Heap() : m_name((char*)""), m_allocatedBytes(0) {}

Heap::Heap(const char *name) : m_name((char*)name), m_allocatedBytes(0) {}

void Heap::AddAllocation(size_t size)
{
	m_allocatedBytes += size;

	std::cout << GetName() << ": " << m_allocatedBytes << " bytes allocated!" << std::endl;
}

void Heap::RemoveAllocation(size_t size)
{
	std::cout << GetName() << ": " << m_allocatedBytes << " bytes before deletion!" << std::endl;

	m_allocatedBytes -= size;

	std::cout << GetName() << ": " << m_allocatedBytes << " bytes left after deletion!" << std::endl;
}
