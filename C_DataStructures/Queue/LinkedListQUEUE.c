/*	Author's name: Eshaan Bansal
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    if (!temp) return;
    temp->data=x;
    temp->next=NULL;
    if (front==NULL && rear==NULL) {
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void dequeue()
{
    if (front==NULL) {
        printf("\n\tDequeue failed: Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    if (front==rear)
        front=rear=NULL;
    else
        front = front->next;
    free(temp);
}

void print_queue()
{
    if (front==NULL) {
        printf("\n\print_queue failed: Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    while (temp!=NULL) {
        if (temp==front)
            printf("\n\tfront-> %d", temp->data);
        else if (temp==rear)
            printf("\n\trear-> %2d", temp->data);
        else
            printf("\n\t%9d", temp->data);
        temp=temp->next;
    }
}

int print_front() {
	if(front == NULL) {
		printf("\n\tprint_front failed: Queue is empty\n");
		return;
	}
	printf("\n\tfront-> %d",front->data);
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
                printf("\n\tEnter element to push: ");
                scanf("%d", &x);
				enqueue(x);
				break;
		case 2: //
			    dequeue();
				break;
		case 3: //
				print_queue();
				break;
        case 4:
                print_front();
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
   