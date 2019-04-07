// Program to check whether a year is a leap year or not

#include <iostream.h>
#include <conio.h>

void main ()
{
	clrscr();
	int year;
	cout<<"Enter a year: ";
	cin>>year;
	if (year%100==0) {
		if (year%400==0)
			cout<<"\n Leap year";
		else
			cout<<"\n Not a leap year";
	}
	else if (year%4==0)
		cout<<"\n Leap year";
	else
		cout<<"\n Not a leap year";

	getch();
}