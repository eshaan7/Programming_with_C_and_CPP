/*	Programmers' name: Eshaan Bansal (41816401518)
  	Date: 04/04/2019
	Topic: 5. Write a program to convert infix expression to postfix expression using stack.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

struct stack
{ 
    int top; 
    char A[MAX_SIZE];
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

char pop(struct stack *s)
{
	if (!isEmpty(s)) 
        return s->A[s->top--] ; 
    return '$'; 
}

char peek(struct stack *s) 
{
	return s->A[s->top];
}

// A utility function to check if the given character is operand 
// returns 1 if operand or 0 if not
int isOperand(char c) 
{ 
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); 
} 

// Function to return precedence of operators
// Higher returned value means higher precedence 
int prec(char c)
{
	if (c=='^')
		return 3;
	else if (c=='*' || c=='/')
		return 2;
	else if (c=='+' || c=='-')
		return 1;
	else
		return -1;
}

// The main function that converts given infix expression 
// to postfix expression.  
int infixToPostfix(char* exp)
{
	int i,k;
	struct stack s;
	s.top=-1;
	//char* output = (char *)malloc(sizeof(exp)*sizeof(char));
	// ^^ for using another string for output: replace exp[++k] with output[++k]
	for (i=0, k=-1; exp[i]; ++i) {
		// here exp[i] is the scanned character going from left to right

        // If the scanned character is an operand, add it to output. 
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		
		// If the scanned character is an ‘(‘, push it to the stack. 
		else if (exp[i]=='(')
			push(&s, exp[i]);
        
		// If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
		else if (exp[i]==')') {
			while (!isEmpty(&s) && peek(&s)!='(')
				exp[++k] = pop(&s);
			if (!isEmpty(&s) && peek(&s)!='(')
				return -1; // invalid expression
			else 
				pop(&s);
		}

		// an operator is encountered
		else {
			while ( !isEmpty(&s) && prec(exp[i]) <= prec(peek(&s)) )
				exp[++k] = pop(&s);
			push(&s, exp[i]);
		} 
	}
	// pop all the operators from the stack 
    while (!isEmpty(&s)) 
        exp[++k] = pop(&s); 
    exp[++k] = '\0'; 
    printf("\n\tPostfix expression: %s\n", exp);
	return 0;
}

int main() 
{ 
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	printf("\tInfix expression: %s", exp);
    infixToPostfix(exp);
    return 0;
}
