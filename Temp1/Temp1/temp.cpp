#include<stdio.h>
#include<stdlib.h>
int Ischild(int L[], int R[], int u, int v)
{
	if (u == 0 || v == 0)
		return 0;
	else
	{
		if (u == v) return 1;
		int Rl = Ischild(L, R, u, L[v]);
		int Rr = Ischild(L, R, u, R[v]);
		return (Rl || Rr);
	}
}
int main()
{
	int L[8] = { 0, 2, 4, 6, 0, 0, 0, 0 };
	int R[8] = { 0, 3, 5, 7, 0, 0, 0, 0 };

	printf_s("%d", Ischild(L, R, 7, 2));
	system("pause");
	return 0;
}