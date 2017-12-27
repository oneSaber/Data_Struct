#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100
void InputR(int Map[][MAX_LEN], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf_s("%d", &Map[i][j]);
	}
}
void Showr(int Map[][MAX_LEN], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf_s("%d ", Map[i][j]);
		printf_s("\n");
	}
}
void Warhsall(int MapR[][MAX_LEN], int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (MapR[i][k] == 1)
			{
				for (int j = 0; j < n; j++)
					MapR[i][j] = (MapR[i][j] || MapR[k][j]);
			}
		}
	}
}
//int main()
//{
//	int MapR[MAX_LEN][MAX_LEN];
//	int n;
//	scanf_s("%d", &n);
//	InputR(MapR, n);
//	Warhsall(MapR, n);
//	Showr(MapR, n);
//	system("pause");
//	return 0;
//}