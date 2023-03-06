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
void check()
{
	struct node *t1,*t2;
	t1=head;
	int f=1;
	while(t1)
	{		
		if(f==1){
			t2=t1;
			while(t2){
				if((t2->data)<(t1->data)){
					f=0;
					break;
				}
				t2=t2->link;
			}
		}else{
			break;
		}
		t1=t1->link;	
	}
	if(f==1)
	printf("Non-decreasing order");
	else
	printf("Not in non-decreasong order");
}

void main()
{
	int arr[]={1,2,3,5,6,7};
	int i=0;
	for(i=0;i<6;i++){
		insert(arr[i]);
	}
	check();

	
}
