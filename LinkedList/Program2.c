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
void sort()
{
	struct node *t1,*t2;
	t1=head;
	while(t1)
	{
		t2=head;
		while(t2)
		{
			int temp=t1->data;
			if(t1->data<t2->data){
				t1->data=t2->data;
				t2->data=temp;
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
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
	sort();
	show();
}
