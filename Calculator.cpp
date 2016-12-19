// Menu Driven Program

#include<iostream.h>
#include<conio.h>
#include<process.h>

void main()
{
	clrscr();
	int choice,a,b,c;
	cout<<"Enter 2 numbers : ";
	cin>>a>>b;
	cout<<"\n\n Menu"
		<<"\n\n 1. Addition"
		<<"\n 2. Subtraction"
		<<"\n 3. Product"
		<<"\n 4. Divide"
		<<"\n 5. Remainder"
		<<"\n 6. Exit";
	cout<<"\n\n\t Enter your choice(1-6): ";
	cin>>choice;
	if (choice==1) {
		c=a+b;
		cout<<"\n Sum = "<<c;
	}
	else if (choice==2) {
		c=a-b;
		cout<<"\n Difference = "<<c;
	}
	else if (choice==3)	{
		c=a*b;
		cout<<"\n Product = "<<c;
	}
	else if (choice==4)	{
		c=a/b;
		cout<<"\n Quotient = "<<c;
	}
	else if (choice==5)	{
		c=a%b;
		cout<<"\n Remainder = "<<c;
	}
	else if (choice==6)	{
		exit(0);
	}
	else {
		cout<<"\n Invalid choice";
	}
	getch();
}