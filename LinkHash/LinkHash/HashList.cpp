#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"HashSep.h"
#define MinTableSize 10

int NextPrime(int TableSize)
{
	for (int i = TableSize + 1; i < MinTableSize; i++)
	{
		int flag = 1;
		for (int j = 2; j < sqrt(i) + 1; j++)
		{
			if (i%j==0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return i;
	}
}


HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < MinTableSize)
	{
		printf_s("Table size too small");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		printf_s("Out of space");
		return NULL;
	}
	H->TableSize = NextPrime(TableSize);
	H->TheList = (List*)malloc(sizeof(List) * H->TableSize);
	if (H->TheList == NULL)
	{
		printf_s("Out of space");
		return NULL;
	}
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheList[i] = (Position)malloc(sizeof(struct ListNode));
		if (H->TheList[i] == NULL)
			printf_s("Out of space");
		else H->TheList[i]->next = NULL;
	}
}
