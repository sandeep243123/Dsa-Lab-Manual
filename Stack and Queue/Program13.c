#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct node
{
	struct node *link;
	int data;
};
struct node *head=NULL,*temp=NULL;
void enqueue(int d)
{
	struct node *t=(struct node *)malloc(sizeof(struct node));
	t->data=d;
	if(head==NULL)
	{
		head=t;
		temp=t;
	}else{
		temp->link=t;
		temp=t;
	}
	t->link=head;
}
void dequeue()
{
	struct node *f;
	if(temp==head)
	{
		printf("Empty queue\n");
	}else{
		f=temp->link;
		head=head->link;
		temp->link=head;
		printf("%d is dequeued\n",f->data);
		free(f);
	}
	
}
void poll()
	{
		printf("%d\n",head->data);
	}


void main()
{
	int i;
		for(i=0;i<8;i++)
		{
			enqueue(i);
		}
		dequeue();
		dequeue();
		dequeue();
		dequeue();
		dequeue();
		poll();
}
