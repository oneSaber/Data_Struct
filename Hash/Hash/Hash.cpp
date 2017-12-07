#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxLen 100
#define LinkLen 10

//利用哈希存储信息，假设信息小于100

struct data {
	char PhoneNumber[81];
	char Name[81];
	char Address[81];
};
typedef struct data Person;
struct HashNode {
	Person info;
	struct HashNode *next;
};

struct InfoNode {
	Person info;
	int store;
	//1为以经存储，0为未存储
};
typedef struct HashNode *Node;
typedef struct InfoNode Personal;

//冲突时生成新的hash
int newHash(int oldhash)
{
	return (oldhash + 1) % MaxLen;
}
//返回用电话号码生成的hash值，-1为输入结束
int Hash(char Key[])
{
	if (Key[0] == '\0')
		return -1;
	int sum = 0;
	int i = 0;
	while (Key[i] != '\0')
		sum += Key[i++];
	return sum % MaxLen;
}
//初始化People数组，将所有格子设为未储存
void InitPeople(Personal People[])
{
	for (int i = 0; i < MaxLen; i++)
	{
		People[i].store = 0;
	}
}
//按照电话号码存储信息
void StoreByPhone(Personal People[])
{
	int i = 0;
	char tempPhone[81];
	while (i<MaxLen)
	{
		gets_s(tempPhone);
		int hash = Hash(tempPhone);
		//输入结束
		if (hash == -1)
			return;
		if (hash > -1 && People[hash].store != 1)
		{
			strcpy_s(People[hash].info.PhoneNumber, tempPhone);
			gets_s(People[hash].info.Name);
			gets_s(People[hash].info.Address);
			i++;
		}
		else
		{
			while (hash < MaxLen-1)
			{
				hash = newHash(hash);
				if (People[hash].store != 1)
				{
					strcpy_s(People[hash].info.PhoneNumber, tempPhone);
					gets_s(People[hash].info.Name);
					gets_s(People[hash].info.Address);
					i++;
				}
			}
		}
	}
}
//按照电话号码查询
void SearchByPhone(Personal People[])
{
	printf_s("输入查找的电话:");
	char Phone[81];
	gets_s(Phone);
	int oldHash = Hash(Phone);
	//直接查找到，不冲突
	if (strcmp(Phone, People[oldHash].info.PhoneNumber) == 0)
	{
		printf_s("Number :%s\nName:%s\nAddress:%s",
			People[oldHash].info.PhoneNumber,
			People[oldHash].info.Name,
			People[oldHash].info.Address);

	}//冲突,继续查找
	else {
		int hash = oldHash;
		hash = newHash(hash);
		while(hash!=oldHash)
		{ 
			if (People[hash].store)
			{	//直接查找到，不冲突
				if (strcmp(Phone, People[oldHash].info.Name) == 0)
				{
					printf_s("Number :%s\nName:%s\nAddress:%s",
						People[oldHash].info.PhoneNumber,
						People[oldHash].info.Name,
						People[oldHash].info.Address);
					break;
				}
			}
			hash = newHash(hash);
		}
		//查找内容不存在
		hash = newHash(hash);
		//找到第一个不冲突的位置
		while (!People[hash].store)
		{
			strcpy_s(People[hash].info.PhoneNumber, Phone);
			printf_s("没有查找到输入名字和地址插入数据");
			gets_s(People[hash].info.Name);
			gets_s(People[hash].info.Address);
			break;
		}
	}
}


//用name做hash值
int HashName(char Key[])
{
	if (Key[0] == '\0')
		return -1;
	int sum = 0;
	int i = 0;
	while (Key[i] != '\0')
		sum += Key[i++];
	return sum % LinkLen;
}
void Init(Node People[])
{
	for (int i = 0; i < LinkLen; i++)
	{
		People[i] = (Node)malloc(sizeof(struct HashNode));
		People[i]->next = NULL;
	}
}
void TravePeople(Node People[])
{
	for (int i = 0; i < LinkLen; i++)
	{
		printf_s("%d:", i);
		Node P = People[i]->next;
		while (P != NULL)
		{
			printf_s("(%s, %s, %s)->", P->info.Name, P->info.PhoneNumber, P->info.Address);
			P = P->next;
		}
		printf_s("Null\n");
	}
}
//按名字储存
void StoreByName(Node Head[])
{
	char tempname[81];
	gets_s(tempname);
	int hash = HashName(tempname);
	while (hash != -1)
	{
		Node P = Head[hash];
		while (P->next!=NULL)
		{
			P = P->next;
		}
		Node Q = (Node)malloc(sizeof(struct HashNode));
		strcpy_s(Q->info.Name, tempname);
		gets_s(Q->info.PhoneNumber);
		gets_s(Q->info.Address);
		P->next = Q;
		Q->next = NULL;

		gets_s(tempname);
		hash = HashName(tempname);
	}
}

//按名字查找
void SearchByName(Node Head[])
{
	char searchname[81];
	printf_s("输入查找的名字:");
	gets_s(searchname);
	int hash = HashName(searchname);
	Node head = Head[hash];
	while (head->next != NULL)
	{
		//头结点放的是垃圾值
		head = head->next;
		if (strcmp(head->info.Name, searchname) == 0)
		{
			printf_s("(%s, %s, %s)->", head->info.Name, head->info.PhoneNumber, head->info.Address);
			return;
		}
	}
	Node Q = (Node)malloc(sizeof(struct HashNode));
	printf_s("未查找到");
	head->next = Q;
	Q->next = NULL;
	strcpy_s(Q->info.Name, searchname);
	gets_s(Q->info.PhoneNumber);
	gets_s(Q->info.Address);

}
int main()
{
	//按电话号码存储
	/*Personal People[MaxLen];
	InitPeople(People);
	StoreByPhone(People);
	SearchByPhone(People);*/
	//按名字储存
	Node People[LinkLen];
	Init(People);
	StoreByName(People);
	//TravePeople(People);
	SearchByName(People);
	system("pause");
	return 0;
}