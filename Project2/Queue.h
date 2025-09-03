#pragma once
#include "Pool.h"

typedef struct QueueNode
{
	unsigned int value;
} QueueNode;

typedef struct Queue
{
	QueueNode* queue;
	unsigned int maxSize;
	QueueNode* lastNode;
	QueueNode* firstNode;
	unsigned int currentNode;
} Queue;


void initQueue(Queue** queue, const unsigned int amountOfNodes, PoolContainer* container);

void cleanQueue(Queue** queue);

bool enqueue(Queue* queue, const unsigned int value);

unsigned int dequeue(Queue* queue);

bool isEmpty(Queue* queue);

bool isFull(Queue* queue);

unsigned int peekFront(Queue* queue);

unsigned int peekLast(Queue* queue);