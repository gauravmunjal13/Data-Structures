#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

struct node* newNode(int data);
void iterativePreorder1(node *root);
void iterativePreorder2(node *root);

using namespace std;

/* node structure */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* **** Private Functions **** */
int main( void )
{
    /* Constructed binary tree is
           1
          / \
         2   3
        / \   \
       4   5   6
        \
         7
    */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right= newNode(6);
  //root->left->left->left  = newNode(7);
  iterativePreorder1(root);
  iterativePreorder2(root);

  return 0;
}

/* **** Utility Functions **** */

/* To create new node */
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/*  Method 1 */
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder1(node *root)
{
    // Base Case
    if (root == NULL)
       return;

    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}


/* Method 2 */
void iterativePreorder2(node *root)
{
    // Base Case
    if (root == NULL)
       return;

    stack<node *> nodeStack; // create stack

    printf("\n Pre-Order Traversal \n");
    while(1){
        printf("%d ",root->data); // print the data

        if( root->left != NULL ){ //if left child is there proceed with the it and push the right child
            if( root->right != NULL )
                nodeStack.push(root->right);
            root = root->left;
        }
        else if( root->right != NULL){
            root = root->right;
        }
        else{ // if left child is NULL, go with the right child from stack
            if( nodeStack.empty() == true )
                break;
            root = nodeStack.top();
            nodeStack.pop();
        }
    }

    return;
}
