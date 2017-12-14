#include<stdio.h>
#include<stdlib.h>
//返回数组的长度
int ReadFile(FILE *f, int Data[])
{
	int data;
	int i = 1;
	while (fscanf_s(f,"%d",&data)==1)
	{
		Data[i] = data;
		i++;
	}
	return i-1;
}
//顺序查找
int Search(int key, int Data[])
{
	for (int i = 0; i < Data[0]; i++)
	{
		if (Data[i] == key)
			return i;
	}
	return 0;
}
//折半查找
int BinarySearch(int key, int data[],int left,int right)
{
	if (left > right)
		return 0;
	int mid = (left + right) / 2;
	if (data[mid] == key)
		return mid;
	else {
		if (data[mid] < key)
			return BinarySearch(key, data, mid + 1, right);
		else return BinarySearch(key, data, left, mid - 1);
	}
}
// 折半查找，非递归写法
int Bsearch(int key, int left, int right, int A[])
{
	while (left <= right&&left>0&&right<=A[0])
	{
		int mid = (left + right) / 2;
		if (A[mid] == key)
			return mid;
		else if (A[mid] < key)
			left = mid + 1;
		else if (A[mid] > key)
			right = mid - 1;
	}
	return 0;
}
int main()
{
	FILE *fout;
	fopen_s(&fout,"data.txt", "r");
	int data[10];
	//printf_s("%d %d", 'EOF', '\n');
	data[0]=ReadFile(fout, data);
	int search_key;
	printf_s("输入查找的数字：");
	scanf_s("%d", &search_key);
	//int postion = BinarySearch(search_key, data, 1, data[0]);
	int position = Bsearch(search_key, 1, data[0], data);
	if(position)
		printf_s("%d", position);
	else printf_s("can not find");
	system("pause");
	return 0;
}