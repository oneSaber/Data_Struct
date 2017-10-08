#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Coeff;//系数
	int Degree;//次数
	struct Node	*next;
};

typedef struct Node *Position;
typedef struct Node *List;

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
			printf("%d %d\n", P->Coeff,P->Degree);
			P = P->next;
		}
	}
	else printf("Empty List ,Nothing Can Show");
}
//p是q的前驱，交换q和它的后继
void SwitchNode(Position p, Position q)
{
	if(!IsLast(p))
	{
		int tempCoeef  = p->Coeff;
		p->Coeff = q->Coeff;
		q->Coeff = tempCoeef;
		int tempDegree = p->Degree;
		p->Degree = q->Degree;
		q->Degree = tempDegree;
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
			if (q->Degree < p->Degree)
				SwitchNode(p, q);
			q = q->next;
		}
		p = p->next;
	}
	return L;
}
List Add(List la,List lb)
{
	Position pa = la->next;
	Position pb = lb->next;
	List lc = (List)malloc(sizeof(struct Node));
	lc->next = NULL;
	Position pc = (Position)malloc(sizeof(struct Node));
	pc->next = NULL;
	pc = lc->next;
	while(!IsLast(pa)&&!IsLast(pb))
	{
		printf("pa:%d %d\n", pa->Coeff,pa->Degree);
		printf("pb:%d %d\n", pb->Coeff,pb->Degree);
		pa = pa->next;
		pb = pb->next;	
	}
	return lc;
}
int main()
{
	List la = (List)malloc(sizeof(struct Node));
	List lb = (List)malloc(sizeof(struct Node));
	la = MakeList(la);
	lb = MakeList(lb);
	ShowList(la);
	ShowList(lb);
	Add(la,lb);
	return 0;
}