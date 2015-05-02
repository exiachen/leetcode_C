#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int *base;
	int *nextMinItem;
	int minItemIndex;
	int stackTop;
	int maxSize;
} MinStack;

static int minValue(MinStack *stack) {
	if (!stack || !stack->base || stack->minItemIndex < 0)
		return INT_MAX;

	return (stack->base[stack->minItemIndex]);
}

void minStackCreate(MinStack *stack, int maxSize) {
	if (!stack || maxSize <= 0)
		return;

	stack->base = (int *)malloc(sizeof(int) * maxSize);
	if (!stack->base) {
		printf("init stack failed\n");
		return;
	}

	stack->nextMinItem = (int *)malloc(sizeof(int) * maxSize);
	if (!stack->nextMinItem) {
		printf("init nextMinItem failed\n");
		free(stack->base);
		return;
	}

	stack->minItemIndex = -1;
	stack->stackTop = -1;
	stack->maxSize = maxSize;
    
    return;
}

void minStackPush(MinStack *stack, int element) {
	if (!stack)
		return;

	stack->stackTop++;
	if (stack->stackTop >= stack->maxSize) {
		printf("stack is full\n");
		stack->stackTop--;
		return;
	}

	stack->base[stack->stackTop] = element;

	if ((-1 == stack->minItemIndex) || element < minValue(stack)) {
		stack->nextMinItem[stack->stackTop] = stack->minItemIndex;
		stack->minItemIndex = stack->stackTop;
	}
	else
		stack->nextMinItem[stack->stackTop] = -1;

	return;
}

void minStackPop(MinStack *stack) {
	if (!stack)
		return;

	if (stack->stackTop < 0) {
		printf("stack is empty\n");
		return;
	}

	if (stack->stackTop == stack->minItemIndex) {
		stack->minItemIndex = stack->nextMinItem[stack->stackTop];
	}

	stack->stackTop--;
	return;
}

int minStackTop(MinStack *stack) {

	return stack->base[stack->stackTop];
}

int minStackGetMin(MinStack *stack) {

    return stack->base[stack->minItemIndex];
}

void minStackDestroy(MinStack *stack) {
	if (!stack)
		return;

	if (stack->base) {
		free(stack->base); 
		stack->base = NULL;
	}

	if (stack->nextMinItem) {
		free(stack->nextMinItem);
		stack->nextMinItem = NULL;
	}

	return;
}

int main(int argc, char *argv[]) {
	MinStack stack;
	int i = 0;

	minStackCreate(&stack, 10);

#if 0
	printf("pushing...\n");
	for (i = 0; i < 11; i++)
	{
		minStackPush(&stack, i + 1);
		printf("min: %d, top: %d\n", minStackGetMin(&stack), minStackTop(&stack));
	}

	printf("\npoping...\n");
	for (i = 0; i < 11; i++)
	{
		printf("min: %d, top: %d\n", minStackGetMin(&stack), minStackTop(&stack));
		minStackPop(&stack);
	}
#endif

	minStackPush(&stack, 2147483647);

	printf("top : %d, min: %d\n", minStackTop(&stack), minStackGetMin(&stack));

	minStackDestroy(&stack);

	return 0;
}







