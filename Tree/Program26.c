#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};
void A(struct node*);
int count=0;
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
    	if(root->left!=NULL&&root->right!=NULL)
    	{
    		count++;
		}
      A(root->left);
	  A(root->right);
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
  A(root);
  printf("Non full node is %d\n",count);
  return 0;
}
