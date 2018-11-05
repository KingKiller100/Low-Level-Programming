 
//#include "Structures.h"
//#include <cassert>
//
//#define MEMSYSTEM_SIGNATURE 0xdeadc0de
//#define MEMSYSTEM_ENDMARKER 0xdeadbeef
//
//void * operator new(size_t size, Heap * pHeap)
//{
//	size_t iRequestedBytes = size + sizeof(AllocHeader) + sizeof(int);
//	char *pMem = (char*)malloc(iRequestedBytes);
//	AllocHeader *pHeader = (AllocHeader*)pMem;
//	pHeader->iSignature = MEMSYSTEM_SIGNATURE;
//	pHeader->pHeap = pHeap;
//	pHeader->iSize = (int)size;
//
//	auto *pStartMemBlock = pMem + sizeof(AllocHeader);
//	int *pEndMarker = (int*)(pStartMemBlock + size);
//	*pEndMarker = MEMSYSTEM_ENDMARKER;
//
//	pHeap->AddAllocation(size);
//
//	return pStartMemBlock;
//}
//
//void * operator new(size_t size)
//{
//	return operator new(size, HeapFactory::GetDefaultHeap());
//}
//
//void operator delete(void * pMem)
//{
//	AllocHeader *pHeader = (AllocHeader*)((char*)pMem - sizeof(AllocHeader));
//
//	auto heap = pHeader->pHeap;
//	auto size = pHeader->iSize;
//	auto sig = pHeader->iSignature;
//
//	assert(sig == MEMSYSTEM_SIGNATURE);
//
//	int *pEndMarker = (int*)(int*)((char*)pMem + size);
//
//	assert(*pEndMarker == MEMSYSTEM_ENDMARKER);
//
//	heap->RemoveAllocation(size);
//	free(pHeader);
//}