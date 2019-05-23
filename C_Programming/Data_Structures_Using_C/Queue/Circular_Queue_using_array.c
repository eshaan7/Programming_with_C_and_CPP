/*  Programmers' name: Eshaan Bansal (41816401518)
    Date: 04/04/2019
    Topic: 10. Write a program to implement circular queue using array
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int A[MAX_SIZE];
int rear=-1;
int front=-1;

void enqueue()
{
    if ( (rear>=MAX_SIZE-1 && front==0) || rear==front-1) {
        printf("\n\tenqueue() failed: Circular queue is full.\n");
        return;
    }
    int x;
    printf("\n\tEnter element: ");
    scanf("%d", &x);
    if (front==-1 && rear==-1) {
        front=rear=0;
        A[rear]=x;
    }
    else if (rear==MAX_SIZE-1) {
        rear=0;
        A[rear]=x;
    }
    else
        A[++rear]=x;
}

void dequeue()
{
    if (front==-1) {
        printf("\n\tdequeue() failed: Circular queue is empty.\n");
        return;
    }
    printf("\n\tDeleted element: %d\n", A[front]);
    if (front==rear)
        front=rear=-1;
    else if (front == MAX_SIZE-1)
        front=0;
    else
        front++;
}

void print_queue()
{   
    if (front==-1) {
        printf("\nprint_queue() failed: Circular queue is empty.\n");
        return;
    }
    int i=front;
    do {
        if (i==front)
            printf("\n\tfront-> %d", A[i]);
        else
            printf("\n\t%9d", A[i]);
        i=(i+1)%MAX_SIZE;
    } while (i!=rear);
    printf("\n\trear-> %2d\n\n", A[i]);       
}

void queueFront() 
{ 
    if (front == -1) { 
        printf("\n\tqueueFront failed: Circular queue is Empty\n"); 
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
	printf("\n\t3. Print Circular queue");
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
        case 4:
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
   