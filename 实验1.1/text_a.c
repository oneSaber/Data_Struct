#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct card
{
	char type[81];//牌色
	int number;//牌大小
	struct card *next;
};

typedef struct card Card;
typedef Card *List;
typedef Card *Position;

int IsLast(Position p)
{
	return p->next == NULL;
}
//链表是否为空
int IsEmpty(List L)
{
	return L->next == NULL;
}
List MakeList(List L)
{
	if (L == NULL)
		L = (List)malloc(sizeof(Card));
	L->next = NULL;
	return L;
}
//输出链表
void ShowList(List L)
{
	if (!IsEmpty(L))
	{
		Position P = L->next;
		while (P!=NULL)
		{
			if (P->number <= 10)
				printf("%s %d\n", P->type, P->number);
			else
			{
				switch (P->number)
				{
				case 11:printf("%s J\n", P->type); break;
				case 12:printf("%s Q\n", P->type); break;
				case 13:printf("%s K\n", P->type); break;
				case 53:printf("Joker\n"); break;
				case 54:printf("Joker\n"); break;
				}
			}
			P = P->next;
		}
	}
	else printf("Empty List ,Nothing Can Show");
}
//p是q的前驱，交换q和它的后继
void SwitchNode(Position p, Position q)
{
	if (!IsLast(p))
	{
		int tempNum = p->number;
		p->number = q->number;
		q->number = tempNum;
		//交换p.q的牌色
		char temp[81];
		strcpy_s(temp, p->type);
		strcpy_s(p->type, q->type);
		strcpy_s(q->type, temp);
	}
}
//排序
List Sort(List L)
{
	Position p = L->next;
	while (!IsLast(p))
	{
		Position q = p->next;
		while (!IsLast(q))
		{
			if (q->number < p->number)
				SwitchNode(p, q);
			q = q->next;
		}
		p = p->next;
	}
	return L;
}
//插入头结点之后，再排序
void Insert(List L, int num, int cardtype)
{
	Position p = (Position)malloc(sizeof(Card));
	if (num == 53 || num == 54)
		p->number = num;
	else 
	{
		p->number = num % 13;
		if (p->number == 0)
			p->number = 13;
	}
	if (num == 53 || num == 54)
	{
		char temp[81] = "Joker";
		strcpy_s(p->type, temp);
	}
	else 
	{
		switch (cardtype)
		{
		case 0: {char temp[81] = "Heart"; strcpy_s(p->type, temp); } break;//红桃
		case 1: {char temp[81] = "club"; strcpy_s(p->type, temp); } break;//梅花
		case 2: {char temp[81] = "diamond"; strcpy_s(p->type, temp); } break;//方块
		case 3: {char temp[81] = "spade"; strcpy_s(p->type, temp); } break;//黑桃
		default:
			break;
		}
	}
	p->next = L->next;
	L->next = p;
}

void newCard(int cardNum[],List la)
{
	int cardnum = rand() % 54 + 1;
	while (cardNum[cardnum])
	{
		cardnum = rand() % 54 + 1;
	}
	cardNum[cardnum] = 1;
	Insert(la, cardnum, cardnum % 4);
}
//last是三张地主牌
 void Deal_Card(List la,List lb,List lc,List last)
 {
	 srand(time(0));
	 la = MakeList(la);
	 lb = MakeList(lb);
	 lc = MakeList(lc);
	 last = MakeList(last);
	 int cardNum[55] = { 0 };
	 for (int i = 0; i < 17; i++)
	 {
		 newCard(cardNum, la);
		 newCard(cardNum, lb);
		 newCard(cardNum, lc);
	 }
	 for (int i = 1; i < 55; i++)
	 {
		 if (!cardNum[i])
		 {
			 Insert(last, i, i % 4);
		 }
	 }
	 printf_s("la :\n");
	 Sort(la);
	 ShowList(la);
	 printf_s("lb:\n");
	 Sort(lb);
	 ShowList(lb);
	 printf_s("lc:\n");
	 Sort(lc);
	 ShowList(lc);
	 printf_s("last:\n");
	 Sort(last);
	 ShowList(last);
 }

int main()
{
	List la = NULL;
	List lb = NULL;
	List lc = NULL;
	List last = NULL;
	Deal_Card(la, lb, lc, last);
	system("pause");
	return 0;
}