#ifndef stack_ll
#define stack_ll
struct node{
	int data;
	struct node * next;
};

int pop(struct node*);
struct node * push(struct node*,int);
#endif
