/* Programmers' name: Eshaan & Anviti
   Date: 13/11/2017
   Topic: A program to create, and display the elements of an integer array using pointers.
*/

#include<iostream.h>
#include<conio.h>

void create(int arr[], int n)
{
    int *p=arr;
    cout<<"\n\n\tEnter the array elements: ";
    for (int i=0; i<n; i++) {
    	cin>>*p;
        p++;
    }
}

void show(int arr[], int n)
{
    int *p=arr;
    cout<<"\n\n\tElements of array: ";
    for (int i=0; i<n; i++) {
    	cout<<*p<<" ";
        	p++; 
    }
}

void main()
{
    int arr[10],n;
    clrscr(); 
    cout<<"\n\nEnter size of array(max 10): ";
    cin>>n;
    create(arr, n);
    show(arr, n);
    getch();
} 