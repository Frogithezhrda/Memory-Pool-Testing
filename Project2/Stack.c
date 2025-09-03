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
	// 2, 1 2
	StackNode newNode;
	if(stack->maxSize > stack->currentSize)
	{
		//maxsize = 4, currentAmount = 3
		for (int i = stack->currentSize; i > 0; i--)
		{
			stack->stack[i + 1] = stack->stack[i];
		}
		newNode.value = value;
		stack->stack[0] = newNode;
		return true;
	}
	return false;
}

unsigned int pop(Stack* stack)
{
	return 0;
}

bool isStackEmpty(Stack* stack)
{
	return !stack->currentSize;
}

bool isStackFull(Stack* stack)
{
	return stack->currentSize;
}

unsigned int peek(Stack* stack)
{
	return 0;
}
