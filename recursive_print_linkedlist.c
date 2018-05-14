#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node* insert(struct node *head,int x)
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
	return head;
}

 void print(struct node *ptr)
{
	if(ptr==NULL)
	{
		printf("\n");
		return;
	}
	printf("%d\n",(*ptr).data);
	print((*ptr).link);
}

void reverse_print(struct node *p)
{
	if(p==NULL)
	{
		printf("\n");
		return;
	}
	reverse_print((*p).link);
	printf("%d\n",(*p).data);
}

int main(void)
{
	struct node *head=NULL;
	int l;
	printf("Enter the number of values to be inserted = ");
	scanf("%d",&l);
	for(int i=0,x;i<l;i++)
	{
		printf( "Data : ");
		scanf("%d",&x);
		head=insert(head,x);
	}
	print(head);
	reverse_print(head);
	return 0;
}