#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#define POOL_SIZE (1024 * 1024) // 1 Mb


typedef uint8_t* Pool;
typedef void* PoolPtr;

typedef struct PoolContainer
{
	Pool pool;
	unsigned int currentLocation;
	unsigned int maxSize;
} PoolContainer;

void initPool(const unsigned int blockCount, PoolContainer** poolContainer);
void cleanPool(PoolContainer** poolContainer);
void clearPool(PoolContainer* poolContainer);
PoolPtr allocatePool(PoolContainer* poolContainer, const unsigned int size);
void printPool(PoolContainer* poolContainer);