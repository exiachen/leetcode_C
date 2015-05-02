/*
* For leetcode test.
* Author: chenchen
* Date: 2015.3.22
*/

#include <stdio.h>
#include <stdlib.h>

/* 1024 * 1024 / 32 */
#define HASH_TABLE_SIZE (1024 * 1024)
#define BIT_MAP_SIZE (HASH_TABLE_SIZE / 32)
#define SQUENCE_LEN 10
static int gBitMap[BIT_MAP_SIZE] = {0};

typedef struct _DNA_SQUENCE_NODE
{
	struct _DNA_SQUENCE_NODE *next;
	char squences[SQUENCE_LEN + 1];
} DNA_SQUENCE_NODE;

static DNA_SQUENCE_NODE root = {0};
static int nodeNum = 0;

static void setBit(int *bitMap, int pos)
{
	int quotient = 0;
	int remainder = 0;

	if (!bitMap || pos >= HASH_TABLE_SIZE || pos < 0)
		return;
	
	quotient = pos / 32;
	remainder = pos % 32;

	bitMap[quotient] |= (0x1 << (32 - remainder - 1)); 

	return;
}

static int getBit(int *bitMap, int pos)
{
	int quotient = 0, remainder = 0, tmpValue = 0;
	if (!bitMap || pos >= HASH_TABLE_SIZE || pos < 0)
		return -1;

	quotient = pos / 32;
	remainder = pos % 32;
	tmpValue = bitMap[quotient];

	return (tmpValue >> (32 - remainder - 1)) & 0x01;
}

static void clearBit(int *bitMap, int pos, int mapSize)
{
	return;
}


static unsigned int BKDRHash(char *str, int length)
{
	unsigned int seed = 131;
	unsigned int hash = 0;

	if (!str)
		return 0;

	while (length)
	{
		hash = hash * seed + (*str++);
		length--;
	}

	return hash % HASH_TABLE_SIZE;
}

static DNA_SQUENCE_NODE *newSquenceNode(char *squences)
{
	DNA_SQUENCE_NODE *ptr = NULL;

	if (!squences)
		return NULL;

	ptr = (DNA_SQUENCE_NODE *)malloc(sizeof(DNA_SQUENCE_NODE));
	if (!ptr)
	{
		printf("malloc squence node failed\n");
		return NULL;
	}
	nodeNum++;
	memset(ptr, 0, sizeof(DNA_SQUENCE_NODE));

	memcpy(ptr->squences, squences, SQUENCE_LEN);

	return ptr;
}

static void addToRepeatedList(char *squence)
{
	DNA_SQUENCE_NODE *newNode = NULL;
	DNA_SQUENCE_NODE *ptr = &root;

	while (ptr->next)
	{
		if (!strcmp(squence, ptr->next->squences))
		{
			return;
		}
		ptr = ptr->next;
	}

	newNode = newSquenceNode(squence);
	if (!newNode)
	{
		printf("add to list failed\n");
		return;
	}

	ptr->next = newNode;

	return;
}

static void releaseRepeatedList(void)
{
	DNA_SQUENCE_NODE *ptr = &root;
	DNA_SQUENCE_NODE *tmp = NULL;

	tmp = ptr->next;
	while (tmp)
	{
		ptr = tmp->next;
		free(tmp);
		tmp = ptr;
	}

	root.next = NULL;
	return;
}

static void outputList(char **result)
{
	DNA_SQUENCE_NODE *ptr = root.next;
	int i = 0;

	if (!result)
		return;

	while (ptr)
	{
		if (i >= nodeNum)
		{
			printf("out of range!\n");
		}
		result[i++] = ptr->squences;
		ptr = ptr->next;
	}

	return;
}

char **findRepeatedDnaSequences(char *input, int *outputSize)
{
	char *ptr = input;
	int bitTable = 0;
	unsigned int hash = 0;
	char **result = NULL;
	int count = 0;
	int i = 0;
	int inputLen = 0;

	if (!input || !outputSize || ((inputLen = strlen(input)) <= 10))
	{
		*outputSize = 0;
		return NULL;
	}

	while (*ptr && ((ptr - input) <= (inputLen - 10)))
	{
		hash = BKDRHash(ptr, 10);
		if (getBit(gBitMap, hash))
		{
			addToRepeatedList(ptr);
		}
		else
		{
			setBit(gBitMap, hash);
		}

		ptr++;
	}

	result = (char **)malloc(nodeNum * sizeof(char *));
	if (!result)
	{
		printf("malloc result failed\n");
		return NULL;
	}
	memset(result, 0, sizeof(char *) * nodeNum);

	outputList(result);
	*outputSize = nodeNum;

	return result;
}

int main(int argc, char const *argv[])
{
	char *input = "AAAAAAAAAAAA";
	int outputSize = 0;
	char **output = NULL;
	int i = 0;
	
	output = findRepeatedDnaSequences(input, &outputSize);
	if (!output)
	{
		printf("find failed\n");
	}
	else
	{
		printf("repeated squences:\n");
		for (i = 0; i < outputSize; i++)
		{
			printf("%s  ", output[i]);
		}
		printf("\n");
	}

	if (output)
	{
		free(output);
	}
	releaseRepeatedList();

	return 0;
}