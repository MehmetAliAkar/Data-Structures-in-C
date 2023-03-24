#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node * next;
}

void print(struct node *r)
{
	printf("\n");
	struct node * iter = r;
	while (iter -> next != r)
	{
		printf("%d ",iter -> x);
		iter = iter -> next;
	}
	printf("%d", iter -> x);
}

void insert(struct node *r, int x)
{
	struct node * iter = r;
	while (iter -> next != r)
		iter = iter -> next;
	iter -> next = (struct node*)malloc(sizeof(struct node));
	iter -> next -> x = x;
	iter -> next -> next = r;
}

struct node * addSeq(struct node *r, int x)
{
	if (r == NULL)
	{
		r = (struct node *)malloc(sizeof(struct node));
		r -> x = x;
		r -> next = r;
		return (r);
	}
	if (r -> x > x)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> x = x;
		temp -> next = r;
		struct node * iter = r;
		while (iter -> next != r)
			iter = iter -> next;
		iter -> next = temp;
		return (temp);
	}
	struct node * iter = r;
	while (iter -> next != r && iter -> next -> x != x)
	{
		iter = iter -> next;
	}
	struct node * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> x = x;
	temp -> next = iter -> next;
	iter -> next = temp;
}

struct node * delete(struct node *r, int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node * iter = r;
	if (r -> x == x)
	{		
		while (iter -> next != r)
			iter = iter -> next;
		temp = r;
		temp -> next =  iter -> next;
		free(temp);
		return (r);//check it 
	}
	while (iter -> next != r && iter -> next -> x != x)
		iter = iter -> next;
	if (iter -> next == r)
	{
		printf("Number cannot found!\n");
		return (r);
	}
	temp = iter -> next;
	iter -> next = iter -> next -> next;
	free(temp);
	return (r);
}

int main(void)
{
	        struct node * root = NULL;
		root = addSeq(root, 400);
		root = addSeq(root, 50);
	        root = addSeq(root, 4);
		root = addSeq(root, 20);
		root = addSeq(root, 500);
		print(root);
		printf("\n");
		root = delete(root,4);
	        print(root);
	        root = delete(root, 50);
	        print(root);
	        root = delete(root,500);
		print(root);												                root = delete(root, 500);
		print(root);													        return (0);
}
