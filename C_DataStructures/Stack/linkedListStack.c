/*	Author's name: Eshaan Bansal
	Linked list implementation of stack
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Node* top = NULL;

void push()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (!temp) {
        printf("\nHeap Overflow"); 
        exit(1); 
	}
	int x;
	printf("\nPlease enter new element: ");
	scanf("%d", &x);	
	temp->data=x;
	temp->link=top;
	top=temp;
}

void pop()
{
	if (top!=NULL) {
		struct Node *temp = top;
		top=top->link;
		temp->link=NULL;
		printf("\nDeleted element: %d\n", temp->data);
		free(temp);
		//or top=top->link;
	}
	else {
		printf("\nStack underflow.\n");
	}
}

void print_stack()
{
	if (top == NULL) { 
        printf("\nStack Underflow\n"); 
        exit(1); 
    } 
	struct Node *temp = top;
	printf("Stack:");
	while (temp!=NULL) { 
		// print node data 
		if (temp==top)
			printf("\n\ttop-->%d", temp->data);
		else
			printf("\n\t%7d", temp->data);
		// assign temp link to temp 
		temp=temp->link; 
	}
	printf("\n");
}

int main()
{
	//unsigned char cchoice='0';
	int choice;
	do {
	choice=0;
	//system("clear");
	printf("\n\t--------MENU--------");
	printf("\n\t1. Push element");
	printf("\n\t2. Pop element");
	printf("\n\t3. Print stack");
	printf("\n\t4. Exit");
	printf("\n\t--------------------");
	printf("\n\n\t\tEnter choice(1-4): ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: //
				push();
				break;
		case 2: //
				pop();
				break;
		case 3: //
				print_stack();
				break;
		case 4: //
				exit(0);
				break;
		default:
				printf("\nInvalid input. Please try again.\n\n");
				break;

	}
	} while (1);
	return 0;
}
