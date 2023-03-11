#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
int stack1[MAXSIZE],stack2[MAXSIZE];
int top1,top2,count;
top1=-1;
top2=-1;
count=0;
void push1(int d)
{
	if((top1+1)==MAXSIZE)
	{
		printf("Overflow\n");
	}else{
		top1++;
		stack1[top1]=d;
	}
}
void push2(int d)
{
	if((top2+1)==MAXSIZE)
	{
		printf("Overflow\n");
	}else{
		top2++;
		stack2[top2]=d;
	}
}
int pop1()
{
	if(top1==-1)
	{
		printf("Underflow\n");
	}else{
		int a=stack1[top1];
		top1--;
		return a;
	}
}
int pop2()
{
	if(top2==-1)
	{
		printf("Underflow\n");
	}else{
		int a=stack2[top2];
		top2--;
		return a;
		 
	}
}
void enqueue(int d)
{
	push1(d);
	count++;
}
void dequeue()
{
	if(top1==-1&&top2==-1)
	{
		printf("Queue is Empty\n");
	}else{
		int i;
		for(i=0;i<count;i++)
		{
			int e=pop1();
			push2(e);
		}
		int b=pop2();
		printf("The dequeued element is %d\n",b);
		count--;
		for(i=0;i<count;i++)
		{
			int a=pop2();
			push1(a);
		}
	}
}
void display()  
{  
	int i;
   for(i=0;i<=top1;i++)  
  {  
     printf("%d ",stack1[i]);  
  }  
  printf("\n");
} 
void main()
{
	enqueue(10);  
   	enqueue(20);  
   	enqueue(30);  
   	display(); 
   	dequeue();
   	display();
}
