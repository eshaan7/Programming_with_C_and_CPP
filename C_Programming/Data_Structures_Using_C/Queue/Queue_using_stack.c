#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct stack {
    int A[MAX_SIZE];
    int top;
};

struct queue {
    struct stack s1, s2;
};

// stack ADT operations

void push(struct stack *s, int x)
{
    if (s->top == MAX_SIZE-1) {
        printf("Error: stack overflow\n");
        return;
    }
    (s->A)[++s->top]=x;
}

void pop(struct stack *s)
{
    if (s->top==-1) {
        printf("Error: stack underflow\n");
        return;
    }
    else
        --s->top;
}

int retTop(struct stack *s) 
{
    return (s->A)[s->top];
}

int isEmpty(struct stack *s) 
{
    if (s->top==-1)
        return 1;
    return 0;
}

// Operations on queue with the two stacks

void enqueue(struct queue *q, int x)
{
    while (!isEmpty(&(q->s1))) {
        push(&(q->s2), retTop(&(q->s1)));
        pop((&(q->s1)));
    }
    push(&(q->s1), x);
    while (!isEmpty(&(q->s2))) {
        push(&(q->s1), retTop(&(q->s2)));
        pop(&(q->s2));
    }
}

void dequeue(struct queue *q)
{
    if (isEmpty(&q->s1)) {
        printf("\n\tQueue is empty!\n");
        return;
    }
    int x = retTop(&(q->s1));
    pop(&(q->s1));
    printf("popped: %d", x);
}

void print_queue(struct queue *q)
{
	if (isEmpty(&q->s1)) {
        printf("\n\tQueue is empty!\n");
        return;
    }
	int i;
	printf("Queue:");
	for (i=q->s1.top; i>=0; i--) {
		if (i==q->s1.top)
			printf("\n\ttop-->%2d\n",q->s1.A[i]);
		else
			printf("\t%8d\n",q->s1.A[i]);
	}
	printf("\n");
}

// main() function

int main()
{
    struct queue q;
    (q.s1).top=-1;
    (q.s2).top=-1;
	int choice=0;
	do {
	choice=0;
	//system("clear");
	printf("\n\t--------MENU--------");
	printf("\n\t1. Push element");
	printf("\n\t2. Pop element");
	printf("\n\t3. Print queue");
	printf("\n\t4. Exit");
	printf("\n\t--------------------");
	printf("\n\n\t\tEnter choice(1-4): ");
	scanf("%d", &choice);
    int x;
	switch(choice)
	{
		case 1: //
                printf("\n\tEnter element to push: ");
                scanf("%d", &x);
				enqueue(&q, x);
				break;
		case 2: //
			    dequeue(&q);
				break;
		case 3: //
				print_queue(&q);
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

// END OF PROGRAM