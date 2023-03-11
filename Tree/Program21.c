#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};
void A(struct node*);
void B(struct node*);
void C(struct node*);
struct node *newNode (int item)
{
  struct node *temporary = (struct node *) malloc (sizeof (struct node));
  temporary->data = item;
  temporary->left = temporary->right = NULL;
  return temporary;
}

struct node *insert (struct node *node, int data)
{
  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else if (data > node->data)
    node->right = insert (node->right, data);
  return node;
}
void A(struct node *root)
{
  if (root != NULL)
    {
    	printf ("%d ", root->data);
      B(root->left);
	  B(root->right);
    }
}
void B(struct node *root)
{
  if (root != NULL)
    {
    	printf("%d ",root->data);
	 	A(root->left);
	  	A(root->right);
    }
}

int main ()
{ 
  struct node *root = NULL;
  root = insert (root, 1);
  insert (root, 2);
  insert (root, 3);
  insert (root, 4);
  insert (root, 5);
  insert (root, 6);
  insert (root, 7);
  insert (root, 8);
  insert (root, 9);
  insert (root, 10);
  insert (root, 11);
  insert (root, 12);
  insert (root, 13);
  insert (root, 14);
  printf ("The preOrder is :\n");
  A(root);
  
  return 0;
}
