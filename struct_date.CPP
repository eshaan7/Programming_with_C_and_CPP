// Program which takes 2 dates as inputs and returns the later date

#include<iostream.h>
#include<conio.h>

struct date { int dd,mm,yy; };

date compare_date (date d1, date d2)
{
    if (d1.yy>d2.yy && d1.mm>d2.mm && d1.dd>d2.dd)
	return d1;
    else
	return d2;
}

void main()
{
	clrscr();
	date d1,d2,d3;
	cout<<"\n\tEnter 1st date in DD/MM/YYYY format: ";
	cin>>d1.dd;
	gotoxy(50, 2);
	cout<<"/ ";
	cin>>d1.mm;
	gotoxy(55, 2);
	cout<<"/ ";
	cin>>d1.yy;
	cout<<"\n\tEnter 2nd date in DD/MM/YYYY format: ";
	cin>>d2.dd;
	gotoxy(50, 4);
	cout<<"/ ";
	cin>>d2.mm;
	gotoxy(55, 4);
	cout<<"/ ";
	cin>>d2.yy;
	d3=compare_date(d1, d2);
	cout<<"\n\n\t1st date: "<<d1.dd<<"/"<<d1.mm<<"/"<<d1.yy;
	cout<<"\n\t2nd date: "<<d2.dd<<"/"<<d2.mm<<"/"<<d2.yy;
	cout<<"\n\n\t\tThe later date is: "<<d3.dd<<"/"<<d3.mm<<"/"<<d3.yy;
	getch();
}
