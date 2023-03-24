#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node * next;
	struct node * prev;
};

void	print(struct node * r)
{
	printf("\n");
	while (r!=NULL)
	{
		printf("%d ",r->x);
		r = r -> next;
	}
}

struct node * addSeq(struct node * r, int x)
{
	if (r == NULL)
	{
		r = (struct node*)malloc(sizeof(struct node));
		r -> prev = NULL;
		r -> next = NULL;
		r -> x = x;
		return (r);
	}
	if (r -> x > x)
	{
		struct node * temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> next = r;
		temp -> prev = NULL;
		temp -> x = x;
		r -> prev = temp;
		return (temp);
	}
	struct node * iter = r;
	while (iter -> next != NULL && iter -> next -> x < x)
		iter = iter -> next;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> prev = iter;
	if (temp -> next !=NULL)
		temp -> next -> prev = temp;
	temp -> x = x;
	return (r);
}

struct node *delete(struct node * r, int x)
{
	struct node * temp;
	struct node * iter = r;

	if (r -> x == x)
	{
		temp = r;
		r = r -> next;
		free(temp);
		return (r);
	}
	while (iter -> next != NULL && iter -> next -> x != x)
		iter = iter -> next;
	if (iter -> next == NULL){
		printf("Number cannot found.\n");
		return (r);
	}
	temp = iter -> next;
	iter -> next = iter -> next -> next;
	free(temp);
	if (iter -> next !=NULL)
		iter -> next -> prev = iter;
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
