#include<stdio.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *Front,*End;

bool isempty()
{
	if((Front==NULL)&&(End==NULL)) return 1;
	return 0;
}

struct Node* GetNewNode(int data)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void Enqueue(int data)
{
	struct Node*
    temp=GetNewNode(data);
	if((Front==NULL)&&(End==NULL))
	{
		Front=temp;
		End=temp;
		return;
	}
	End->next=temp;
	End=temp;
}

void Dequeue()
{
	if(isempty()) return;
	else if(Front==End)
	{
		struct Node *temp=Front;
		Front=End=NULL;
		free(temp);
	}
	else
	{
	struct Node* temp=Front;
	Front=temp->next;
	free(temp);
	}
}

void Print()
{
	struct Node* temp=Front;
	printf("Queue: ");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
		
int main(void)
{
	Front=NULL;
	End=NULL;
	Enqueue(5);
	Enqueue(9);
	Enqueue(3);
	Enqueue(8);
	Print();
	Dequeue();
	Print();
	return 0;
}