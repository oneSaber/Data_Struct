#include<stdio.h>
#include<stdlib.h>
#include"MAP.h"


bool Visited[MAXLEN];
void DeepTrave(Node G[],int start)
{
	int i;
	for (i = 1; i <= G[0]->num; i++)
		if (G[i]->num == start) 
			break;
	Node p = G[i];
	if (Visited[G[i]->num] == false)
	{
		Visited[G[i]->num] = true;
		printf_s("%d-> ", G[i]->num);
		while (p->next != NULL)
		{
			p = p->next;
			DeepTrave(G, p->num);
		}
	}
}
bool AllTrave(int n)
{
	bool finish = true;
	for (int i = 1; i <= n; i++)
		finish = finish && Visited[i];
	return finish;
}
int NotraveNode(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (Visited[i] == false)
			return i;
	}
}

//广度优先搜索
bool Visited2[MAXLEN];
void NFS(Node G[], int start)
{
	Queue Q = NULL;
	InitQueue(Q);
	Push(Q, start);
	while (Q->length>0)
	{
		int q = Pop(Q);
		int i;
		for (i = 1; i <= G[0]->num; i++)
			if (i == q)
				break;
		if (Visited2[q] == false)
		{
			printf_s("%d->", q);
			Visited2[q] = true;
		}
		Node p = G[i]->next;
		while (p != NULL)
		{
			Push(Q, p->num);
			p = p->next;
		}
	}
}
int main()
{
	Node G[MAXLEN];
	CreatGraph(G, false);
	ShowGraph(G);
	for (int i = 1; i < G[0]->num; i++)
		Visited[G[i]->num] = false;
	for (int i = 1; i < G[0]->num; i++)
		Visited2[G[i]->num] = false;
	int start;
	/*while (!AllTrave(G[0]->num))
	{
		start = NotraveNode(G[0]->num);
		DeepTrave(G, start);
	}*/
	NFS(G, 1);
	system("pause");
	return 0;
}