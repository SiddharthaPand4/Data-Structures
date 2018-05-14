#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left,*right;
};

struct Node *FindMin(struct Node *root)
{
	if(root==NULL) return NULL;
	if(root->left==NULL) return root;
	else return FindMin(root->left);
}

struct Node *delete(struct Node *root,int data)
{
	if(root==NULL) root=NULL;
	else if(root->data>data) root->left=delete(root->left,data);
	else if(root->data<data) root->right=delete(root->right,data);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->right==NULL)
		{
			struct Node *temp=root;
			root=temp->left;
			free(temp);
		}
		else if(root->left==NULL)
		{
			struct Node *temp=root;
			root=root->right;
			free(temp);
		}
		else
		{
			struct Node *temp=FindMin(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
}
