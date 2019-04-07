/*  Programmers' name: Eshaan Bansal (41816401518)
    Topic: 13. Write a program to implement doubly linked list: Insertion Deletion Search and Traversal.
*/

#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
	struct Node* prev; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	new_node->prev = NULL; 
	/* change prev of head node to new node */
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data) 
{ 
	/* check if the given prev_node is NULL */
	if (prev_node == NULL) { 
		printf("the given previous node cannot be NULL"); 
		return; 
	} 

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = prev_node->next; 
	prev_node->next = new_node; 

	/* Make prev_node as previous of new_node */
	new_node->prev = prev_node; 

	/* Change previous of new_node's next node */
	if (new_node->next != NULL) 
		new_node->next->prev = new_node; 
} 

void append(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	struct Node* last = *head_ref;
	new_node->data = new_data; 

	/* This new node is going to be the last node, so 
		make next of it as NULL*/
	new_node->next = NULL;

	/* If the Linked List is empty, then make the new 
		node as head */
	if (*head_ref == NULL) { 
		new_node->prev = NULL; 
		*head_ref = new_node; 
		return; 
	} 

	/* Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* Change the next of last node */
	last->next = new_node; 

	/* Make last node as previous of new node */
	new_node->prev = last; 

	return; 
} 

/* Function to delete a node in a Doubly Linked List. 
   head_ref --> pointer to head node pointer. 
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return; 
  
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
}

// This function prints contents of linked list starting from the given node 
void printList(struct Node* node) 
{ 
	struct Node* last; 
	printf("\nTraversal in forward direction \n"); 
	while (node != NULL) { 
		printf(" %d ", node->data); 
		last = node; 
		node = node->next; 
	} 

	printf("\nTraversal in reverse direction \n"); 
	while (last != NULL) { 
		printf(" %d ", last->data); 
		last = last->prev; 
	} 
} 

void searchList(struct Node* node, int data) 
{
	while (node != NULL) { 
		if (data==node->data) {
			printf("Element found: %d", node->data);
			break;
		}
		node = node->next; 
	} 	
}

int main() 
{ 
	int choice=0, x=0;
	struct Node* head = NULL; 
	printf("-------MENU-------");
	printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert at position i");
    printf("\n 4 - Delete at i");
    printf("\n 5 - Traversal");
    printf("\n 6 - Search for element");
    printf("\n------------------");
    while (1)
    {
    printf("\n\tEnter Choice(1-6): ");
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1: //
    		printf("\nEnter element to push: ");
    		scanf("%d", &x);
    		append(&head, x); 
    		break;
    	case 2:
    		printf("\nEnter element to push: ");
    		scanf("%d", &x);
    		push(&head, x); 
    		break;
    	case 3:
    		printf("\nEnter element to push: ");
    		scanf("%d", &x);
    		insertAfter(head->next, x); 
    		break;
    	case 4:
    		deleteNode(&head, head);
    		break;
    	case 5:
    		printList(head);
    		break;
    	case 6:
    		printf("\nEnter element to search: ");
    		scanf("%d", &x);
    		searchList(head, x);
    		break;
    	default:
    		printf("\nInvalid option. Try again\n");
    		break;
    }
	}
	return 0; 
} 
