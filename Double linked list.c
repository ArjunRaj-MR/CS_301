/*
Advantages of double linked list: 
	Traversal is possible from tail to head.
	Easier to roll back to a previous node. Which inturn makes the reversing of the node easier.
	More efficient in using memory than arrays.
Disadvantages of double linked list:	
	The whole list has to be traversed to reach the first node from the last node.
	Insertion and deletion of nodes is a bit complicated.
	Slower than arrays while accessing an element.
Changes in the program:
	The structure contained an extra variable to point to the previous node.
	The address of the first and last(head&tail) nodes needed to be saved.
	There were only few changes to the code that "generates" the Doubly Linked List: the pointer pointing to the prev. node has to be assigned every time a node is created.
	The reverselist() code had substantial change, it was very simple, as it is possible to traverse the doubly linked list in the reverse order.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int num;
	struct Node *next,*prev;};
int main()
{
	int i;
	void reverselist(struct Node*);
	struct Node *DLLH=NULL,*DLLT=NULL,*node=NULL;
	printf("Creating doubly linked list.....\n");
	for(i=0;i<10;i++)
	{
		if(i==0)
		{
			node=(struct Node*)malloc(sizeof(struct Node));
			DLLH=node;
			node->prev=NULL;
		}
		else
		{
			node->next=(struct Node*)malloc(sizeof(struct Node));
			node->next->prev=node;
			node=node->next;
		}
		node->num=i*2;
	}
	node->next=NULL;
	DLLT=node;
	node=DLLH;
	printf("Printing the list.....\n|");
	while(node!=NULL)
	{
		printf("%d<->",node->num);
		node=node->next;
	}
	printf("\b\b\b|  \n");
	reverselist(DLLT);
	return 0;
}
void reverselist(struct Node *LL)
{
	struct Node *node,*Dll;
	printf("\nReversing the list.....\n");
	while(LL!=NULL)
	{
		if(LL->next==NULL)
		{
			node=(struct Node*)malloc(sizeof(struct Node));
			Dll=node;
			node->prev=NULL;
		}
		else
		{
			node->next=(struct Node*)malloc(sizeof(struct Node));
			node->next->prev=node;
			node=node->next;
		}
		node->num=LL->num;
		LL=LL->prev;
	}
	node->next=NULL;
	printf("Printing the reversed list.....\n|");
	node=Dll;
	while(node!=NULL)
	{
		printf("%d<->",node->num);
		node=node->next;
	}
	printf("\b\b\b|  \n");
}	
