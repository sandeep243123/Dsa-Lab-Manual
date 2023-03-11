#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE];
int front=-1,rear=-1;
int isEmpty(){
	if((front==rear+1)||(front==0&&rear==SIZE-1))
	return 1;
	return 0;
}
int isFull(){
	if(front==-1)
	return 1;
	return 0;
}
void enqueue(int d)
{
	if(isFull())
	{
		printf("queue is full");	
	}else{
		if(front==-1)
		front=0;
		rear=(rear+1)%SIZE;
		arr[rear]=d;
		printf("Element %d is inserted\n",d);
	}
}
int dequeue()
{
	int d;
	if(isEmpty())
	{
		printf("queue is Empty\n");
		return -1;
	}else{
	d=arr[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}else{
		front=(front+1)%SIZE;
	}
	printf("Deleted element is %d",d);
	return d;
}
}
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", arr[i]);
    }
    printf("%d ", arr[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
void main()
{
	dequeue();
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);

  display();
  dequeue();

  display();

  enqueue(7);
  display();

}
