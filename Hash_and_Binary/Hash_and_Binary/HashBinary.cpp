#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_INIT_SIZE 100 //线性表分配空间的初始容量
#define LISTINCREMENT 10   //线性表分配空间的增量

typedef struct {
	int *elem;
	int length;
	int listsize;
}Sqlist;

bool InitList(Sqlist &L)
{
	L.elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	if (L.elem)
	{
		L.length = LIST_INIT_SIZE;
		L.listsize = LIST_INIT_SIZE;
		int i;
		for (i = 0; i < L.length; i++)
			L.elem[i] = INT_MIN;
		return true;
	}
	else return false;
}
int Len(Sqlist L)
{
	return L.length;
}
//将e插到线性表第i的位置上
bool ListInsert(Sqlist &L, int i, int e)
{
	if (i<1 || i>Len(L) + 1)
		return false;
	if (L.length >= L.listsize)
	{
		int *newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (!newbase)
			return false;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *q = &(L.elem[i - 1]);
	for (int *p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return true;
}
int BinarySearch(int Array[], int left, int right,int searchKey)
{
	if (left > right)
		return -1;
	else {
		int middle = (left + right) / 2;
		if (Array[middle] == searchKey)
			return middle;
		else {
			if (Array[middle] < searchKey)
				return BinarySearch(Array, middle + 1, right, searchKey);
			else return BinarySearch(Array, left, middle - 1, searchKey);
		}
	}
}
//找到最大容量下的最大素数
int findPrime(int Maxlen)
{
	int i ;
	for (i = Maxlen - 1; i > 2; i--)
	{
		int flag = 1;
		for (int j = 2; j < sqrt(i) + 1; j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return i;
	}
}
//每一个元素的哈希值
int Hash(int key,int prime)
{
	return key % prime;
}
void HashInsert(Sqlist la,int prime)
{
	int hash;
	int e;
	printf_s("输入lb构建散列(q结束):");
	while (scanf_s("%d", &e))
	{
		hash = Hash(e,prime);
		//该位置已经被占用，重新求hash
		while (la.elem[hash] != INT_MIN)
			hash = Hash(hash+1, prime);
		la.elem[hash] = e;
	}
	getchar();
}
void HashFind(Sqlist la,int searchKey,int prime)
{
	int hash = Hash(searchKey, prime);
	int findtime = 0;
	while (searchKey != la.elem[hash]&&findtime <= la.length)
	{
		findtime++;
		hash = Hash(hash + 1, prime);
	}
	if (findtime >= la.length)
		printf_s("can't find");
	else printf_s("%d的位置是%d\n", searchKey,hash);
}
int main()
{
	printf_s("1.二分查找\n");
	printf_s("2.散列\n");
	printf_s("输入模式：");
	int mode;
	scanf_s("%d", &mode);
	getchar();
	switch (mode)
	{
	case 1: {
		Sqlist la;
		InitList(la);
		int i = 1;
		int e;
		i = 1;
		puts("输入 La（q 表示结束):");
		while (scanf_s("%d", &e))
		{
			ListInsert(la, i, e);
			i++;
		}
		la.length = i-1;
		getchar();
		printf_s("二分查找,输入查找的元素：");
		int searchKey;
		while (scanf_s("%d", &searchKey))
		{//返回的是searchkey的位置
			int pos = BinarySearch(la.elem, 0, la.length - 1, searchKey) + 1;
			if (pos)
				printf_s("%d 的位置是 %d\n",searchKey, pos);
			else printf_s("can't find\n");
			getchar();
			printf_s("继续查找(q 退出)：");
		}

	}break;
	case 2: {
		Sqlist lb;
		InitList(lb);
		int prime = findPrime(LIST_INIT_SIZE);
		HashInsert(lb, prime);
		int hashkey;
		printf_s("输入需要查找的值(q 退出)：");
		while (scanf_s("%d", &hashkey))
		{
			HashFind(lb, hashkey, prime);
			getchar();
			printf_s("输入下一个查找数（q退出）：");
		}
	}break;
	default:
		break;
	}
	system("pause");
	return 0;
}