#include<stdio.h>
#include<Stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head=NULL,*temp=NULL;
void insert(int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
		temp=t;		
	}else{
		temp->next=t;
		t->prev=temp;
		temp=temp->next;
	}	
}
void insertAtFirst(int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
		temp=t;
	}else{
		t->next=head;
		head->prev=t;
		head=head->prev;
	}
	
}
void insertAtEnd(int d)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->prev=NULL;
	t->next=NULL;
	if(head==NULL)
	{
		head=t;
		temp=t;
	}else{
		temp=head;
		while(temp->next){
			temp=temp->next;
		}
		t->prev=temp;
		temp->next=t;
	}
}
void insertAtPos(int n,int d)
{
	struct node *f;
	temp=head;
	int c;
	while(temp){
		c++;
		temp=temp->next;
	}
	if(n==1){
		insertAtFirst(d);
	}else if(n==(c+1)){
		insertAtEnd(d);
	}else if(n>(c+1)){
		printf("Invalid pos\n");
	}else{
		temp=head;
		struct node *t=(struct node*)malloc(sizeof(struct node));
		t->data=d;
		while(n>2)
		{
			n--;
			temp=temp->next;
		}
		t->next=temp->next;
		temp->next->prev=t;
		temp->next=t;
		t->prev=temp;
	}
}
void deleteAtFirst(){
	struct node *f;
	if(head==NULL)
	{
		printf("List is Empty");
	}else{
		f=head;
		head=head->next;
		free(f);
	}
}
void deleteAtEnd(){
	struct node *f;
	temp=head;
	if(head==NULL)
	{
		printf("List is Empty");
	}else if(head->next==NULL){
		free(head);
	}else{
		while(temp->next->next){
			temp=temp->next;
		}
		f=temp->next;
		temp->next=NULL;
		free(f);
	}
}
void deleteAtPos(int n)
{
	struct node *f;
	temp=head;
	int c;
	while(temp){
		c++;
		temp=temp->next;
	}
	if(n==1){
		deleteAtFirst();
	}else if(n==(c)){
		deleteAtEnd();
	}else if(n>c){
		printf("Invalid pos\n");
	}else{
		temp=head;
		while(n>2)
		{
			n--;
			temp=temp->next;
		}
		
		f=temp->next;
		temp->next=f->next;
		f->next->prev=temp;
		free(f);
	}
}
void show()
{
	temp=head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
//	while(temp)
//	{
//		printf("%d ",temp->data);
//		temp=temp->prev;
//	}
	printf("\n");
}

void main()
{
	int arr[]={1,2,3,5,6,7};
	int i=0;
	for(i=0;i<6;i++){
		insert(arr[i]);
	}	
	show();
	insertAtFirst(23);
	show();
	insertAtEnd(24);
	show();
	insertAtPos(9,0);
	show();
	deleteAtFirst();
	show();
	deleteAtEnd();
	show();
	deleteAtPos(6);
	show();
}

