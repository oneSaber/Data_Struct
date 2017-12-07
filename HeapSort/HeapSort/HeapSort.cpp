#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Maxlen 10
#define LeftChild(i) (2*i+1)
void RandText(int Arr[])
{
	srand(time(0));
	for (int i = 0; i < Maxlen; i++)
		Arr[i] = rand() % Maxlen;
}
void Adjust(int Arr[], int i,int N)
{
	int temp;
	int child;
	for (temp = Arr[i]; LeftChild(i) < N; i = child)
	{
		child = LeftChild(i);
		if (child != N - 1 && Arr[child + 1] > Arr[child])
			child++;
		if (Arr[child] > temp)
			Arr[i] = Arr[child];
		else break;
	}
	Arr[i] = temp;
}
void HeapSort(int Arr[])
{
	for (int i = Maxlen / 2; i >= 0; i--)
		Adjust(Arr, i, Maxlen);
	for (int i = Maxlen - 1; i > 0; i--)
	{
		int temp = Arr[i];
		Arr[i] = Arr[0];
		Arr[0] = temp;
		Adjust(Arr, 0, i);
	}
}
int main()
{
	int Arr[Maxlen];
	RandText(Arr);//通过随机数生成测试值
	printf_s("before sort:");
	for (int i = 0; i < Maxlen; i++)
		printf_s("%d ", Arr[i]);
	HeapSort(Arr);//排序
	printf_s("\nafter sort:");
	for (int i = 0; i < Maxlen; i++)
		printf_s("%d ", Arr[i]);
	system("pause");
	return 0;
}