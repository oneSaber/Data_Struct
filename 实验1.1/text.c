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
//初始化链表
List InitList(List L)
{
	L = (Position)malloc(sizeof(struct Node));
	if (L != NULL)
		L->next = NULL;
	else
		printf("内存分配失败");
	return L;
}
//是否是链表尾部


Position Find(List L, int Coeff)
{
	Position p = L->next;
	while (p->Coeff != Coeff && !IsLast(p))
		p = p->next;
	return p;
}
//插在data后面
void Insert(List L, int Coeff,int Degree, int num)
{
	Position InsertPoint = Find(L, num);
	Position temp = (Position)malloc(sizeof(struct Node));
	temp->Coeff = Coeff;
	temp->Degree = Degree;
	temp->next = InsertPoint->next;
	InsertPoint->next = temp;
}
//删除data节点
void DeleteNode(List L, int Coeff)
{
	Position p = L->next;
	while (p->next->Coeff != Coeff && !IsLast(p->next))
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
	while (p!=NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
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

int main()
{
	List La = (Position)malloc(sizeof(struct Node));
	La->next = NULL;
	List Lb = (Position)malloc(sizeof(struct Node));
	Lb->next = NULL;
	printf("输入LA\n");
	La = MakeList(La);
	getchar();
	printf("输入Lb\n");
	Lb = MakeList(Lb);
	Sort(La);
	Sort(Lb);
	// ShowList(La);
	// ShowList(Lb);
	List Lc;
	Lc = Add(La,Lb);
	ShowList(Lc);
	return 0;
}