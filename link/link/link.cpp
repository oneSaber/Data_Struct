#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode *next;
}NODE,*Position,*List;
int IsLast(Position p)
{
	return p->next == NULL;
}
//链表是否为空
int IsEmpty(List L)
{
	return L->next == NULL;
}
List MakeList(List L)
{
	while (L == NULL)
		L = (Position)malloc(sizeof(NODE));
	Position p1, p2;
	p1 = (Position)malloc(sizeof(NODE));
	if (p1 == NULL)
		printf_s("内存分配失败");
	else {
		L->next = p1;
		printf_s("input next(q for finish):");
		while (scanf_s("%d", &p1->data) == 1)
		{
			p2 = (Position)malloc(sizeof(NODE));
			p1->next = p2;
			p1 = p2;
		}
		p1->next = NULL;
		getchar();
		return L;
	}
}
void ShowList(List L)
{
	if (!IsEmpty(L))
	{
		Position P = L->next;
		while (!IsLast(P))
		{
			printf_s("%d ", P->data);
			P = P->next;
		}
	}
	else printf_s("Empty List ,Nothing Can Show");
}
//初始化链表
List InitList(List L)
{
	L = (Position)malloc(sizeof(NODE));
	if (L != NULL)
		L->next = NULL;
	else
		printf_s("内存分配失败");
	return L;
}
//是否是链表尾部


Position FindByValue(List L, int data)
{
	Position p = L->next;
	if (p == NULL)
		return NULL;
	while (p->data != data)
	{
		if(!IsLast(p))
			p = p->next;
		else return NULL;
	}
	return p;
}
Position FindByOrder(List L, int order)
{
	Position p = L->next;
	int i = 1;
	while (!IsLast(p))
	{
		if (i == order)
			return p;
		p = p->next;
		i++;
	}
	return NULL;
}
//插在data后面
void Insert(List L, int data, int num)
{
	Position InsertPoint = FindByValue(L, num);
	if (Insert != NULL)
	{
		Position temp = (Position)malloc(sizeof(NODE));
		temp->data = data;
		temp->next = InsertPoint->next;
		InsertPoint->next = temp;
	}
	else printf_s("can't find insert position \n");
}
//删除data节点
void DeleteNode(List L, int data)
{
	Position p = L->next;
	while (p->next->data != data && !IsLast(p->next))
		p = p->next;
	Position temp = p->next;
	p->next = temp->next;
	free(temp);
}
//删除整个链表，是链表为空
void DeleteList(List L)
{
	Position p, temp;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}

//p是q的前驱，交换q和它的后继
void SwitchNode(Position p, Position q)
{
	if (!IsLast(p))
	{
		int temp = p->data;
		p->data = q->data;
		q->data = temp;
	}
}
List Sort(List L)
{
	Position p = L->next;
	while (!IsLast(p))
	{
		Position q = p->next;
		while (!IsLast(q))
		{
			if (q->data < p->data)
				SwitchNode(p, q);
			q = q->next;
		}
		p = p->next;
	}
	return L;
}

void UnionList(List lc,List la, List lb)
{
	Position pa = la->next;
	Position pb = lb->next;
	Position pc = lc;
	while (!IsLast(pa))
	{
		if (!FindByValue(lc, pa->data))
		{
			pc->next = (Position)malloc(sizeof(NODE));
			pc->next->data = pa->data;
			pc = pc->next;
			pc->next = NULL;
		}
		pa = pa->next;
	}

	while(!IsLast(pb))
	{
		if (!FindByValue(lc, pb->data))
		{
			pc->next = (Position)malloc(sizeof(NODE));
			pc->next->data = pb->data;
			pc = pc->next;
			pc->next = NULL;	
		}
		pb = pb->next;
	}
	pc->next = (Position)malloc(sizeof(NODE));
	pc->next->data = pb->data;
	pc = pc->next;
	pc->next = NULL;
}
int main()
{
	List la, lb;
	char ch;
	la = NULL;
	lb = NULL;
	printf_s("make A list:");
	la = MakeList(la);
	while ((ch = getchar()) != 'Q')
	{
		printf_s("链表元素：");
		ShowList(la);
		printf_s("\n1.按值查找\n");
		printf_s("2.按序查找\n");
		printf_s("3.删除元素\n");
		printf_s("4.在元素之后插入:\n");
		printf_s("5.求la,lb的并集\n");
		int choose;
		scanf_s("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1: {
			int searchVal;
			scanf_s("%d", &searchVal);
			getchar();
			Position p = FindByValue(la, searchVal);
			if (p != NULL)
				printf_s("%d", p->data);
			else printf_s("can't find");
		}break;
		case 2: {
			int searchOrder;
			scanf_s("%d", &searchOrder);
			getchar();
			Position p = FindByOrder(la, searchOrder);
			if (p != NULL)
				printf_s("%d", p->data);
			else printf_s("can't find");
		}break;
		case 3: {
			int deleteVal;
			scanf_s("%d", &deleteVal);
			getchar();
			DeleteNode(la, deleteVal);
		}break;
		case 4: {
			int insertPos, insertVal;
			printf_s("输入在哪个元素后插入，插入的值：");
			scanf_s("%d %d", &insertPos, &insertVal);
			getchar();
			Insert(la, insertVal, insertPos);
		}break;
		case 5 :{
			List lb, lc;
			lb = NULL;
			lc = NULL;
			lb = MakeList(lb);
			lc = InitList(lc);
			UnionList(lc, la, lb);
			ShowList(lc);
		}break;
		default:
			getchar();
			break;
		}
		puts("\nQ for quit");
	}
	system("pause");
	return 0;
}