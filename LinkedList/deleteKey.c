/***

Given a singly linked list, delete all occurrences of a given key in it. For example, consider the following list.

Example:

Input: 2 -> 2 -> 1 -> 8 -> 2 ->  3 -> 2 -> 7
       Key to delete = 2
Output:  1 -> 8 -> 3 -> 7


Asked in Arista Networks

**/







// C Program to delete all occurrences of a given key in 
// linked list 
#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
typedef struct Node { 
	int data; 
	struct Node* next; 
} Node; 

/* Given a reference (pointer to pointer) to the head of a 
list and an int, inserts a new node on the front of the 
list. */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node 
		= (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Given a reference (pointer to pointer) to the head of a 
list and a key, deletes all occurrence of the given key 
in linked list */
Node* deleteKey(Node* head, int x) 
{ 
	if (!head) 
		return head; 
	// Until the head data is equal to the key move the head 
	// pointer 
	while (head && head->data == x) 
		head = head->next; 
	Node *curr = head, *prev = NULL; 
	while (curr) { 
		if (curr->data == x) 
			prev->next = curr->next; 
		else
			prev = curr; 
		curr = curr->next; 
	} 
	return head; 
} 

// This function prints contents of linked list starting 
// from the given node 
void printList(Node* node) 
{ 
	while (node != NULL) { 
		printf(" %d ", node->data); 
		node = node->next; 
	} 
} 

// Driver code 
int main() 
{ 
	// Start with the empty list 
	struct Node* head = NULL; 

	push(&head, 7); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 8); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 2); 

	int key = 2; // key to delete 

	puts("Created Linked List: "); 
	printList(head); 

	// Function call 
	head = deleteKey(head, key); 
	if (!head) 
		printf("\nNo element present in the Linked list\n"); 
	else { 
		printf("\nLinked List after Deletion is:\n"); 
		printList(head); 
	} 
	return 0; 
}
