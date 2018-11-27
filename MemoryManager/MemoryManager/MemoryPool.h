#pragma once

class MemoryPool
{
public:
	MemoryPool();
	void Initialize();
	~MemoryPool();

	void *Alloc(size_t iSize);
	void FreeMemory(void *p, size_t i_size);

private:
	char memBlock[8192];
	char* _currentAddress;
};

