/*
 *
 * BST Operations
 * 1.) insert
 * 2.) search
 * 3.) inorder,preorder,postorder
 * 4.) delete node
 *
 * */

#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct Node
{

	int data;
	struct Node *left;
	struct Node *right;

} Node;

struct Node *head = NULL;
Node *NewNode(Node *root , int key)
{

    root = (Node*)malloc(sizeof(Node));
    root->left = root->right = NULL;
    root->data = key;
    return root;

}

void insertNode(Node *root,int key)
{

    if(root == NULL)
        return NewNode(key);
    else if (root->data > key)
        root->left = insertNode(root->left,key);
    else if (root->data < key)
        root->right = insertNode(root->right,key);
    else
    {
        printf("duplicate entry\n");
    }


}


void preorder(Node *root)
{
    if(root ! = NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }

}
int  main()
{
    head = insertNode(head,5);
    insertNode(head,2);
    insertNode(head,20);
    insertNode(head,4);
    insertNode(head,15);

    preorder(head);

	return 0;
}

