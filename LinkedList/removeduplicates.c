void removeduplicates(Node *head)
{
	Node *temp=head;
	int prev;
	while(temp)
	{
		if(temp!=head)
		{
			if(prev->data==temp->data)
			{
				prev->next=temp->next;
				free(temp);
				temp=prev;
			}
		}
		prev=temp;
		temp=temp->next;
	}
}
