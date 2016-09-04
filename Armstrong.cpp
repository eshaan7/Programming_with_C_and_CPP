//File Name: Armstrong.cpp
//Author: Eshaan Bansal
//Description: Checks if a number is an armstrong number or not

#include<iostream>
using namespace std;

int main()
{
	int n,a, remainder, A=0;
	cout<<"Enter any number: ";
	cin>>n;
	a=n;
	while ( n!=0 ) {
		remainder=n%10;
		A+=remainder*remainder*remainder;
		n/=10;
	}
	if(a==A)
		cout<<"\n\n\t It is an armstrong number."<<endl;
	else
		cout<<"\n\n\t It\'s not an armstrong number."<<endl;
	return 0;
}
