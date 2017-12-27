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
//将文件中的数据读到数组中
void ReadArray(int Array[], FILE *file)
{
	for (int i = 0; i < MaxLen; i++)
		fscanf_s(file, "%d", &Array[i]);
}
//冒泡排序
void Bubble(int Array[])
{
	int compare_time = 0;
	int change_time = 0;
	for (int i = 0; i < MaxLen; i++)
	{
		for (int j = i; j < MaxLen; j++)
		{
			compare_time++;
			if (Array[i] < Array[j])
			{
				change_time++;
				int temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}
	printf_s("这次冒泡排序，需要比较%d次，以及交换%d次", compare_time, change_time);
}
//简单选择排序
void EasySecation(int Array[])
{
	int compare_time = 0;
	int change_time = 0;
	for (int i = 0; i < MaxLen - 1; i++)
	{
		int temp = 0;
		int index = i;
		for (int j = i + 1; j < MaxLen; j++)
		{
			compare_time++;
			if (Array[index] > Array[j])
				index = j;
		}
		temp = Array[index];
		Array[index] = Array[i];
		Array[i] = temp;
		change_time++;
	}
	printf_s("这次冒泡排序，需要比较%d次，以及交换%d次", compare_time, change_time);
}
//直接插入排序
void InsertSort(int Array[])
{
	int compare_time = 0;
	int change_time = 0;
	int i, j, k;
	for (i = 1; i < MaxLen; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			compare_time++;
			if (Array[j] < Array[i])
				break;
		}
		if (j != i - 1)
		{
			int temp = Array[i];
			for (k = i - 1; k > j; k--)
			{
				change_time++;
				Array[k+1] = Array[k];
			}
			Array[k + 1] = temp;
		}
	}
	printf_s("这次冒泡排序，需要比较%d次，以及交换%d次", compare_time, change_time);
}
int main()
{
	FILE *in, *out;
	fopen_s(&in, "randon.dat", "w");
	Randtext(in);
	fclose(in);
	fopen_s(&out, "randon.dat", "r");
	int Array[MaxLen];
	ReadArray(Array, out);
	//Bubble(Array);
	//EasySecation(Array);
	InsertSort(Array);
	system("pause");
	return 0;
}