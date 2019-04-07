/*	Programmers' name: Eshaan Bansal (41816401518)
  	Date: 04/04/2019
	Topic: 2. Write a program to implement stack using array.
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

void print_stack()
{
	int i;
	printf("Stack:");
	for (i=top; i>=0; i--) {
		if (i==top)
			printf("\n\ttop-->%2d",A[i]);
		else
			printf("\n\t%8d",A[i]);
	}
	printf("\n");
}

int main()
{
	int choice;
	do {
	choice=0;
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
		case 1: // to push element to top of stack
				push();
				break;
		case 2: // to pop an element from the top of stack
				pop();
				break;
		case 3: // to display a stack
				print_stack();
				break;
		case 4: // exits program
				exit(0);
				break;
		default:
				printf("\nInvalid input. Please try again.\n\n");
				break;

	}
	} while (1);
	return 0;
}
