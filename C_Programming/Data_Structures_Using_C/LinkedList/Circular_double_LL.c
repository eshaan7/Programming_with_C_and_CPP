/*  Programmers' name: Eshaan Bansal (41816401518)
    Topic: 15. Write a program to implement doubly circular linked list: Insertion Deletion Search and Traversal.
*/

#include<stdio.h> 
#include<stdlib.h>

struct Node 
{ 
	int data; 
	struct Node *next; 
	struct Node *prev; 
}; 

// Function to insert at the end 
void insertEnd(struct Node** start, int value) 
{ 
	// If the list is empty, create a single node 
	if (*start == NULL) 
	{ 
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*)); 
		new_node->data = value; 
		new_node->next = new_node->prev = new_node; 
		*start = new_node; 
		return; 
	} 

	struct Node *last = (*start)->prev; 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*)); 
	new_node->data = value; 
	new_node->next = *start; 
	(*start)->prev = new_node; 
	new_node->prev = last; 
	last->next = new_node; 
} 

// Function to insert Node at the beginning 
// of the List 
void insertBegin(struct Node** start, int value) 
{ 
	struct Node *last = (*start)->prev; 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*)); 
	new_node->data = value; // Inserting the data 
	new_node->next = *start; 
	new_node->prev = last; 
	last->next = (*start)->prev = new_node; 
	*start = new_node; 
} 

// Function to insert node with value as value1. 
// The new node is inserted after the node with 
// with value2 
void insertAfter(struct Node** start, int value1, 
									int value2) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*)); 
	new_node->data = value1; // Inserting the data 

	// Find node having value2 and next node of it 
	struct Node *temp = *start; 
	while (temp->data != value2) 
		temp = temp->next; 
	struct Node *next = temp->next; 

	// insert new_node between temp and next. 
	temp->next = new_node; 
	new_node->prev = temp; 
	new_node->next = next; 
	next->prev = new_node; 
} 

// Function to delete a given node from the list 
void deleteNode(struct Node **start, int key) 
{ 
    // If list is empty 
    if (*start == NULL) 
        return; 
    // Find the required node 
    // Declare two pointers and initialize them 
    struct Node *curr = *start, *prev_1 = NULL; 
    while (curr -> data != key) 
    { 
        // If node is not present in the list 
        if (curr->next == *start) { 
            printf("\nList doesn't have node with value = %d", key); 
            return; 
        } 
        prev_1 = curr; 
        curr = curr -> next; 
    } 
  
    // Check if node is the only node in list 
    if (curr -> next == *start && prev_1 == NULL) { 
        (*start) = NULL; 
        free(curr); 
        return; 
    } 
  
    // If list has more than one node, 
    // check if it is the first node 
    if (curr == *start) { 
        // Move prev_1 to last node 
        prev_1 = (*start) -> prev; 
  
        // Move start ahead 
        *start = (*start) -> next; 
  
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = *start; 
        (*start) -> prev = prev_1; 
        free(curr); 
    } 
    else if (curr->next == *start) { // check if it is the last node 
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = *start; 
        (*start) -> prev = prev_1; 
        free(curr); 
    } 
    else { 
        // create new pointer, points to next of curr node 
        struct Node *temp = curr -> next; 
  
        // Adjust the pointers of prev_1 and temp node 
        prev_1 -> next = temp; 
        temp -> prev = prev_1; 
        free(curr); 
    } 
} 

void display(struct Node* start) 
{ 
	struct Node *temp = start; 

	printf("\nTraversal in forward direction \n"); 
	while (temp->next != start) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
	printf("%d ", temp->data); 

	printf("\nTraversal in reverse direction \n"); 
	struct Node *last = start->prev; 
	temp = last; 
	while (temp->prev != last) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->prev; 
	} 
	printf("%d ", temp->data); 
} 

int searchList(struct Node* start, int key) 
{ 
	struct Node *temp = start; 

	printf("\nTraversal in forward direction \n"); 
	while (temp->next != start) { 
		if (temp->data==key)
			return 1;
		temp = temp->next;
	}
	return -1;
} 

int main() 
{ 
	int choice=0, x=0, i=0;
	struct Node* start = NULL;  
	printf("-------MENU-------");
	printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert after element");
    printf("\n 4 - Delete an element");
    printf("\n 5 - Traversal list");
    printf("\n 6 - Search for element");
    printf("\n------------------");
    while (1)
    {
    printf("\n\tEnter Choice(1-6): ");
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1:
    		printf("\nEnter element to insert: ");
    		scanf("%d", &x);
			insertBegin(&start, x); 
			break;

		case 2:
			printf("\nEnter element to insert: ");
    		scanf("%d", &x);
			insertEnd(&start, x); 
			break;

		case 3:
			printf("\nEnter element to insert: ");
    		scanf("%d", &x);
			printf("\nelement to insert after: ");
    		scanf("%d", &i);
			insertAfter(&start, x, i); 
			break;

		case 4:
			printf("\nEnter element to delete: ");
    		scanf("%d", &x);
    		deleteNode(&start, x);
    		break;

		case 5:
			printf("Created circular doubly linked list is: "); 
			display(start); 
			break;

		case 6:
			printf("\nEnter element to search: ");
    		scanf("%d", &x);
			(searchList(start, x))?printf("\n\tElement Found!"):printf("\n\tElement not found!");
			break;
			
		default:
    		printf("\nInvalid option. Try again\n");
    		break;
    }
	}
	return 0; 
} 
