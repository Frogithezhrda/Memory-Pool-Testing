#include "Queue.h"

void initQueue(Queue** queue, const unsigned int amountOfNodes, PoolContainer* container)
{
	*queue = (Queue*)allocatePool(container, (sizeof(Queue)));
	(*queue)->queue = (QueueNode*)allocatePool(container, sizeof(QueueNode) * amountOfNodes);
	(*queue)->firstNode = (*queue).queue[0];
	(*queue)->lastNode = NULL;
	(*queue)->maxSize = amountOfNodes;
	(*queue)->currentNode = 0;
}

void cleanQueue(Queue** queue)
{
}

bool enqueue(Queue* queue, const unsigned int value)
{
	QueueNode newNode;
	newNode.value = value;
	if (!isFull(queue))
	{
		queue->queue[queue->currentNode] = newNode;
		queue->currentNode++;
		return true;
	}
	return false;
}

unsigned int dequeue(Queue* queue)
{
	int value = 0;
	QueueNode* node = NULL;
	if (!isEmpty(queue))
	{
		queue->currentNode--;
		value = queue->firstNode->value;
		if (queue->currentNode == 0)
		{
			queue->queue->value = 0;
		}
		for (int i = 1; i < queue->currentNode + 1; i++)
		{
			QueueNode* tempNode = &queue->queue[i]; // 1 2 3 4 5 6 // 2
			queue->queue[i - 1] = queue->queue[i];
		}
		return value;
	}
	return value;
}

bool isEmpty(Queue* queue)
{
	return queue->currentNode <= 0;
}

bool isFull(Queue* queue)
{
	return queue->currentNode >= queue->maxSize;
}

unsigned int peekFront(Queue* queue)
{
	return queue->firstNode->value;
}

unsigned int peekLast(Queue* queue)
{
	return queue->lastNode->value;
}
