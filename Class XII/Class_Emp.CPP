/* Programmer's name: Eshaan & Anviti
   Topic: Program to store the record of an employee 
   Date: 13/04/17
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<dos.h>

class employee
{
	int id;
	char name[20], department[10], address[10];
	float basic_salary, HRA_rate, DA_rate, PF_rate;
	float HRA, DA, PF, g_salary, net_salary;

	void calculate()
	{
		HRA=(HRA_rate*basic_salary)/100;
		DA=(DA_rate*basic_salary)/100;
		PF=(PF_rate*basic_salary)/100;
		g_salary= basic_salary+HRA+DA;
		net_salary=g_salary-PF;
	}

	public:

	void get_data()
	{
		cout<<"\n\n\tName: ";
		gets(name);
		cout<<"\n\tID no.: ";
		cin>>id;
		cout<<"\n\tAddress: ";
		gets(address);
		cout<<"\n\tDepartment: ";
		gets(department);
		cout<<"\n\tBasic Salary: ";
		cin>>basic_salary;
		cout<<"\n\tHRA rate: ";
		cin>>HRA_rate;
		cout<<"\n\tDA rate: ";
		cin>>DA_rate;
		cout<<"\n\tPF rate: ";
		cin>>PF_rate;
		calculate();
		clrscr();
	}

	void display()
	{
		cout<<"\n\n\tName: ";
		puts(name);
		cout<<"\tID: "<<id;
		cout<<"\n\tAddress: ";
		puts(address);
		cout<<"\tDepartment: ";
		puts(department);
		cout<<"\tBasic Salary: "<<basic_salary;
		cout<<"\n\tNet salary: "<<net_salary;

	}
	int return_id()
	{
		return id;
	}
	char *return_name()
	{
		return name;
	}

 };

void main()
{
	clrscr();
	employee e[5];
	int choice,i;
	do {
	clrscr();
	cout<<"\n\n\t--------------------------------------";
	cout<<"\n\t\t-----MENU-----";
	cout<<"\n\t1. Accept"
	    <<"\n\t2. Display"
	    <<"\n\t3. Search on the basis of employee ID"
	    <<"\n\t4. Seach on the basis of name"
	    <<"\n\t5. Exit";
	cout<<"\n\t--------------------------------------";
	cout<<"\n\n\t\tEnter your choice(1-5): ";
	cin>>choice;
	switch(choice)
	{

		case 1: // to invoke get_data() function
			clrscr();
			for (i=0; i<5; i++) {
				gotoxy(27,2);
				cout<<"Details for #"<<i+1;
				e[i].get_data();
			}
			getch();
			break;
		case 2: // to invoke display() function
			clrscr();
			for (i=0; i<5; i++) {
				cout<<"\n\nDetails for #"<<i+1;
				e[i].display();
			}
			getch();
			break;
		case 3: // Search on the basis of employee ID
			clrscr();
			int s_id;
			cout<<"\nEnter search ID: ";
			cin>>s_id;
			for (i=0; i<5; i++) {
				if (s_id==e[i].return_id()) {
					e[i].display();
					break;
				}
			}
			getch();
			break;
		case 4: // Seach on the basis of name
			clrscr();
			char s_name[20];
			cout<<"\nEnter search name: ";
			gets(s_name);
			for (i=0; i<5; i++) {
				if (strcmp(s_name,e[i].return_name())==0) {
					e[i].display();
					break;
				}
			}
			getch();
			break;
		case 5: // Terminates the program
			exit(0);
			break;
		default:
			cout<<"\n\n\t\tInvalid input";
			delay(2000);
			break;
	}
	} while (1);
	getch();
}






