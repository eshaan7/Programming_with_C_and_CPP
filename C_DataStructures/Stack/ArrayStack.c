/*	Author's name: Eshaan Bansal
	Array implementation of stack
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int A[MAX_SIZE];
int top=-1;

void push()
{
	if (top == MAX_SIZE-1) {
		printf("Error: stack overflow\n");
		return;
	}
	int x;
	printf("\nPlease enter new element: ");
	scanf("%d", &x);
	A[++top]=x;
}

void pop()
{
	if (top==-1) {
		printf("Error: stack underflow\n");
		return;
	}
	else
		top--;
}

int retTop() 
{
	return A[top];
}

int isEmpty(struct stack *s) 
{ 
    return s->top == -1 ; 
}

void print_stack()
{
	int i;
	printf("Stack:");
	for (i=top; i>=0; i--) {
		if (i==top)
			printf("\n\ttop-->%2d",A[i]);
		else
			printf("%8d\n",A[i]);
	}
	printf("\n");
}

int main()
{
	//unsigned char choice='0';
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
