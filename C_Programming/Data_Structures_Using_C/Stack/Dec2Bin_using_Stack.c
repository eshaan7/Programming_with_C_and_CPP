/*	Programmers' name: Eshaan Bansal (41816401518)
  	Date: 04/04/2019
	Topic: 4. Write a program to covert decimal to binary using stack.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

struct stack
{ 
    int top; 
    int A[MAX_SIZE];
}; 


int isEmpty(struct stack *s) 
{ 
    return s->top == -1;
} 

void push(struct stack *s, int n)
{
	if (s->top >= MAX_SIZE-1) {
		printf("Error: stack overflow\n");
		return;
	}
	s->A[++s->top]=n;
}

void pop(struct stack *s)
{
	if (!isEmpty(s)) 
        --s->top;
}

void print_stack(struct stack *s)
{
	int i;
	printf("\tNumber in Binary: ");
	for (i=s->top; i>=0; i--)
			printf("%d",s->A[i]);
	printf("\n");
}

int main()
{
    struct stack s;
    s.top=-1;
    int x;
    printf("\n\tEnter number in decimal: ");
    scanf("%d", &x);
    while (x>0) {
        push(&s, x%2);
        x=x/2;
    }
    print_stack(&s);
    return 0;
}