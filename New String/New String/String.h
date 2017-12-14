#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10000
typedef struct
{
	char *Elem;
	int Length;
}HString;

//清除一行
void Eatline()
{
	char ch = getchar();
	while (ch != '\n')
		ch = getchar();
}
//初始化串
int StrInit(HString &S)
{
	S.Elem = (char *)malloc(sizeof(char)*MAXLEN);
	S.Length = 0;
	if (S.Elem != NULL)
		return 1;
	else return 0;
}
//输入串，回车结束输入
int GetString(HString &S)
{
	if (S.Elem == NULL)
		StrInit(S);
	int i = 1;
	char ch = getchar();
	while (ch != '\n')
	{
		S.Elem[i] = ch;
		ch = getchar();
		i++;
	}
	S.Length = i - 1;
	return 1;
}
//串的长度
int Len(HString S)
{
	return S.Length;
}
//输出串
int ShowString(HString S)
{
	for (int i = 1; i <= S.Length; i++)
		printf_s("%c", S.Elem[i]);
	printf_s("\n");
	return 1;

}
//将S2的值赋给S1
int StrAssign(HString &s1, HString s2)
{
	for (int i = 0; i < s1.Length; i++)
		s1.Elem[i + 1] = 0;
	s1.Length = s2.Length;
	for (int i = 0; i < s2.Length; i++)
		s1.Elem[i + 1] = s2.Elem[i + 1];
	return 1;
}
//将S2拼接在S1后面
int StrConcat(HString &s1, HString s2)
{
	int start = s1.Length + 1;
	s1.Length += s2.Length;
	for (int i = start; i <= s1.Length; i++)
		s1.Elem[i] = s2.Elem[i - start + 1];
	return 1;
}
//返回从第i个字符开始长度为Len的子串
int SubStr(HString S, HString &t, int i, int len)
{
	if (i > S.Length)
		return 0;
	else {
		if (i + len - 1 < S.Length)
		{
			for (int k = i; k < i + len; k++)
				t.Elem[k - i + 1] = S.Elem[k];
			t.Length = len;
			return 1;
		}
		else {
			for (int k = i; k <= S.Length; k++)
				t.Elem[k - i + 1] = S.Elem[k];
			t.Length = S.Length - i + 1;
			return 2;
		}
	}
}
//比较两个串是否相等
int StrCmp(HString S1, HString S2)
{
	if (S1.Length != S2.Length)
		return 0;
	else {
		int flag = 1;
		for (int i = 1; i <= S1.Length; i++)
		{
			if (S1.Elem[i] != S2.Elem[i])
			{
				flag = 0;
				break;
			}
		}
		return flag;
	}
}
//将串T插入到串S，i之后
int StrInsert(HString &s, int i, HString t)
{
	if (s.Length + t.Length < MAXLEN)
	{
		for (int k = s.Length; k > i; k--)
		{
			s.Elem[k + t.Length] = s.Elem[k];
		}
		for (int k = i + 1; k <= t.Length + i; k++)
		{
			s.Elem[k] = t.Elem[k - i];
		}
		s.Length += t.Length;
		return 1;
	}
	else return 0;
}
//删除串
int StrDelete(HString &S, int i, int len)
{
	if (i + len - 1 < S.Length)
	{
		S.Length -= len;
		for (int k = i; k < S.Length; k++)
			S.Elem[k] = S.Elem[k + len];
		return 1;
	}
	else {
		for (int k = i; k <= S.Length; k++)
			S.Elem[k] = 0;
		S.Length -= (S.Length - i) + 1;
		return 2;
	}
}
//得到串中与t相同的子串的第一个位置，KMP实现
void Next(HString T, int next[])
{
	int i = 1;
	next[i] = 0;
	int j = 0;
	while (i < T.Length)
	{
		if (j == 0 || T.Elem[i] == T.Elem[j]) {
			++i; ++j;
			next[i] = j;
		}
		else j = next[j];
	}
}
int Index_KMP(HString S, HString T, int pos)
{
	int i = pos, j = 1;
	int next[81];
	Next(T, next);
	while (i <= S.Length && j <= T.Length)
	{
		if (j == 0 || S.Elem[i] == T.Elem[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}
	if (j > T.Length) return i - T.Length;
	else return 0;
}

//将S中所有得子串u替换为v
HString Replace(HString &S, HString u, HString v)
{
	HString T, temp;
	StrInit(T);
	StrInit(temp);
	int Start = 1;
	int End = 1;
	int pos = T.Length;
	int index = Index_KMP(S, u, 1);
	while (index != 0)
	{
		End = index;
		SubStr(S, temp, Start, End - Start);
		Start = End;
		StrInsert(T, pos, temp);
		pos = T.Length;
		StrInsert(T, pos, v);
		pos = T.Length;
		index = Index_KMP(S, u, index + u.Length);
	}
	if (End + u.Length < S.Length)
	{
		Start = End + u.Length;
		SubStr(S, temp, Start, S.Length - Start);
		StrInsert(S, pos, temp);
	}
	return T;
}
