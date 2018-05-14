#include<stdbool.h>
/*
struct Node
{
	int data;
	struct Node *left,*right;
};
*/

isSubtreeLesser(struct Node *root,int value)
{
	if(root==NULL) return true;
	else if(root->data<=value&&isSubtreeLesser(root->left)&&isSubtreeLesser(root->right))
	return true;
	else return false;
}

isSubtreeGreater(struct Node *root,int value)
{
	if(root==NULL) return true;
	else if(root->data>value&&isSubtreeGreater(root->left)&&isSubtreeGreater(root->right))
	return true;
	else return false;
}

bool isBst(struct Node *root)
{
	if(root==NULL) return true;
	else if(isSubtreeLesser(root->left,root->data)&&isSubtreeGreater(root->right,root->data)&&isBst(root->left)&&isBst(root->right))
	return true;
	else
	return false;
}