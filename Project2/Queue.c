#include "Queue.h"

void initQueue(Queue** queue, const unsigned int amountOfNodes, PoolContainer* container)
{
	*queue = (Queue*)allocatePool(container, (sizeof(Queue)));
	(*queue)->queue = (QueueNode*)allocatePool(container, sizeof(QueueNode) * amountOfNodes);
	(*queue)->readIndex = 0;
	(*queue)->frontIndex = 0;
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
		queue->queue[queue->readIndex] = newNode;
		queue->currentNode++;
		queue->readIndex = (queue->readIndex + 1) % queue->maxSize;
		return true;
	}
	return false;
}

unsigned int dequeue(Queue* queue)
{
	int value = 0;
	if (!isEmpty(queue))
	{
		value = queue->queue[queue->frontIndex].value;
		queue->currentNode--;
		queue->frontIndex = (queue->frontIndex + 1) % queue->maxSize;
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
	return queue->queue[queue->frontIndex].value;
}

unsigned int peekLast(Queue* queue)
{
	return queue->queue[(queue->readIndex - 1 + queue->maxSize) % queue->maxSize].value;
}
