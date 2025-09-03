#include "Pool.h"

void initPool(const unsigned int blockCount, PoolContainer** poolContainer)
{
	*poolContainer = (PoolContainer*)malloc(sizeof(PoolContainer));
	(*poolContainer)->pool = (Pool)calloc(blockCount, POOL_SIZE); 
	(*poolContainer)->currentLocation = 0;
	(*poolContainer)->maxSize = POOL_SIZE * blockCount;
}

void cleanPool(PoolContainer** poolContainer)
{
	free((*poolContainer)->pool);
	free(*poolContainer);
	*poolContainer = NULL;
}

void clearPool(PoolContainer* poolContainer)
{
	poolContainer->currentLocation = 0;
}

PoolPtr allocatePool(PoolContainer* poolContainer, const unsigned int size)
{
	void* pointerVar = NULL;
	if (poolContainer->currentLocation + size <= poolContainer->maxSize)
	{
		pointerVar = poolContainer->pool + poolContainer->currentLocation;
		poolContainer->currentLocation += size;
	}
	return pointerVar;
}

void printPool(PoolContainer* poolContainer)
{
	for (int i = 0; i < poolContainer->currentLocation; i++)
	{
		printf("%X ", poolContainer->pool[i]);
	}
}
