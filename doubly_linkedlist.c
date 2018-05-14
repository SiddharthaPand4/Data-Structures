#include<stdio.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;

void insertAtHead(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}

void print()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

void reverse_print()
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->prev;
	}
}

int main(void)
{
	head=NULL;
	insertAtHead(2);
	insertAtHead(5);
	insertAtHead(8);
	insertAtHead(13);
	print();
	reverse_print();
	return 0;
}