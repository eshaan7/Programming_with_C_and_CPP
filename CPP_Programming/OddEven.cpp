// Program to find out odd or even number

#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int a;
	cout<<"Enter any number: ";
	cin>>a;
	if(a%2==0)
		cout<<"\nThe number is even.";
	else
		cout<<"\nThe number is odd.";
	getch();
}
