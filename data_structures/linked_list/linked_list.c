#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	struct node * next;
};

void	print(struct node *r)
{
	while (r != NULL)
	{
		printf("\n%d ", r-> x);
		r = r -> next;
	}
} 

int main(void)
{
	struct node * root;
	root = (struct node*)malloc(sizeof(struct node));
	struct node * iter = NULL;
	iter = root;
	root -> x = 10;
	root -> next = (struct node *)malloc(sizeof(struct node));
	root -> next -> x = 20;
	root -> next -> next = (struct node*)malloc(sizeof(struct node)); 
	root -> next -> next -> x = 30;
	root -> next -> next -> next = NULL;
	printf("%d", iter -> x);
	iter = iter -> next;
	printf(" %d",iter -> x);
        iter = iter -> next;
	printf(" %d", iter-> x);
	iter = root;
	int i = 0;  	
/*	while(iter -> next != NULL)
	{
		i++;
		printf("\n%d. eleman %d ",i,iter -> x);
		iter = iter -> next;
	}*/

	for(;i < 5;i++)
	{
		iter -> next = (struct node *)malloc(sizeof(struct node));
		iter = iter -> next;
		iter -> x = i * 10;
	}
	print(root);
	
	return (0);
}
