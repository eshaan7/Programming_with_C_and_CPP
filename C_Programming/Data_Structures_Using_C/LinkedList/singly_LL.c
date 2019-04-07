/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 12. Write a program to implement singly linked list: Insertion Deletion Search and Traversal.
*/

#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

struct Node *head = NULL;

// inserts a new node on the front of the list 
void push(int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; // assign new_data
	new_node->next = head; // make new_node point to previous head node
	head = new_node; // move the head to point to the new node
} 

/* Given the position of new node, find prev_node, insert a new node after this 
prev_node */
void insertAtnthpos(int new_data, int n) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; // assign new_data
	if (n == 1) { 
		new_node->next = head; // make new_node point to previous head node
		head = new_node;
		return; 
	} 
	struct Node* prev_node = head;
	for (int i=0; i<(n-2); i++)
		prev_node = prev_node->next;
	/* here, prev_node is node at (n-1)th position */
	/* Make next of new node as next of prev_node */
	new_node->next = prev_node->next; 

	/* move the next of prev_node as new_node */
	prev_node->next = new_node; 
} 

/* Appends a new node at the end */
void append(int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; // assign new_data
	new_node->next = NULL; // make new_node point to NULL
	/* check if list is empty i.e. head is NULL */
	if (head == NULL) { 
		head = new_node; 
		return; 
	}
	/* Else traverse till the last node */
	struct Node* last = head;
	while (last->next != NULL) 
		last = last->next; 
	/* Change the next of last node */
	last->next = new_node; 
	return; 
} 

// This function prints contents of linked list starting from head
void printList() 
{ 
	struct Node* node = head;
	while (node != NULL) { 
		printf("[%d]->", node->data); 
		node = node->next; 
	}
	printf("NULL\n\n"); 
} 

int main() 
{ 
	// Insert 6. So linked list becomes 6->NULL 
	append(6); 
	// Insert 7 at the beginning. So linked list becomes 7->6->NULL 
	push(7); 
	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
	push(1); 
	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
	append(4); 
	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
	insertAtnthpos(8, 3); 
	printf("\nCreated Linked list is: "); 
	printList(); 
	return 0; 
} 
