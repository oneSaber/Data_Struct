#pragma once
#ifndef _MAP_H
#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 1000 // 表示图的顶点数
struct Vertex {
	int num;//用数字表示顶点
	int weight;
	struct Vertex *next;
};
typedef struct Vertex * Node;

struct qNode {
	int data;
	struct qNode *next;
};
struct queue {
	int length;
	struct qNode *top;
	struct qNode *tail;
};
typedef qNode NODE;
typedef NODE *Position;
typedef struct queue *Queue;
void InsertNode(Node *G, int to, int weight, bool Derction)
{
	Node p = (*G)->next;
	Node q = *G;
	int insertfinsh = 0;
	while (p)
	{
		//终点已经存在
		if (p->num == to)
		{
			if (Derction)
			{
				p->weight = weight;
			}
			insertfinsh = 1;
			break;
		}
		q = p;
		p = p->next;
	}
	if (!insertfinsh)
	{
		p = (Node)malloc(sizeof(struct Vertex));
		p->num = to;
		p->weight = weight;
		p->next = NULL;
		q->next = p;
	}
}
void InsertVoidNode(Node *G, int from, int to, int weight,bool Derction,bool isfrom)
{
	(*G) = (Node)malloc(sizeof(struct Vertex));
	(*G)->num = from;
	if (isfrom || !Derction)
	{
		Node p = (Node)malloc(sizeof(struct Vertex));
		p->num = to;
		p->weight = weight;
		p->next = NULL;
		(*G)->next = p;
	}
	else (*G)->next = NULL;
}
//返回图的顶点数,生成的图由Derction决定是否有向
int CreatGraph(Node G[], bool Derction)
{
	int i = 0;
	int from, to, weight;
	G[i] = (Node)malloc(sizeof(struct Vertex));
	G[i]->num = -1;
	G[i]->weight = 0;
	G[i]->next = NULL;
	while (scanf_s("%d %d %d", &from, &to, &weight) == 3)
	{
		int findfrom = 0;
		int findto = 0;
		for (int j = 0; j <= i; j++)
		{
			//在现在的图中找到起点
			if (G[j]->num == from)
			{
				findfrom = 1;
				InsertNode(&G[j], to, weight, Derction);
			}
			if (G[j]->num == to)
			{
				findto = 1;
				//有向图不需要从入到出的
				if(!Derction)
					InsertNode(&G[j], from, weight*-1, (!Derction));
			}
		}
		if (!findfrom)
		{
			//当前图中没有from节点，插入from
			InsertVoidNode(&G[++i], from, to, weight,Derction,true);
		}
		if (!findto)
		{
			InsertVoidNode(&G[++i], to, from, weight*-1,Derction,false);
		}
	}
	//G[0]保存顶点数
	G[0]->num = i;
	return i;
}
void ShowGraph(Node G[])
{
	for (int i = 1; i <= G[0]->num; i++)
	{
		printf_s("%d :", G[i]->num);
		Node p = G[i]->next;
		while (p)
		{
			printf_s("(%d ->%d: %d),", G[i]->num, p->num, p->weight);
			p = p->next;
		}
		printf_s("null\n");
	}
}

void InitQueue(Queue &Q)
{
	if (Q == NULL)
		Q = (Queue)malloc(sizeof(NODE));
	Q->top = NULL;
	Q->tail = NULL;
	Q->length = 0;
}
int Top(Queue Q)
{
	Position p = Q->top;
	return p->data;
}
int Pop(Queue Q)
{
	if (Q->length == 0)
		return false;
	Position p = Q->top;
	if (Q->length > 1) {
		Q->top = p->next;
		Q->length--;
		return p->data;
	}
	else
	{
		Q->top = p->next;
		Q->tail = NULL;
		Q->length = 0;
		return p->data;
	}
}
void Push(Queue Q, int data)
{
	Position p = (Position)malloc(sizeof(NODE));
	p->data = data;
	p->next = NULL;
	if (Q->length > 0)
	{
		Position q = Q->tail;
		q->next = p;
		p->next = NULL;
		Q->length++;
		Q->tail = p;
	}
	else {
		Q->top = p;
		Q->tail = p;
		Q->length++;
	}
}

#endif // !_MAP_H
