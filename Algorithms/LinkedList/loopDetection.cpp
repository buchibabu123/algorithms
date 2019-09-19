#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{

	int data;
	struct List *link;

};

struct List *head = NULL;


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



List *detectLoop(List *head)
{

	List *slw_ptr = head;
	List *fst_ptr = head;


	while(slw_ptr && fst_ptr && fst_ptr->link)
	{


		slw_ptr = slw_ptr->link;
		fst_ptr = fst_ptr->link->link;
		if(slw_ptr == fst_ptr)
			return slw_ptr;	
	}

	return NULL;
}

bool removeLoope(List *head,List *loopNode)
{
#ifdef ROTATE
	List *ptr = head;
	List *temp = loopNode;
	while(1)
	{

		temp = loopNode;
		while(temp->link != loopNode && temp->link != ptr)
			temp = temp->link;
		if(temp->link == ptr)
		{
			cout <<"removig loop"<<temp->data<<endl;
			break;
		}

		ptr = ptr->link;
	}
	temp->link = NULL;
#else
	cout <<"2nd method for loop removing"<<endl;

	List *ptr = head;
	List *temp = loopNode;
	while(ptr->link!=temp->link)
	{

		ptr = ptr->link;
		temp = temp->link;

	}
	temp->link = NULL;

#endif



}

void display()
{

	List *node = head;
	while(node!=NULL)
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
	display();
	if(detectLoop(head) != NULL)
		cout <<"list has loop"<<endl;
	else
		cout <<"no loop in the list"<<endl;

	cout <<head->link->link->link->link->link->link->data<<endl;
	cout <<head->link->link->data<<endl;
	head->link->link->link->link->link->link = head->link->link;
	List *loopNode = detectLoop(head);
	if(loopNode != NULL)
		cout <<"list has loop"<<endl;
	else
		cout <<"no loop in the list"<<endl;

	removeLoope(head,loopNode);

	display();




}
