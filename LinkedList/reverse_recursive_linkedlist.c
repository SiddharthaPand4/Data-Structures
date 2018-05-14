#include<stdio.h>

struct node
{
	int data;
	struct node *link;
};

struct node* head;

void insert(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	(*temp).data=x;
	(*temp).link=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
	struct node *temp1=head;
	while((*temp1).link!=NULL)
	{
		temp1=(*temp1).link;
	}
	(*temp1).link=temp;
	}
}

void print(void)
{
	printf("\nYour list is :- \n");
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("\n%d\n",(*temp).data);
		temp=(*temp).link;
	}
}

void reverse(struct node *p)
{
	if(p->link==NULL)
	{
		head=p;
		return;
	}
	reverse(p->link);
	struct node *q=p->link;
	q->link=p;
	p->link=NULL;
}

int main(void)
{
	insert(1);
	insert(5);
	insert(8);
	insert(13);
	insert(23);
	print();
	reverse(head);
	print();
	return 0;
}
