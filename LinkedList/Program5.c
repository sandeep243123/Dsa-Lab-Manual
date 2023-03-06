#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *link;
	int data;
};
struct node *head=NULL,*temp=NULL;
void insert(int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->link=NULL;
	if(head==NULL)
	{
		head=t;
		temp=head;
	}else{
		temp->link=t;
		temp=temp->link;
	}
}
void rev()
{
	struct node *prev=NULL,*next=NULL;
	while(head)
	{
		next=head->link;
		head->link=prev;
		prev=head;
		head=next;
	}
	head=prev;
}
void show()
{
	temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
void main()
{
	int arr[]={3,2,5,4,8,6,9};
	int i=0;
	for(i=0;i<7;i++){
		insert(arr[i]);
	}
	show();
	rev();
	show();
	
}
