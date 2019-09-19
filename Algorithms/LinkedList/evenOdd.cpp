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


void evenOddSegregate()
{

	List *even = NULL;
	List *odd = NULL ;
	List *current = head;

	int count =1;

	while(current != NULL)
	{

		if (count %2 == 0) // even node
		{

			if(even  == NULL)
				even = current;
			even->link = current;

		}

		else // odd node
		{


			if (odd == NULL)
				odd = current;
			odd->link = current;

		}

		count++;
		current = current->link;
	}
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
	evenOddSegregate();




}
