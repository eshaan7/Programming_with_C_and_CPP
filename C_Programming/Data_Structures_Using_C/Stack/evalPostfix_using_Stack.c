/*	Programmers' name: Eshaan Bansal (41816401518)
  	Date: 04/04/2019
	Topic: 6. Write a program to evaluate postfix expression using stack.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 

#define MAX_SIZE 15

struct stack
{ 
    int top; 
    int A[MAX_SIZE]; 
}; 


int isEmpty(struct stack *s) 
{ 
    return s->top == -1 ; 
} 

void push(struct stack *s, char c)
{
	if (s->top >= MAX_SIZE-1) {
		printf("Error: stack overflow\n");
		return;
	}
	s->A[++s->top]=c;
}

char pop(struct stack *s) // to return top element of stack and delete it
{
	if (!isEmpty(s)) 
        return s->A[s->top--] ; 
    return '$'; 
}

char peek(struct stack *s) // to return top element of stack
{
	return s->A[s->top];
}

// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    // Create a stack of capacity equal to expression size 
    struct stack s;
    s.top=-1;
    int i; 
    // Scan all characters one by one from left to right
    for (i = 0; exp[i]!='\0'; ++i) { 
        // If the scanned character is an operand (number here), 
        // push it to the stack. 
        if (isdigit(exp[i])) 
            push(&s, exp[i] - '0'); 
  
        // If the scanned character is an operator, pop two 
        // elements from stack and apply the operator 
        else {
            int val1 = pop(&s); 
            int val2 = pop(&s); 
            switch (exp[i]) 
            { 
            case '+': push(&s, val2 + val1); break; 
            case '-': push(&s, val2 - val1); break; 
            case '*': push(&s, val2 * val1); break; 
            case '/': push(&s, val2/val1); break; 
            } 
        } 
    } 
    return pop(&s);
}

// Driver program to test above functions 
int main() 
{ 
    char exp[] = "231*+9-";
    printf("The expression is:%s\n", exp);
    //char exp[] = "100 200 + 2 / 5 * 7 +"; 
    printf ("\tpostfix evaluation: %d\n", evaluatePostfix(exp)); 
    return 0; 
} 