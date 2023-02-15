#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int size=0;
struct node* insertAtFirst(struct node *head,int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=data;
	temp->next=head;
	size++;
	return temp;
}
void Display(struct node *head){
	if(head==NULL)
	printf("List is Empty\n");
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
struct node* insertAtLast(struct node *head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=data;
	struct node *t=head;
	size++;
	if(head==NULL)
	{
		head=insertAtFirst(head,data);
		return head;
	}else{
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=temp;
		return head;
	}
}

struct node* insertAtPos(struct node *head,int data,int pos)
{
	if(size==0&&pos==1)
	{
		return insertAtFirst(head,data);
	}else if(pos<size||pos>size)
	{
		printf("Invalid Postion");
		return head;
	}
	if(pos==1)
	return insertAtFirst(head,data);
	else if(size==pos)
	{
		return insertAtLast(head,data);
	}else{
		struct node *t=(struct node*)malloc(sizeof(struct node));
		t->data=data;
		t->next=NULL;
		struct node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=t;
		size++;
	}
	return head;
}
struct node* deleteAtFirst(struct node* head)
{
	if(head==NULL){
	    printf("List is empty\n");
	return head;
	}
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	size--;
	return head;
}
struct node* deleteAtLast(struct node *head){
	if(head==NULL||head->next==NULL){
	return deleteAtFirst(head);
	}
	struct node *temp=head;
	struct node *t=head;
	while(temp->next->next!=NULL)
	temp=temp->next;
	t=temp;
	temp=temp->next;
	t->next=NULL;
	free(temp);
	size--;
	return head;
	
}
void main(){
	int ch,i,n,data,pos;
	struct node *head=NULL;
	while(1){
		printf("********************************\n");
		printf("1.Insert At first\n");
		printf("2.Insert At last\n");
		printf("3.Insert At given Postion\n");
		printf("4.Delete At first\n");
		printf("5.Delete At last\n");
		printf("6.Display\n");
		printf("7.Exit\n");
		printf("********************************\n");
		printf("Enter the choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the value\n");
			scanf("%d",&data);
			head=insertAtFirst(head,data);
			break;
			case 2:
			printf("Enter the value\n");
			scanf("%d",&data);
			head=insertAtLast(head,data);
			case 3:
			printf("Enter the value\n");
			scanf("%d",&data);
			printf("Enter the position\n");
			scanf("%d",&pos);
			insertAtPos(head,data,pos);	
			break;
			case 4:
				head=deleteAtFirst(head);
				break;
			case 5:
				head=deleteAtLast(head);
				break;
			case 6:
			Display(head);
			break;
			case 7:
			exit(1);				
			default: printf("Invalid Choice\n");
		}
	}
	
}
