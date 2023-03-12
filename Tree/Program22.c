#include<stdio.h>
#include<stdlib.h>
long fact(int n)
{
	if(n==1)
	return 1;
	return n*fact(n-1);
}
void main(){
	int l,ul;
	int n=3;
	l=(fact(2*n)*fact(n))/(fact(n)*fact(n)*(n+1));
	printf("Labelled binary tree: %d\n ",l);
	ul=l/fact(n);
	printf("Unlabelled binary tree: %d",ul);
}
