#include "Heap.h"
#include <iostream>
#include <cassert>

Heap::Heap() : m_name((char*)""), m_allocatedBytes(0), _prevAddress(nullptr)
{}

Heap::Heap(char* name) : m_name((char*)name), m_allocatedBytes(0), _prevAddress(nullptr)
{}

void Heap::Initialize(const char* n)
{
	m_name = (char*)n;
	m_allocatedBytes = 0;
	_prevAddress = nullptr;
}

void Heap::AddAllocation(const size_t &size)
{
	std::cout << m_name << ": " << size << " bytes added!" << std::endl;

	m_allocatedBytes += size;

	std::cout << m_name << ": " << m_allocatedBytes << " bytes allocated!\n" << std::endl;
}

void Heap::RemoveAllocation(const size_t &size)
{
	std::cout << m_name << ": " << m_allocatedBytes << " bytes before deletion!" << std::endl;
	std::cout << m_name << ": " << size << " bytes deleted!" << std::endl;

	m_allocatedBytes -= size;

	std::cout << m_name << ": " << m_allocatedBytes << " bytes left after deletion!\n" << std::endl;
}

void Heap::WalkHeap()
{
	AllocHeader* copyHeap;
	size_t totalBytes = 0;

	if (_prevAddress) // get last look at address on the heap
	{
		copyHeap = (AllocHeader*)_prevAddress; // casts to AllocHeader to find previous and next
		
		if (copyHeap)
		{
			if (copyHeap->_prev != nullptr)
			{
				while (copyHeap->_prev && copyHeap != copyHeap->_prev)
				{
					copyHeap = copyHeap->_prev;
				}

				size_t requestedBytes = copyHeap->iSize + sizeof(AllocHeader) + sizeof(int);

				if (m_name != (char*)"default")
					std::cout << copyHeap->pHeap->GetName() << " size for each class allocated on the heap (excluding AllocHeader): " << requestedBytes << std::endl;

				while (true)
				{
					assert(copyHeap->iSignature == MEMSYSTEM_SIGNATURE);

					auto *pEndMem = (int*)(int*)((char*)copyHeap + copyHeap->iSize + sizeof(AllocHeader));

					assert(*pEndMem == MEMSYSTEM_ENDMARKER);

					if (!copyHeap->_next || copyHeap == copyHeap->_next)
						break;

					copyHeap = copyHeap->_next;
					totalBytes += m_allocatedBytes;
				}
			}
			else
			{
				size_t requestedBytes = m_allocatedBytes + sizeof(AllocHeader) + sizeof(int);

				if (m_name != (char*)"default")
					std::cout << GetName() << " size for each class allocated on the heap (excluding AllocHeader): " << requestedBytes << std::endl;

				totalBytes += m_allocatedBytes;
			}
		}
	}
	
	std::cout << m_name << " heap's total bytes allocated on this heap: " << totalBytes << "\n" << std::endl;
}
