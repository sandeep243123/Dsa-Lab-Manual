#include<stdio.h>
#define MAXSIZE 5
int arr[MAXSIZE];
int size=0;
void push(int d)
{
	if(size<MAXSIZE)
	{
		arr[size]=d;
		size++;
	}else{
		printf("Overflow\n");
	}
}
void pop(){
	if(size<0)
	{
		printf("Underflow\n");
	}else{
		printf("%d ",size);
		size--;
		printf("%d is poped\n",arr[size]);
		
	}
}
void main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
}
