#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxLen 10

//利用随机数生成测试数组
void Randtext(int Array[])
{
	srand(time(0));
	for (int i = 0; i < MaxLen; i++)
		Array[i] = rand() % MaxLen;
}

void quick_sort(int s[], int l, int r)
{
	int i, j, x;
	if (l < r)
	{
		i = l;
		j = r;
		x = s[i];
		while (i < j)
		{
			while (i < j && s[j] > x)
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;  //将关键值放回一次排序结束处 
		printf_s("\n");
		quick_sort(s, l, i - 1);
		quick_sort(s, i + 1, r);
	}
}

int main()
{
	int Array[MaxLen];
	Randtext(Array);
	for (int count = 0; count < MaxLen; count++)
		printf_s("%d ", Array[count]);
	printf_s("\n");
	quick_sort(Array, 0, MaxLen - 1);
	for (int i = 0; i < MaxLen; i++)
		printf("%d ", Array[i]);
	system("pause");
	return 0;
}