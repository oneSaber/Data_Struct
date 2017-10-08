#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Coefficient;
	int Degree;
	struct Node *next;
};
typedef struct Node *Position;
typedef struct Node *List;
//判定是否到链表尾部
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
		L = (Position)malloc(sizeof(struct Node));
	Position p1, p2;
	p1 = (Position)malloc(sizeof(struct Node));
	if (p1 == NULL)
		printf("内存分配失败");
	else {
		L->next = p1;
		while (scanf("%d %d", &p1->Coeff,&p1->Degree) == 2)
		{
			p2 = (Position)malloc(sizeof(struct Node));
			p1->next = p2;
			p1 = p2;

		}
		p1->next = NULL;
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
			printf("%d %d", P->Coeff,P->Degree);
			P = P->next;
		}
	}
	else printf("Empty List ,Nothing Can Show");
}
int main()
{
	List L = (List)malloc
	L = MakeList(L);
	ShowList(L);
	return 0;
}