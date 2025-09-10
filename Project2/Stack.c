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
	if(stack->maxSize > stack->currentSize)
	{
		//maxsize = 4, currentAmount = 3
		for (int i = stack->currentSize - 1; i >= 0; i--)
		{
			stack->stack[i + 1] = stack->stack[i];
		}
		newNode.value = value;
		stack->stack[0] = newNode;
		stack->currentSize++;
		return true;
	}
	return false;
}

unsigned int pop(Stack* stack)
{
	int value = 0;
	// 1 2 3 / 3 / 2 
	StackNode* node = NULL;
	if (!isStackEmpty(stack))
	{
		stack->currentSize--;
		value = stack->stack[0].value; // 1 
		if (stack->currentSize == 0)
		{
			stack->stack->value = 0;
		}
		for (int i = 1; i < stack->currentSize + 1; i++) //
		{
			StackNode tempNode = stack->stack[i]; // 1 2 3 4 5 6 // 2
			stack->stack[i - 1] = stack->stack[i];
		}
	}

	return value;
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
