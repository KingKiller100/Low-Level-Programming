#pragma once

class MemoryPool
{
public:
	MemoryPool(size_t iObjectsize);
	~MemoryPool();

	void *Alloc(size_t iSize);
	void Free(void *p, size_t i_size);
};

