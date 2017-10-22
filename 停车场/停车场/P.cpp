#include"Queue.h"
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	Stack Parking = (Stack)malloc(sizeof(Car));
	Queue Waiting = CreateQueue();
	Stack Temp = (Stack)malloc(sizeof(Car));
	Parking = CreateStack(Parking);
	Temp = CreateStack(Temp);
	
	int n;//Í£³µ³¡ÈÝÁ¿
	scanf_s("%d", &n);
	eatline();
	char Info = getchar();
	int car_id;
	int time;
	while (Info != 'E')
	{
		scanf_s("%d%d", &car_id, &time);
		switch (Info)
		{
		case 'A':
		{
			if (Stack_length(Parking) < n)
				Push(Parking, car_id, time);
			else {
				Car waitcar;
				waitcar.card_id = car_id;
				waitcar.time = time;
				waitcar.next = NULL;
				InQueue(Waiting, waitcar);
			}
		}break;
		case 'D':
		{
			Position p = Parking->next;
			Position tempP;
			while (p->card_id != car_id)
			{
				tempP = Pop(Parking);
				Push(Temp, tempP->card_id, tempP->time);
				p = p->next;
			}
			Position Leave_Car = Pop(Parking);
			printf_s("id = %d stay time = %d",Leave_Car->card_id, time - Leave_Car->time);
			while (!IsEmpty(Temp))
			{
				Position temp = Pop(Temp);
				Push(Parking, temp->card_id, temp->time);
			}
			if (Waiting.length > 0)
			{
				Car next_car = OutQueue(Waiting);
				Push(Parking, next_car.card_id, next_car.time);
			}
		}break;
		default:
			break;
		}
		printf_s("Now Parking:\n");
		ShowStack(Parking);
		printf_s("Now Pass:\n");
		ShowQueue(Waiting);
		eatline();
		Info = getchar();
		eatline();
	}
	system("pause");
	return 0;
}