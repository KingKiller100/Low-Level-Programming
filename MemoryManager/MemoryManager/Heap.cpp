#include "Heap.h"
#include <iostream>
#include <cassert>

Heap::Heap() : m_name((char*)""), m_allocatedBytes(0), _previousAddress(nullptr)
{}

Heap::Heap(char* name) : m_name((char*)name), m_allocatedBytes(0), _previousAddress(nullptr)
{}

void Heap::Initialise(const char* n)
{
	m_name = (char*)n;
	m_allocatedBytes = 0;
	_previousAddress = nullptr;
}

void Heap::AddAllocation(size_t size)
{
	std::cout << m_name << ": " << size << " bytes added!" << std::endl;

	m_allocatedBytes += size;

	std::cout << m_name << ": " << m_allocatedBytes << " bytes allocated!" << std::endl;
}

void Heap::RemoveAllocation(size_t size)
{
	std::cout << m_name << ": " << m_allocatedBytes << " bytes before deletion!" << std::endl;

	m_allocatedBytes -= size;
	std::cout << m_name << ": " << size << " bytes deleted!" << std::endl;

	std::cout << m_name << ": " << m_allocatedBytes << " bytes left after deletion!\n" << std::endl;
}

void Heap::WalkHeap()
{
	int a = 0;
	AllocHeader* copyHeap;
	size_t totalBytes = 0;

	
	if (_previousAddress)
	{
		copyHeap = ((AllocHeader*)_previousAddress);

		if (copyHeap->_prev != (AllocHeader*)0xdddddddd)
		{
			while (copyHeap->_prev)
			{
				copyHeap = copyHeap->_prev;
			}

			while (true)
			{
				size_t requestedBytes = copyHeap->iSize + sizeof(AllocHeader) + sizeof(int);

				assert(copyHeap->iSignature == MEMSYSTEM_SIGNATURE);

				char *pMem = (char*)malloc(requestedBytes);
				//auto *pEndMem = (int*)(((char*)pMem + copyHeap->iSize) + sizeof(AllocHeader));

				auto *pEndMem = (int*)(int*)((char*)copyHeap + copyHeap->iSize + sizeof(AllocHeader));

				assert(*pEndMem == MEMSYSTEM_ENDMARKER);


				std::cout << copyHeap->pHeap->GetName() << " total bytes: " << requestedBytes << "\n" << std::endl;

				copyHeap = copyHeap->_next;

				if (!copyHeap->_next)
					break;
			}

			totalBytes += m_allocatedBytes;
		}
		else
			return;
	}
	std::cout << m_name << " total bytes: " << totalBytes << "\n" << std::endl;
}
