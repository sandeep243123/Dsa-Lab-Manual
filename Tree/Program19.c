#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};

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
void trippleOrder (struct node *root)
{
  if (root != NULL)
    {
      printf ("%d ", root->data);
      trippleOrder (root->left);
      printf ("%d ", root->data);
      trippleOrder (root->right);
      printf ("%d ", root->data);
    }
}

void doubleOrder (struct node *root)
{
  if (root != NULL)
    {
    	printf ("%d ", root->data);
      doubleOrder (root->left);
    	printf ("%d ", root->data);
	  doubleOrder (root->right);
    }
}
int main ()
{ 
  struct node *root = NULL;
  root = insert (root, 9);
  insert (root, 7);
  insert (root, 5);
  insert (root, 8);
  insert (root, 14);
  insert (root, 11);
  insert (root, 16);
  printf ("The doubleOrder is :\n");
  doubleOrder (root);
  printf ("\nThe trippleOrder is :\n");
  trippleOrder (root);
  return 0;
}
