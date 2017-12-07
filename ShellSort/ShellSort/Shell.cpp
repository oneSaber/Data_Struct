#include<stdio.h>
#include<stdlib.h>
#define Length 1000
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Shell(int a[], int length)
{
	int i, j, grp;
	for (grp = length / 2; grp > 0; grp = grp / 2)
	{//将数组分组
		for (i = 0; i < grp; i++)
		{//对每一个分组排序
			for (j = i + grp; j < length; j += grp)
			{
				if (a[j] < a[j - grp])
				{
					int temp = a[j];
					int k = j - grp;
					while (k >= 0 && a[k] > temp)
					{
						a[k + grp] = a[k];
						k -= grp;
					}
					a[k+grp] = temp;
				}
			}
		}
	}

}

void RandData(int a[], int length)
{
	srand(time_t(0));
	for (int i = 0; i < length; i++)
		a[i] = rand() % 10000;
}
int main()
{
	int a[Length];
	RandData(a, Length);
	Shell(a, Length);
	for (int i = 0; i < Length; i++)
		printf_s("%d ", a[i]);
	system("pause");
	return 0;
}