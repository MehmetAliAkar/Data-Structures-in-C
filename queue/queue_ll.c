#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node * next;
};

struct node * temp = NULL;
struct node * frant = NULL;
struct node * rear = NULL;

void enque(int data){
	struct node * element = (struct node*)malloc(sizeof(struct node));
	element -> x = data;

	if (front == NULL){
		front = element;
		front -> next = front;
		rear = eleman;
		rear -> next = NULL;
	}
	else if(front -> next == front)
	{
		rear -> next = element;
		rear = element;
		front -> next = NULL;
		front -> next = rear;
	}
	else{
	rear -> next = element;
	rear = element;
	rear -> next = NULL;
	}
}

void deque(){
	if ( front == NULL)
		printf("\nEmpty queue");
	else
	{
		temp = front;
		while (temp -> next != NULL)
		{
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("%d ",temp -> data);
	}
}
