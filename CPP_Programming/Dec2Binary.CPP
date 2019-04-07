// Program which accepts number in base 10 and prints number in base 2

#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int n,i=0, r[10];
	cout<<"Enter any number: ";
	cin>>n;
	cout<<"\n\n\tNumber in Base 10: "<<n;
	while (n!=1) {
		r[i]=n%2;
		i++;
		n=n/2;
	}
	cout<<"\n\tNumber in Base 2: ";
	for (; i>=0; i--)
		cout<<r[i];
	getch();
}


