#include"Queue.h"
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>

void ShowQueue(Queue q)
{
	Car c;
	while (q.length > 0)
	{
		c = OutQueue(q);
		printf_s("%c,%d,%d\n", c.Info, c.card_id, c.stay_time);
	}
}
void All_inQueue(Queue &q)
{
	Car c;
	c.Info = getchar();
	eatline();
	while (scanf_s("%d%d",&c.card_id, &c.stay_time) == 2)
	{
		eatline();
		InQueue(q, c);
		c.Info = getchar();
		eatline();
	}
	eatline();
}
int main()
{
	Stack car_stack = (Stack)malloc(sizeof(Car));
	car_stack =	CreateStack(car_stack);
	Queue car_queue;
	car_queue = CreateQueue();
	printf_s("Queue:\n");
	All_inQueue(car_queue);
	printf_s("show queue:\n");
	ShowQueue(car_queue);
	system("pause");
	return 0;
}