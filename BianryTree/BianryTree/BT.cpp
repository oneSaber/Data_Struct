#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node*left, *right;
};

typedef struct Node* NODE;
typedef struct Node* Tree;
int initTree(Tree t)
{
	t->data = 0;
	t->left = NULL;
	t->right = NULL;
}
Tree Find(int search_key, Tree T)
{
	if (T->data == search_key)
		return T;
}