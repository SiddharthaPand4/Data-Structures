#include<stdio.h>

struct node
{
	int data;
	struct node* link;
};

struct node* head;

int insert(int data,int pos)
{
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	(*temp1).data=data;
	if(pos==1)
	{
		(*temp1).link=head;
		head=temp1;
		return;
	}
	struct node* temp2=head;
	for(int i=0;i<pos-2;i++)
	{
		temp2=(*temp2).link;
	}
	(*temp1).link=(*temp2).link;
	(*temp2).link=temp1;
	return 0;
}

void print(void)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("\n%d",(*temp).data);
		temp=(*temp).link;
	}
}

void delete(int pos)
{
	struct node *temp3=head;
	if(pos==1)
	{
		head=(*temp3).link;
		free(temp3);
		return;
	}
	for(int i=0;i<pos-2;i++)
	{
		temp3=(*temp3).link;
	}
	struct node* temp4=(*temp3).link;
	(*temp3).link=(*temp4).link;
	free(temp4);
}

int main(void)
{
	int n;
	head=NULL;
	printf("Enter the number of elements you want to insert = ");
	scanf("%d",&n);
	for(int i=0,data,pos;i<n;i++)
	{
		printf("\nEnter the data = ");
		scanf("%d",&data);
		printf("\nEnter the position you wanna enter= ");
		scanf("%d",&pos);
		insert(data,pos);
	}
	print();
	int pos;
	printf("\n\nEnter the position of the data you want to delete = ");
	scanf("%d",&pos);
	delete(pos);
	print();
	return 0;
}
