#include "Stack.h"

void initStack(Stack** stack, const unsigned int amountOfNodes, PoolContainer* container)
{
	*stack = (Stack*)allocatePool(container, (sizeof(Stack)));
	(*stack)->stack = (StackNode*)allocatePool(container, sizeof(StackNode) * amountOfNodes);
	(*stack)->maxSize = amountOfNodes;
	(*stack)->currentSize = 0;
}

void cleanStack(Stack** stack)
{
}

bool push(Stack* stack, const unsigned int value)
{
	// 2, 1, 2 / 3 / 5
	StackNode newNode;
	newNode.value = value;
	if (!isStackFull(stack))
	{
		stack->stack[stack->frontIndex] = newNode;
		stack->currentSize++;
		stack->frontIndex = (stack->frontIndex + 1) % stack->maxSize;
		return true;
	}
	return false;
}

unsigned int pop(Stack* stack)
{
	int value = 0;
	if (!isStackEmpty(stack))
	{
		value = stack->stack[(stack->frontIndex - 1 + stack->maxSize) % stack->maxSize].value;
		stack->currentSize--;
		stack->frontIndex = ((stack->frontIndex - 1 + stack->maxSize) % stack->maxSize) % stack->maxSize;
	}

	return value;
}

bool isStackEmpty(Stack* stack)
{
	return !stack->currentSize;
}

bool isStackFull(Stack* stack)
{
	return stack->currentSize >= stack->maxSize;
}

unsigned int peek(Stack* stack)
{
	return 0;
}
