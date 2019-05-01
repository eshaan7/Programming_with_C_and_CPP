/*	Programmers' name: Eshaan Bansal (41816401518)
  	Date: 04/04/2019
	Topic: 8. Write a program to implement queue using array.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int A[MAX_SIZE];
int rear=-1;
int front=-1;

void enqueue()
{
    if (rear>=MAX_SIZE-1) {
        printf("\n\tenqueue() failed: Queue is full.\n");
        return;
    }
    int x;
    printf("\n\tEnter element: ");
    scanf("%d", &x);
    if (front==-1 && rear==-1) {
        front=rear=0;
        A[rear]=x;
    }
    else
        A[++rear]=x;
}

void dequeue()
{
    if (front==-1) {
        printf("\n\tdequeue() failed: Queue is empty.\n");
        return;
    }
    printf("\n\tDeleted element: %d\n", A[front]);
    if (front==rear)
        front=rear=-1;
    else
        front++;
}

void print_queue()
{   
    if (front==-1) {
        printf("\n\tprint_queue() failed: Queue is empty.\n");
        return;
    }
    for (int i=front; i<=rear; i++) {
        if (i==front)
            printf("\n\tfront-> %d", A[i]);
        else if (i==rear)
            printf("\n\trear-> %2d", A[i]);
        else 
            printf("\n\t%9d", A[i]);
    }
    printf("\n\n");    
}

void queueFront()
{ 
    if (front == -1) { 
        printf("\n\tqueueFront() failed: Queue is Empty\n"); 
        return; 
    } 
    printf("\nFront Element is: %d", A[front]);
}

int main()
{
    int choice=0;
	do {
	choice=0;
	//system("clear");
	printf("\n\t--------MENU--------");
	printf("\n\t1. Push element");
	printf("\n\t2. Pop element");
	printf("\n\t3. Print queue");
    printf("\n\t4. Print element at front");
	printf("\n\t5. Exit");
	printf("\n\t--------------------");
	printf("\n\n\t\tEnter choice(1-4): ");
	scanf("%d", &choice);
    int x;
	switch(choice)
	{
		case 1: //
			enqueue();
			break;
		case 2: //
			dequeue();
			break;
		case 3: //
			print_queue();
			break;
        case 4: //
        	queueFront();
        	break;
		case 5: //
			exit(0);
			break;
		default:
			printf("\nInvalid input. Please try again.\n\n");
			break;
	}
	} while (1);
	return 0;
}
   
