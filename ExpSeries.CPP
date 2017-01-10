// Exponential Series

#include<iostream.h>
#include<conio.h>

void main()
{
	int i,j,x,n,power=1,fact=1;
	float S=0;
	cout<<"Enter any two number: ";
	cin>>n>>x;
	for (i=1; i<=n; i++) {
		power=1;
		fact=1;
		for (j=1; j<=i; j++) {
			power*=x;
			fact*=j;
		}
		S+=power/fact;
	}
	cout<<"Exponential series = "<<S;
	getch();
}
