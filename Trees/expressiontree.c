/*
The expression tree is a binary tree in which each internal node corresponds to the operator and each leaf node corresponds to the operand 
so for example expression tree for 3 + ((5+9)*2) would be:

                 +
                / \
               3   *
                  / \
                 +   2
               /  \
              5    9
                  
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
    struct node* next;
};
 struct node *head=NULL;
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
     
    return (node); 
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    
    else{
        // printf("%d ", node->data);
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%c ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
    }
}

void push(struct node *x)
{
    if(head == NULL)
        head =x;
    else {
        x->next =head;
        head = x;
    }
}

struct node *pop()
{
    struct node *p = head;
    head = head->next;
    return p;
    
}


int main()
{
    char s[10] = "ABC*+D/";
    int l = strlen(s);
    struct node *x, *y, *z;
    for (int i = 0; i < l; i++)
    {
        if(s[i] == '\0')
           break;
        else if(s[i] == '+' || s[i] == '-' || s[i] =='*' || s[i] == '/' || s[i] == '^')
        {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);  
        }
        else {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf(" The Inorder Traversal of Expression Tree: ");
    // printf("\n%d",z->data);
    printInorder(z);
    // free(z);
    return 0;
}