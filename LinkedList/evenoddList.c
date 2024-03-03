/**
 * 
 * 
 * Given a Linked List of integers, write a function to modify the linked list such that all odd numbers appear before 
 * all the even numbers in the modified linked list.
 * 
 * **/


#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


void oddEven(Node **head)
{
    Node *odd=NULL, *even=NULL, *even_head=NULL, *odd_head=NULL;
    Node *node = *head;

    while(node !=  NULL)
    {
        if(node->data % 2)
        {
            if(!odd)
            {
              odd=node;
              odd_head=node;
            }
            else{
                odd->next=node;
                odd=odd->next;
            }   
        }
        else {
            if(!even)
            {
                even=node;
                even_head=node;
            }
            else {
                even->next=node;
                even=even->next;
            }
        }
        
        node=node->next;
    }
    even->next=NULL;
    odd->next=even_head;
   
    if(odd_head)
      *head = odd_head;
    else 
      *head = even_head;
    return;    
}

void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list of the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
}

void printList(Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    /* Let us create a sample linked list as following 
      0->2->4->6->8->10->11 */
  
    push(&head, 11);
    push(&head, 10); 
    push(&head, 8); 
    push(&head, 6);
    push(&head, 13);   
    push(&head, 4); 
    push(&head, 2); 
    push(&head, 0); 

    printf("\nOriginal Linked list \n"); 
    printList(head);
    printf("\n");
    oddEven(&head); 

    printf("\nModified Linked list \n"); 
    printList(head);

}



