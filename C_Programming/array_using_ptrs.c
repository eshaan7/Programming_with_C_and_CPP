/* Programmers' name: Eshaan Bansal (41816401518)
   Date: 04/04/2019
   Topic: Write a program to implement array using pointers.
*/

#include<stdio.h>

void create(int arr[], int n)
{
    int *p=arr;
    int i;
    printf("\n\tEnter the array elements: ");
    for (i=0; i<n; i++) {
    	scanf("%d", p);
        p++;
    }
}

void show(int arr[], int n)
{
    int *p=arr;
    int i;
    printf("\n\tElements of array: ");
    for (i=0; i<n; i++) {
    	printf("%d ",*p);
        p++; 
    }
}

int main()
{
    int arr[10],n;
    printf("\nEnter size of array(max 10): ");
    scanf("%d", &n);
    create(arr, n);
    show(arr, n);
    return 0;
} 