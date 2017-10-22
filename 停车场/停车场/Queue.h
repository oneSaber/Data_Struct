#pragma once
#ifndef Queue_H
#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>

#define QueueLine 1000
struct Queue
{
	Car *wiatCars;
	int length;
	int start;
	//队尾为 0+length
};
//创建一个新的队列
Queue CreateQueue()
{
	Queue new_Queue;
	new_Queue.wiatCars = (Car *)malloc(sizeof(Car)*QueueLine);
	new_Queue.length = 0;
	new_Queue.start = 0;
	return new_Queue;
}
//入队
void InQueue(Queue &car_queue,Car car)
{
	int last = (car_queue.start + car_queue.length) % QueueLine;
	car_queue.wiatCars[last] = car;
	car_queue.length ++;
}
//出队
Car OutQueue(Queue &car_queue)
{
	Car outcar = car_queue.wiatCars[car_queue.start];
	car_queue.start++;
	car_queue.length--;
	return outcar;
}
//批量输入
void All_inQueue(Queue &q)
{
	Car c;
	while (scanf_s("%d%d", &c.card_id, &c.time) == 2)
	{
		eatline();
		InQueue(q, c);
	}
	eatline();
}

//输出队列
void ShowQueue(Queue q)
{
	Car c;
	for(int i = 0;i<q.length&&q.length>0;i++)
	{
		c = q.wiatCars[i];
		printf_s("%d,%d\n",c.card_id, c.time);
	}
}

#endif // !Queue_H
