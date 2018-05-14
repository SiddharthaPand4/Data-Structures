Node *merge(Node *A,Node *B)
{
	if(A==NULL&&B==NULL) return NULL;
	if(A!=NULL&&B==NULL) return A;
	if(B!=NULL&&A==NULL) return B;
	Node *headA=A,*headB=B,head,temp;
	while(A!=NULL&&B!=NULL)
	{
		if(A==headA&&B==headB)
		{
		    if(B->data>=A->data)
		    {
		    	head=headA;
		    	A=A->next;
		    }
		    else
		    {
		    	head=headB;
		    	B=B->next;
		    }
		    temp=head;
		}
		else
		{
			if(A->data<B->data)
			{
				temp->next=A;
				temp=A;
			}
			else
			{
				temp->next=B;
				temp=B;
			}
		}
	}
	while(A!=NULL)
	{
		temp->next=A;
		temp=A;
		A=A->next;
	}
	while(B!=NULL)
	{
		temp->next=B;
		temp=B;
		B=B->next;
	}
	return head;
}
