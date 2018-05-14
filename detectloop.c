#include<stdio.h>
struct Node
{
	int data;
	struct Node *next;
};

int main(void)
{
struct Node *slow=head,*fast=head;
while(slow)
{
	while(fast)
	{
		fast=fast->next;
		if(slow==fast) return 1;
	}
	slow=slow->next;
}
return 0;
}
