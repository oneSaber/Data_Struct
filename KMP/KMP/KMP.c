#include<stdio.h>
#include<stdlib.h>
//Êä³ö×Ö·û´®
void ShowString(char T[])
{
	for (int i = 1; i <= T[0]; i++)
		putchar(T[i]);
}

//ÊäÈë×Ö·û´®
void GetString(char T[])
{
	gets(T);
	int i = 0;
	while (T[i] != '\0')
		i++;
	//ÕÒµ½×Ö·û´®½áÎ²
	int length = i;
	while (i > 0)
	{
		T[i] = T[i - 1];
		i = i - 1;
	}
	T[0] = length;
	return T;
}
void Next(char T[], int next[])
{
	int i = 1;
	next[i] = 0;
	int j = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j]) {
			++i; ++j;
			next[i] = j;
		}
		else j = next[j];
	}
}
int Index_KMP(char S[], char T[], int pos)
{
	int i = pos,j = 1;
	int next[81];
	Next(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}
	if (j > T[0]) return i - T[0] - 1;
	else return -1;
}
int main()
{
	char S[81];
	char T[81];
	int next[80];
	GetString(S);
	getchar();
	GetString(T);
	int index = Index_KMP(S, T, 1);
	printf_s("%d", index);
	system("pause");
	return 0;
}