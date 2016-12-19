// Sine Series

#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int i,j,n,fact, sign=-1;
	float power,x, S=0;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of x: ";
	cin>>x;
	for (i=1; i<=n; i+=2) {
		power=1;
		fact=1;
		for (j=1; j<=i; j++) {
			power*=x;
			fact*=j;
		}
		sign*=-1;
		S+=sign*power/fact;
	}
	cout<<"Sin("<<x<<") = "<<S;
	getch();
}
