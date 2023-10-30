/**

  Print Left view of Binary tree
 
                  4
                /   \
               5     2
                   /   \
                  3     1
                /   \
               6     7

    Output = 4 5 3 6           
 **/


// C program to print left view of Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

 
// A utility function to create a new Binary Tree node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewUtil(struct node *root, int level, int *maxLevel)
{
    if (root== NULL)
        return ;
    if(level > *maxLevel)
    {
        printf("%d ",root->data);
        *maxLevel = level;
    } 
     
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);

}

void leftView(struct node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}


// Main function call
int main()
{
    struct node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    leftView(root);
 
    return 0;
}