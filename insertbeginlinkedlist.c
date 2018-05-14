#include<stdio.h>

struct node
{
	int data;
	struct node* link;
};

struct node* head;

void insert(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	(*temp).data=x;
	(*temp).link=head;
	head=temp;
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

int main(void)
{
	int n;
  printf("The number of elements you want to insert:- ");
  scanf("%d",&n);
  for(int i=0,x;i<n;i++)
  {
  	printf("\nEnter the element = ");
  	scanf("%d",&x);
  	insert(x);
  	print();
  }
  	return 0;
}