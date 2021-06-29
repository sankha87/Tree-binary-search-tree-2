// Binary search tree - Implementation in C
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}*root;

void Insert(int);
struct Node* insertNode(struct Node* , int);
struct Node* GetNewNode(int);
void inorder_recursive(struct Node *);

int main()
{
	Insert(15);
	Insert(10);
	Insert(20);
	Insert(25);
	Insert(8);
	Insert(12);
	printf("\nInorder Traversal : \n");
	inorder_recursive(root);
	_getch();
}

struct Node* GetNewNode(int value)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
};

void Insert(int value)
{
	root = insertNode(root, value);
}

struct Node* insertNode(struct Node* root, int value)
{
	if (root == NULL)
		root = GetNewNode(value);

	else if (root->data < value)
		root->right = insertNode(root->right, value);
	else
		root->left = insertNode(root->left, value);

	return root;
}


void inorder_recursive(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		inorder_recursive(root->left);
		printf("%d ", root->data);
		inorder_recursive(root->right);
	}
}