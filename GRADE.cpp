// Calculate Grade of Student

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<math.h>

void main()
{
	clrscr();
       /*	 // Taking input using while loop
	int num=0;
	float total=0;
	float marks,avg;
	while (num < 5) {
	cout<<"Enter marks obtained in 5 subjects: ";
	cin>>marks;
	num++;
	total = total + marks;
	 } */
	char grade;
	float a,b,c,d,e,avg,total;
	cout<<"Enter marks obtained in 5 subjects: ";
	cin>>a>>b>>c>>d>>e;
	total=a+b+c+d+e;
	avg=total/5;
	cout<<"\n\n Total marks obtained in 5 subjects : "<<total;
	cout<<"\n Average marks in 5 subjects: "<<avg;
	/*                  // Personal approach to the problem(works fine)
	if (avg>=90) {
		grade='A';
	}
	else if (avg>=80 && avg<90) {
		grade='B';
	}
	else if (avg>=60 && avg<80) {
		grade='C';
	}
	else if (avg>=33 && avg<60) {
		grade='D';
	}
	else {
		grade='E';
	}  */

	if (avg>=33) {
	if (avg>=60) {
	if (avg>=80) {
	if (avg>=90)
		grade='A';
	else
		grade='B';
	}
	else
		grade='C';
	}
	else
		grade='D';
	}
	else
		grade='E';
	cout<<"\n\n\n Your grade is: "<<grade;
	getch();
}
