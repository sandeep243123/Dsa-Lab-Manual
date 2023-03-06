#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *link;
	int data;
};
struct node *head=NULL,*temp=NULL,*end=NULL;
void insert(int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->link=NULL;
	if(head==NULL)
	{
		head=t;
		end=head;
	}else{
		end->link=t;
		end=end->link;
	}
	end->link=head;
}
void show()
{
	temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->link;
	}while(temp!=head);
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
	
	
}
