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
void mov()
{
	struct node *t;
	temp=head;
	while(temp->link->link)
	{
		temp=temp->link;
	}
	t=temp->link;
	temp->link->link=head->link;
	temp->link=head;
	head->link=NULL;
	head=t;
}
void show()
{
	
	if(head)
	{
		printf("%d ",head->data);
		head=head->link;
		show();
	}
}
void main()
{
	int arr[]={3,2,5,4,8,6,9};
	int i=0;
	for(i=0;i<7;i++){
		insert(arr[i]);
	}
	show();
	
}
