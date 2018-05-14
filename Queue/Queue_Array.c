#include<stdio.h>
#include<stdbool.h>
#define MAX 10

int a[MAX],front,rear;

bool IsFull()
{
	if((rear+1)%MAX==front) return 1;
	return 0;
}

bool IsEmpty()
{
	if((front==-1)&&(rear==-1)) return 1;
	return 0;
}

void enqueue(int data)
{
	if(IsFull()) return;
	else if(IsEmpty())
	{
		front=rear=0;
	}
	else
	{
		rear=(rear+1)%MAX;
	}
	a[rear]==data;
}

void dequeue()
{
	if(IsEmpty()) return;
	else if(front==rear) front=rear=-1;
	else
	{
		front=(front+1)%MAX;
	}
}

void print()
{
	for(int i=front;i<=rear;i++)
	printf("%d  ",a[i]);
	printf("\n");
}

int main(void)
{
	front=rear=-1;
	enqueue(5);
	enqueue(10);
	enqueue(8);
	enqueue(3);
	enqueue(1);
	enqueue(13);
	enqueue(9);
	enqueue(7);
	enqueue(2);
	print();
	dequeue();
	dequeue();
	print();
	//printf("%d",a[5]);
	return 0;
}
