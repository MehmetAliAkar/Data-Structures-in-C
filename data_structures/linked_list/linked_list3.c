#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	struct node * next;
};

void	print(struct node *r)
{
	printf("\n");
	while (r != NULL)
	{
		printf("%d ", r-> x);
		r = r -> next;
	}
} 

void	insert(struct node *r, int num)
{
	while (r -> next != NULL)
		r = r -> next;
	r -> next = (struct node *)malloc(sizeof(struct node));
	r -> next -> x = num;
	r -> next -> next = NULL;
}

struct node * addSeq(struct node *r, int x)
{
	if (r == NULL){ // if linked list is empty
		r = (struct node*)malloc(sizeof(struct node));
		r -> next = NULL;
		r -> x = x;
		return (r);
	}
	if (r -> x > x) //if the value of insert node smaller than root's value
			//root is changing
	{ 
		struct node * temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> x = x;
		temp -> next = r;
		return (temp);
	}
	struct node * iter = r;
	while (iter -> next != NULL && iter -> next -> x < x)
	{
		iter = iter -> next;
	}
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> x = x;
	return (r);
}

struct node * delete(struct node * r, int x)
{
	struct node * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	struct node * iter = r;
	if (r -> x ==  x)
	{//control 1
		temp = r -> next;
		free(r);
		return (temp);
	}
	while (iter -> next != NULL && iter -> next -> x != x)
		iter = iter -> next;
	if (iter -> next == NULL)
	{
		printf("\nNumber cannot found.");
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
	print(root);
	root = delete(root, 500);
	print(root);
	return (0);
}
