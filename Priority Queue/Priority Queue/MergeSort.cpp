#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Maxlen 10

void TextData(int Arr[])
{
	
	for (int i = 0; i < Maxlen; i++)
		Arr[i] = rand() % Maxlen;
}

void Merge(int A[], int Tmp[], int Lpos, int Rpos, int RightEnd)
{
	int i, leftEnd, NumElem, TmpPos;
	leftEnd = Rpos - 1;
	NumElem = RightEnd - Lpos + 1;
	TmpPos = Lpos;

	while (Lpos <= leftEnd && Rpos <= RightEnd)
	{
		if (A[Lpos] <= A[Rpos])
			Tmp[TmpPos++] = A[Lpos++];
		else 
			Tmp[TmpPos++] = A[Rpos++];
	}
	while (Lpos<=leftEnd)
	{
		Tmp[TmpPos++] = A[Lpos++];
	}
	while (Rpos<=RightEnd)
	{
		Tmp[TmpPos++] = A[Rpos++];
	}
	for (i = 0; i < NumElem; i++, RightEnd--)
		A[RightEnd] = Tmp[RightEnd];
}
void Msort(int A[], int Tmp[], int left, int right)
{
	int Center;
	if (left < right)
	{
		Center = (left + right) / 2;
		Msort(A, Tmp, left, Center);
		Msort(A, Tmp, Center + 1, right);
		Merge(A, Tmp, left, Center + 1, right);
	}
}
void Mergsort(int A[])
{
	int *Tmp;
	Tmp = (int *)malloc(sizeof(int)*Maxlen);
	if (Tmp != NULL)
	{
		Msort(A, Tmp, 0, Maxlen-1);
		free(Tmp);
	}
	else
	{
		printf_s("No space for temp array");
	}
}
int main()
{
	int Arr[Maxlen];
	TextData(Arr);
	printf_s("before sort:");
	for (int i = 0; i < Maxlen; i++)
		printf_s("%d ", Arr[i]);
	Mergsort(Arr);
	printf_s("\n after sort:");
	for (int i = 0; i < Maxlen; i++)
		printf_s("%d ", Arr[i]);
	system("pause");
	return 0;
}