//File Name: ReverseNum.cpp
//Author: Eshaan Bansal
//Description: Prints reverse of any number

#include<iostream.h>
#include<conio.h>

void main()
{
	int n, remainder, reverse=0;
	cout<<"Enter any number: ";
	cin>>n;
	cout<<"\nOriginal number: "<<n<<"\n";
	while ( n!=0 ) {
		remainder= n%10;
		reverse = reverse*10 + remainder;
		n/=10;
	}
	cout<<"\nReverse number: "<<reverse<<"\n";
	getch();
}
