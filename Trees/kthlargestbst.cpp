// C++ program to find k'th largest element in BST
#include<bits/stdc++.h>
using namespace std;


typedef struct Node {
    int key;
    struct Node *left, *right;
}Node;

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void kthLargestElemBST(Node *root, int k, int &c)
{
    if (root == NULL || c >= k )
        return ; 
    kthLargestElemBST(root->right, k, c);
    c++;

    if (c == k)
    {
        cout << "kth largest element for k = "<< k << " is " << root->key<<endl;
        return;
    }

    kthLargestElemBST(root->left, k, c);
}

Node *insert(Node *node, int val)
{
    if(node == NULL)
        return newNode(val);
    
    if (val < node->key)
        node->left = insert(node->left, val);
    else if(val > node->key)
        node->right = insert(node->right, val);
    
    return node;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int c = 0, k=3;
    kthLargestElemBST(root, k , c);

    return 0;
}       