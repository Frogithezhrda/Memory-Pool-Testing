#include "Queue.h"


int main(void)
{
	PoolContainer* container = NULL;
	initPool(1, &container);

	
	Queue* queue = NULL;
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	initQueue(&queue, 3, container);
	enqueue(queue, 2);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	enqueue(queue, 5);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	enqueue(queue, 6);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	printPool(container);
	dequeue(queue);
	dequeue(queue);
	printf("%d", dequeue(queue));
	printPool(container);
	cleanQueue(&queue);
	cleanPool(&container);

	return 0;
}