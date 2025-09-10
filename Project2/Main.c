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
	//stack
	initStack(&stack, 3, container);
	push(stack, 1);
	printf("%d", pop(stack));
	printf("Remaining: %d bytes\n", container->maxSize - container->currentLocation);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
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