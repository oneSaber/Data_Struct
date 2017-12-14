#include<stdio.h>
#include<stdlib.h>
#include"MAP.h"

int main()
{
	Node G[MAXLEN];
	CreatGraph(G,true);
	//Shell(G);
	ShowGraph(G);
	system("pause");
	return 0;
}