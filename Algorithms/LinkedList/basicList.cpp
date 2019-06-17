#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{

	int data;
	struct List *link;

};

struct List *head = NULL;


void addList(int num)
{

	List *temp = (struct List*)malloc(sizeof(struct List));
	temp->data = num;
	temp->link = NULL;


	if(head == NULL)
	{

		head = temp;
	}

	else
	{
		List *node = head;
		while(node->link)	
			node = node->link;

		node->link = temp;

	}

}


bool addAscList(int num)
{

	List *temp = (struct List*)malloc(sizeof(struct List));
	temp->data = num;
	temp->link = NULL;


	if(head == NULL)
	{

		head = temp;
		return true;

	}

	else{

		if(head->data>num)
		{

			temp->link = head;
			head = temp;
		}
		else
		{

			List *node = head;
			while(node->link )
			{
				if(node->data < num && node->link->data > num)
				{
					break;	

				}
				node = node->link;
			}
			temp->link = node->link;
			node->link = temp;

		}

		return true;
	}


}


void reverseLinks()
{

	List *prevNode,*currentNode,*nextNode;

	prevNode = NULL;
	currentNode = head;
	nextNode = head;

	while(currentNode)
	{

		nextNode = currentNode->link;

		currentNode->link  = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;

	}

	head = prevNode;


}


void rcvReverse(List *prevNode,List *currentNode,List **ptr){
	if(currentNode->link)
	{
		rcvReverse(currentNode,currentNode->link,ptr);
	}
	else
	{
		*ptr = currentNode;
	}
	currentNode->link = prevNode;

}
void display()
{

	List *node = head;
	while(node)
	{
		cout <<"node->data == "<<node->data<<endl;
		node = node->link;

	}

}
int main()
{

	addAscList(1);
	addAscList(10);
	addAscList(2);
	addAscList(9);
	addAscList(99);
	addAscList(-17);
	addAscList(3);
	addAscList(8);
	display();
	cout <<"reversing links"<<endl;
	reverseLinks();
	display();
	cout<<"recursive reverse"<<endl;
	rcvReverse(NULL,head,&head);
	display();




}
