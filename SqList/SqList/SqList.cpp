#include<stdio.h>
#include<stdlib.h>
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
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;
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
//删除表中的第I个元素
bool ListDelete(Sqlist &L, int i, int &e)
{
	if (i<1 || i>L.length)
		return false;//参数不合法
	int* p = &(L.elem[i - 1]);
	e = *p;
	int* q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return true;
}
//e是否在线性表L中，在的话返回表中的位置，不在返回false
int LocateElem(Sqlist L, int e)
{
	int find = false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			find = i+1;
			break;
		}
	}
	return find;
}
//将两个线性表合并
void MergeList(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
	Lc.length= La.length + Lb.length;
	Lc.listsize = LIST_INIT_SIZE;
	Lc.elem = (int *)malloc(sizeof(int)*Lc.listsize);
	int a = 0,b = 0;
	int i = 0;
	int insertNum;
	while (a < La.length&&b < Lb.length)
	{
		if (La.elem[a] > Lb.elem[b])
			insertNum = Lb.elem[b++];
		else insertNum = La.elem[a++];
		if (!LocateElem(Lc, insertNum))
			Lc.elem[i++] = insertNum;
	}
	while (a < La.length)
	{
		insertNum = La.elem[a++];
		if (!LocateElem(Lc, insertNum))
			Lc.elem[i++] = insertNum;
	}
	while (b < Lb.length)
	{
		insertNum = Lb.elem[b++];
		if (!LocateElem(Lc, insertNum))
			Lc.elem[i++] = insertNum;
	}
	Lc.length = i;
}
int main()
{
	Sqlist La;
	InitList(La);
	int i = 1;
	int e;
	puts("输入 La（q 表示结束):");
	while (scanf_s("%d", &e))
	{
		ListInsert(La, i, e);
		i++;
	}
	getchar();
	char ch = 'A';
	while (ch!='Q')
	{
		printf_s("la:");
		for (int i = 0; i < La.length; i++)
			printf_s("%d ", La.elem[i]);
		int choose;
		printf_s("\n1.查找某个值的位置\n");
		printf_s("2.删除某个值\n");
		printf_s("3.在某个位置插入:\n");
		printf_s("4.将La与Lb合并:\n");
		printf_s("输入选择:");
		scanf_s("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1: 
		{
			int searchVal;
			printf_s("输入查找的值：");
			scanf_s("%d", &searchVal);
			getchar();
			int pos = LocateElem(La, searchVal);
			if (pos)
				printf_s("%d 在第 %d 位置\n", searchVal, pos);
			else printf_s("can't find\n");
		}break;
		case 2:
		{
			int deletePos;
			printf_s("输入需要删除第i个元素:");
			scanf_s("%d", &deletePos);
			getchar();
			int e;
			if (ListDelete(La, deletePos,e))
				printf_s("%d 删除成功\n",e);
			else printf_s("删除失败\n");
		}break;
		case 3: 
		{
			int insertPos;
			int insertVal;
			printf_s("输入插入的位置和值:");
			scanf_s("%d %d", &insertPos,&insertVal);
			getchar();
			if (ListInsert(La, insertPos, insertVal))
				printf_s("插入成功\n");
			else printf_s("插入失败\n");
		}break;
		case 4:
		{
			Sqlist Lb, Lc;
			InitList(Lb);
			InitList(Lc);
			i = 1;
			puts("输入 Lb（q 表示结束):");
			while (scanf_s("%d", &e))
			{
				ListInsert(Lb, i, e);
				i++;
			}
			getchar();
			MergeList(La, Lb, Lc);
			printf_s("lc:");
			for (int i = 0; i < Lc.length; i++)
				printf_s("%d ", Lc.elem[i]);
			puts("\n");
			getchar();
		}break;
		default:printf_s("输入错误\n");
			break;
		}
		choose = -1;
		printf_s("Q 退出程序:\n");
		ch = getchar();
	}
	system("pause");
	return 0;
}