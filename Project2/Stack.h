#pragma once
#include "Pool.h"

typedef struct StackNode
{
	unsigned int value;
} StackNode;

typedef struct Stack
{
	StackNode* stack;
	unsigned int maxSize;
	unsigned int readIndex;
	unsigned int frontIndex;
	unsigned int currentSize;
} Stack;


void initStack(Stack** stack, const unsigned int amountOfNodes, PoolContainer* container);

void cleanStack(Stack** stack);

bool push(Stack* stack, const unsigned int value);

unsigned int pop(Stack* stack);

bool isStackEmpty(Stack* stack);

bool isStackFull(Stack* stack);

unsigned int peek(Stack* stack);