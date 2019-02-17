/*	Author's name: Eshaan Bansal
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 

#define MAX_SIZE 20

struct stack
{ 
    int top; 
    char A[MAX_SIZE];
}; 


int isEmpty(struct stack *s) 
{ 
    return s->top == -1; 
} 

void push(struct stack *s, char c)
{
	if (s->top >= MAX_SIZE-1) {
		printf("Error: stack overflow\n");
		return;
	}
	s->A[++s->top]=c;
}

void pop(struct stack *s)
{
	if (!isEmpty(s))
        --s->top;
    else
        printf("\nError: Stack underflow.\n");
}

char peek(struct stack *s) 
{
	return s->A[s->top];
}

int isMatchingPair(char character1, char character2) 
{ 
   if (character1 == '(' && character2 == ')') 
     return 1; 
   else if (character1 == '{' && character2 == '}') 
     return 1; 
   else if (character1 == '[' && character2 == ']') 
     return 1; 
   else
     return 0; 
}

int main()
{
    char exp[20];
    printf("\n\tEnter expression: ");
    scanf("%s", exp);
    struct stack s;
    s.top=-1;
    for (int i=0; exp[i]!='\0'; i++) {
        printf("%c", exp[i]);
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(&s, exp[i]);
        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if (isEmpty(&s) || !isMatchingPair(peek(&s),exp[i])) {
                printf("\tExpression is invalid!\n");
                return 1;
            }
            else
                pop(&s);
        }
    }
    if (isEmpty(&s)) {
        printf("\tExpression is valid.\n");
        return 0;
    }
    else {
        printf("\tExpression is invalid.\n");
        return 1;
    }
}
