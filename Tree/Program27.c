#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *createNode(int data) {
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
 	n->right = NULL;
  	n->left = NULL;
	return n;
 }
int height(struct node *);
int main()
{
struct node *r= createNode(5);
struct node *r1 = createNode(3);
struct node *r2 = createNode(10);
struct node *r3 = createNode(2);
struct node *r4 = createNode(4);
struct node *r5 = createNode(8);
struct node *r6 = createNode(12);
r->left = r1; r->right = r2;
r1->left = r3;
r1->right = r4;
r2->left = r5;
r2->right = r6;
printf("height is : %d",height(r));
return 0; }
int height(struct node *t) {
if(!t)
return 0;
if((!(t->left)) && (!(t->right)))
return 0;
int l,r;
l = height(t->left);
r = height(t->right);
return (1 + ((l>r)?l:r));
}
