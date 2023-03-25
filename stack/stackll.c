#include <stdlib.h>
#include <stdio.h>
#include "stackll.h"

int pop(struct node *root)
{
	if (root == NULL)
	{
		printf("\nStack is empty.");
		exit(1);
	}
	struct node * iter = root;
	if (root  -> next == NULL)
	{
		int rvalue = root -> data;
		free(root);
		return (rvalue);
	}
	while (iter -> next -> next != NULL)
		iter = iter -> next;
	struct node * temp = iter -> next;
	int rvalue = temp -> data;
	free(temp);
	iter -> next = NULL;
	return rvalue;
}

struct node * push(struct node *root, int a)
{
	if (root == NULL)
	{
		root = (struct node*)malloc(sizeof(struct node));
		root -> next = NULL;
		root -> data = a;
		return (root);
	}
	struct node * iter = root;
	while (iter -> next != NULL)
		iter = iter -> next;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = a;
	temp -> next = NULL;
	iter -> next = temp;
	return (root);
}


int main(void){
	struct node * s = NULL;
	s = push(s,10);
	s = push(s,20);
	printf("%d ->", pop(s));
	printf("%d ->", pop(s));
	return (0);
}
