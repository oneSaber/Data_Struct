#include<stdio.h>
#include<stdlib.h>
#include"MAP.h"
#define Infinity  9999
typedef struct find {
	bool Known;
	int Distance;
	int LastNode;
}Find;

int MAP[MAXLEN][MAXLEN];

void eatline()
{
	char ch = getchar();
	while (ch != '\n')
		ch = getchar();
}
int CreateMap()
{
	int n;
	printf_s("输入节点数:");
	scanf_s("%d", &n);
	eatline();
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			MAP[i][j] = 0;
	int from, to, weight;
	while (scanf_s("%d %d %d", &from, &to, &weight) == 3)
	{
		eatline();
		if (from>0 && from <= n && to>0 && to <= n)
			MAP[from][to] = weight;
		else printf_s("wrong\n");
	}
	return n;
}

void InitFind(Find T[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		T[i].Known = false;
		T[i].Distance = Infinity;
		T[i].LastNode = -1;
	}
}
int UnknownSmallset(Find T[],int n)
{
	int v = -1;
	int min = Infinity + 1;
	for (int i = 1; i <= n; i++)
	{
		if (!T[i].Known&&min>T[i].Distance)
		{
			v = i;
			min = T[i].Distance;
		}
	}
	return v;
}
void Dijkstra(int start, Find T[],int n)
{
	T[start].Distance = 0;
	T[start].LastNode = 0;
	while (true)
	{
		int v = UnknownSmallset(T, n);
		if (v == -1)
			break;
		else {
			T[v].Known = true;
			for (int j = 1; j <= n; j++)
			{
				if (MAP[v][j] != 0 && !T[j].Known)
				{
					if (T[v].Distance + MAP[v][j] < T[j].Distance)
					{
						T[j].Distance = T[v].Distance + MAP[v][j];
						T[j].LastNode = v;
					}
				}
			}
		}
	}
}
int FindPath(int Path[], int start, int end, Find T[])
{
	int p = end;
	int i = 1;
	int temp[MAXLEN];
	while (p != start)
	{
		temp[i++] = p;
		p = T[p].LastNode;
	}
	Path[1] = start;
	for (int j = i - 1; j >= 1; j--)
		Path[i - j + 1] = temp[j];
	return i;
}
//int main()
//{
//	int n;
//	n = CreateMap();
//	Find T[MAXLEN];
//	InitFind(T, n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			printf_s("%d ", MAP[i][j]);
//		printf_s("\n");
//	}
//	eatline();
//	int start;
//	printf_s("输入start:");
//	scanf_s("%d", &start);
//	Dijkstra(start, T, n);
//	int end;
//	printf_s("输入end:");
//	scanf_s("%d", &end);
//	int path[MAXLEN];
//	int len = FindPath(path, start, end,T);
//	for (int i = 1; i <= len; i++)
//		printf_s("%d ", path[i]);
//	system("pause");
//	return 0;
//}