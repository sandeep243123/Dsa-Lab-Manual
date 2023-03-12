#include<stdio.h>
#include<stdlib.h>
long fact(int n)
{
	if(n==1)
	return 1;
	return n*fact(n-1);
}
void main(){
	int bt;
	int n=6;
	bt=fact(2*n)/fact(n+1);
	printf("Total binaty tree: %d",bt);
}
