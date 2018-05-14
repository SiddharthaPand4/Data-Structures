#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BstNode
{
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

struct Node
{
	struct BstNode *data;
	struct Node *next;
};
struct Node *front=NULL,*rear=NULL;

struct Node* GetNewNode(struct BstNode *data)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void enqueue(struct BstNode *data)
{
	struct Node*
    temp=GetNewNode(data);
	if((front==NULL)&&(rear==NULL))
	{
		front=temp;
		rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

void dequeue()
{
	if(front==NULL) return;
	else if(front==rear) front=rear=NULL;
	else
	{
	    struct Node* temp=front;
	    front=temp->next;
	    free(temp);
	}
}

bool IsEmpty()
{
	if((front==NULL)&&(rear==NULL)) return 1;
	return 0;
}

void ltraverse(struct BstNode *root) //levelorder
{
	if(root==NULL) return;
	enqueue(root);
	while(!IsEmpty())
	{
		struct BstNode *current=front->data;
		dequeue();
		printf("%d\n",current->data);
		if(current->left!=NULL) enqueue(current->left);
		if(current->right!=NULL) enqueue(current->right);
	}
}

void traverse(struct BstNode *root) //depthorder
{
	if(root==NULL) return;
	traverse(root->left);
	printf("%d\n",root->data);
	traverse(root->right);
}

int max(int x,int y)
{
	if(x<=y) return y;
	else return x;
}

int FindHeight(struct BstNode *root)
{
	int height;
	if(root==NULL) return -1;
	else
	{
		height=max(FindHeight(root->left),FindHeight(root->right))+1;
		return height;
	}
}

void FindMin(struct BstNode *root)
{
	if(root==NULL) return;
	else if(root->left==NULL) printf("Min=%d\n",root->data);
	else FindMin(root->left);
}

void FindMax(struct BstNode *root)
{
	if(root==NULL)
	{
		return;
	}
	else if(root->right==NULL)
	{
		printf("Max=%d\n",root->data);
	}
		FindMax(root->right);
}

struct BstNode *newnode(data)
{
	struct BstNode *temp=(struct BstNode*)malloc(sizeof(struct BstNode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct BstNode* insert(struct BstNode* root,int data)
{
	if(root==NULL)
	{
		root=newnode(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

int main(void)
{
	struct BstNode *root=NULL;
	root=insert(root,15);
	root=insert(root,60);
	root=insert(root,8);
	root=insert(root,22);
	root=insert(root,18);
	root=insert(root,25);
	traverse(root);
	FindMax(root);
	FindMin(root);
	int height=FindHeight(root);
	printf("Height=%d\n",height);
	ltraverse(root);
	return 0;
}
