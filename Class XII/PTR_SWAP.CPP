/* Programmers' name: Eshaan & Anviti
   Date: 13/11/2017
   Topic: Pointers: swap 2 given numbers
*/

#include<iostream.h>
#include<conio.h>

void swap(int *a, int *b)
{
    int temp;
    temp=*a; 
    *a=*b;
    *b=temp;
} 

void main()
{
    clrscr();
    int n1,n2;
    cout<<"\n\tEnter 2 numbers: ";
    cin>>n1>>n2;
    cout<<"\n\tBefore swap the 2 numbers are: "<<n1<<" "<<n2;
    swap(&n1, &n2);
    cout<<"\n\tAfter swap the 2 numbers are: "<<n1<<" "<<n2;
    getch();
}