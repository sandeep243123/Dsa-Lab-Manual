#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct node
{
	struct node *link;
	int data;
};
struct node *head=NULL,*temp=NULL;
void push(int d)
{
	struct node *t=(struct node *)malloc(sizeof(struct node));
	if(!t){
		printf("Memory Not alloctaed\n");
	}
	t->data=d;
	t->link=head;
	head=t;
}
void pop()
{
	struct node *f;
	if(!head)
	{
		printf("Underflow\n");
	}else{
	f=head;
	printf("%d poped\n",head->data);
	head=head->link;
	free(f);
	}
}


void main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
}
