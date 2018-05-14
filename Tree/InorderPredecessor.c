/*
struct Node
{
	int data;
	struct Node *left,*right;
};
*/

struct Node *Find(struct Node *root,int data)
{
	if(data<root->data) return Find(root->left,data);
	else if(data>root->data) return Find(root->right,data);
	else return root;
}

struct Node *FindMax(struct Node *root)
{
	if(root==NULL) return NULL;
	if(root->right!=NULL) root=FindMin(root->right);
	return root;
}

struct Node *predecessor(struct Node *root,int data)
{
	struct Node *current=Find(root,data);
	if(current==NULL) return NULL;
	else if(current->right!=NULL)
	return FindMin(current->right);
	else
	{
		struct Node *predecessor=NULL;
		struct Node *ancestor=root;
		while(ancestor!=current)
		{
			if(current->data>ancestor->data)
			{
				predecessor=ancestor;
				ancestor=ancestor->left;
			}
			else
			ancestor=ancestor->right;
		}
		return predecessor;
	}
}