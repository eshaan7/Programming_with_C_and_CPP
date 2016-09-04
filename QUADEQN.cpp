// Quadratic equation

#include <iostream.h>
#include <conio.h>
#include <math.h>

void main () {

	clrscr();
	float a,b,c,d,root1,root2;
	cout<<"Enter coefficients of a, b and c: ";
	cin>>a>>b>>c;
	d=b*b - 4*a*c;
	if (d==0) {
		root1=(-b) /(2*a);
		root2=root1;
		cout<<"\nRoots are real and equal"<<endl;
	}
	else if (d>0) {
		root1= (-b + sqrt(d)) / (2*a);
		root2= (-b - sqrt(d)) / (2*a);
		cout<<"\nRoots are real and different"<<endl;
	}
	else {
		root1= (-b) / (2*a);
		root2= sqrt(-d) / (2*a);
		cout<<"\nRoots are imaginary and complex"<<endl;
	}
	cout<<"\n Root 1 = "<<root1<<endl<<"\n Root 2 = "<<root2;
	getch();
}
