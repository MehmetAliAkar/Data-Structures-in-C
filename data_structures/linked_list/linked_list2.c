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
	if (r == NULL){
		r = (struct node*)malloc(sizeof(struct node));
		r -> next = NULL;
		r -> x = x;
		return (r);
	}
	else if(r -> next == NULL)
	{
		if(r -> x > x)
		{
			struct node * temp = (struct node *)malloc(sizeof(struct node));
			temp -> x = x;
			temp -> next = root;
			return (temp);
		}
		else
		{
			struct node * temp = (struct node*)malloc(sizeof(struct node));
			temp -> x = x;
			temp -> next = NULL;
			r -> next = temp;
			return r;
		}		
	}

}
int main(void)
{
	struct node * root;
	root = (struct node*)malloc(sizeof(struct node));
	root -> x = 20;
	for(int i = 1 ; i < 5 ; i++)
	{
		insert(root, i * 10);	
	}

	print(root);

	printf("\n\n");
	struct node * iter;
	iter = (struct node*)malloc(sizeof(struct node));
	iter = root;

	for(int  i = 0; i < 2; i++)
		iter = iter -> next;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> x = 50;
	print(root);
	free(temp);	
	return (0);
}
