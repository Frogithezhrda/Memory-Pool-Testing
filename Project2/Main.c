#include "Queue.h"
#include "Stack.h"

int main(void)
{
	PoolContainer* container = NULL;
	initPool(1, &container);

	
	Queue* queue = NULL;
	Stack* stack = NULL;
	//queue
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	initQueue(&queue, 3, container);
	enqueue(queue, 10);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	enqueue(queue, 20);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	enqueue(queue, 30);
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	//printPool(container);
	printf("%d", dequeue(queue));
	printf("%d", dequeue(queue));
	printf("%d", dequeue(queue));
	//stack
	initStack(&stack, 3, container);
	push(stack, 10);
	printf("%d", pop(stack));
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	printf("%d", pop(stack));
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	printf("%d", pop(stack));
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	printf("%d", pop(stack));
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);


	printPool(container);
	cleanQueue(&queue);
	cleanPool(&container);

	return 0;
}