#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxLen 10000

//利用随机数生成测试数组
void Randtext(FILE *file)
{
	srand(time(0));
	for (int i = 0; i < MaxLen; i++)
		fprintf_s(file, "%d ", rand() % MaxLen);
}

void ReadArray(int Array[], FILE *file)
{
	for (int i = 0; i < MaxLen; i++)
		fscanf_s(file, "%d", &Array[i]);
}
void quick_sort(int s[], int l, int r,int &change_time,int &compare_time)
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
			{
				j--;
				compare_time++;
			}
			if (i < j)
			{
				compare_time++;
				change_time++;
				s[i++] = s[j];
			}
			while (i < j && s[i] < x)
			{
				compare_time++;
				i++;
			}
			if (i < j)
			{
				compare_time++;
				change_time++;
				s[j--] = s[i];
			}
		}
		s[i] = x;  //将关键值放回一次排序结束处
		quick_sort(s, l, i - 1,change_time,compare_time);
		quick_sort(s, i + 1, r,change_time,compare_time);
	}
}

int main()
{
	int Array[MaxLen];
	FILE * in,*out;
	fopen_s(&in, "Random.dat", "w");
	Randtext(in);
	fclose(in);
	fopen_s(&out, "Random.dat", "r");
	ReadArray(Array, out);
	printf_s("\n");
	int change_time = 0;
	int compare_time = 0;
	quick_sort(Array, 0, MaxLen - 1,change_time,compare_time);
	for (int i = 0; i < MaxLen; i++)
		printf("%d ", Array[i]);
	printf_s("%d %d", compare_time, change_time);
	system("pause");
	return 0;
}