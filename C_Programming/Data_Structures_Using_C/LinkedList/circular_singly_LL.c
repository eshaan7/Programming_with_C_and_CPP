/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 14. Write a program to implement singly circular linked list: Insertion Deletion Search and Traversal.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

void push(int new_data) {
   /* create new node */
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = new_data; // assign new data
   /* if list is empty i.e. head = NULL */
   if (isEmpty()) { 
      head = new_node;
      head->next = head;
   } else {
      new_node->next = head;
      head = new_node;
   }    
}

void deleteFirst() 
{
   struct node *temp = head;
	/* If there is only one element */
   if(head->next == head)
      head = NULL;
   else
      head = head->next;
   printf("\nDeleted node: %d\n", temp->data);
   free(temp);
}

void printList() 
{
   struct node *ptr = head;
   printf("\nCircular Linked List: ");
   if(head != NULL) {
      while(ptr->next != ptr) {
         printf("[%d]->",ptr->data);
         ptr = ptr->next;
      }
      printf("[%d]->",ptr->data);
      printf("--{%d} \n",head->data);
   }
}

int main() {
   push(10);
   push(20);
   push(30);
   push(40);
   push(50);
   printList();
   deleteFirst();
   deleteFirst();
   printList(); 
   return 0;  
}