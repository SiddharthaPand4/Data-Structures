#include<stdbool.h>
/*
struct Node
{
	int data;
	struct Node *left,*right;
}
*/

isBST(struct Node *root,int minValue,int maxValue)
{
	if(root==NULL) return true;
	else if(root->data>minValue&&root->data<maxValue&&isBST(root->left,minValue,root->data)&&isBST(root->right,root->data,maxValue))
	return true;
	else false;
}

bool isBst(struct Node *root)
{
	return isBST(root,INT_MIN,INT_MAX);
}