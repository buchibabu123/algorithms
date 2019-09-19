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
#include <stdlib.h>
//#include <iostream>

//using namespace std;

typedef struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
    int height;

} Node;

struct Node *head = NULL;
Node *NewNode(int key)
{

    Node *root = (Node*)malloc(sizeof(Node));
    root->left = root->right = NULL;
    root->data = key;
    root->height = 1;
    return root;

}

int Getheight(Node *root)
{

    if( root == NULL )
        return 0;
    return (root->height);

}

int Getbalance(Node *root)
{

    if(root == NULL)
        return 0;
    else
    {

        return ( Getheight(root->left) - Getheight(root->right) );

    }

}

int max(int a , int b)
{

    return (a>b)?a:b;
}

Node *rightBalance(Node *root)
{

    printf("rightBalance\n");
    Node *temp = root->left;
    Node *x = temp->right;

    // Perform Rotation
    temp->right = root;
    root->left = x;
    root->height = 1 + max(Getheight(root->left),Getheight(root->right));
    temp->height = 1+ max(Getheight(temp->left),Getheight(temp->right));
    return temp;

}

Node *leftBalance(Node *root)
{

    printf("leftBalance\n");
    Node *temp = root->right;
    Node *x = temp->left;

    temp->left = root;
    root->right = x;
    root->height = 1 + max(Getheight(root->left),Getheight(root->right));
    temp->height = 1+ max(Getheight(temp->left),Getheight(temp->right));

    return temp;


}

Node  *insertNode(Node *root,int key)
{

    if(root == NULL)
        return NewNode(key);
    else if (root->data > key)
    {
        root->left = insertNode(root->left,key);
        printf("left insertion\n");
    }
    else if (root->data < key)
        root->right = insertNode(root->right,key);
    else
    {
        printf("duplicate entry\n");
        return root;
    }

    root->height =  1 + max(Getheight(root->left),Getheight(root->right)); 

    int balance = Getbalance(root);
    printf("balance == [ %d ]\n",balance);
    if(balance > 1 &&  key < root->left->data)
        return rightBalance(root);
    else if (balance < 1 && key > root->right->data)
        return leftBalance(root);
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftBalance(root->left);
        rightBalance(root);

    }
    else if ( balance < 1 && key < root->right->data)
    {
        root->right = rightBalance(root->right);
        leftBalance(root);

    }
    return root;

}


void preorder(Node *root)
{
    if(root != NULL)
    {
        preorder(root->left);
        printf("%d\t",root->data);
        preorder(root->right);
    }

}
int  main()
{
    head = insertNode(head,1);
    head = insertNode(head,4);
    head = insertNode(head,5);
    head = insertNode(head,10);
    head = insertNode(head,20);

    preorder(head);

    return 0;
}

