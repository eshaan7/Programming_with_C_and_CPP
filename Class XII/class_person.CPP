/*
	Programmers' name: Eshaan & Anviti
	Topic: Class- Person; create and search options
	Date:  04/05/2017
*/

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>

int n; // n=> no. of employees user wish to create
class person
{
	protected:
	char name[20];
	int age;
	public:
	void get_person();
};

void person::get_person()
{
		cout<<"\n\n\tName: ";
		gets(name);
		cout<<"\n\tAge: ";
		cin>>age;
}

class employee: public person
{
	char department[20];
	protected:
	float salary;
	public:
	void read();
	void write();
	float return_sal();
	int return_age();
	int return_dept(char d[]);

}e[20];

void employee::read()
{
	get_person();
	cout<<"\n\tSalary: ";
	cin>>salary;
	cout<<"\n\tDepartment: ";
	gets(department);
}

void employee::write()
{
		cout<<"\n\nDetails of employee";
		cout<<"\n\n\tName: ";
		puts(name);
		cout<<"\n\tAge: "<<age;
		cout<<"\n\n\tSalary: "<<salary;
		cout<<"\n\n\tDepartment: ";
		puts(department);

}

float employee::return_sal()
{
	return salary;
}

int employee::return_age()
{
	return age;
}

int employee::return_dept(char d[])
{
	if(strcmp(d,department)==0)
		return 1;
	else
		return 0;

}

void s_salary()
{
	int s,flag=0;
	cout<<"\n\nEnter the amount of salary: ";
	cin>>s;
	for (int i=0; i<n; i++) {
		if(e[i].return_sal()==s) {
			e[i].write();
			flag=1;
			break;
		}
	}
	if (flag!=1)
		cout<<"\n\n\tNo results found";
}

void s_dept()
{
	char d[20];
	int flag=0;
	cout<<"\n\nEnter department of the employee you want to search for: ";
	gets(d);
	for (int i=0; i<n; i++) {
		if (e[i].return_dept(d)==1) {
			e[i].write();
			flag=1;
			break;
		}
	}
	if (flag!=1)
		cout<<"\n\n\tNo results found";
}

void s_age()
{
	int a,flag=0;
	cout<<"\n\nEnter age of the employee you want to search for: ";
	cin>>a;
	for (int i=0; i<n; i++) {
		if (e[i].return_age()==a) {
			e[i].write();
			flag=1;
			break;
		}
	}
	if (flag!=1)
		cout<<"\n\n\tNo results found";
}

void main()
{
	int choice,i;
	do
	{
	clrscr();
	cout<<"\n\n\t------------------------------------";
	cout<<"\n\t\t-------MENU-------"
	    <<"\n\t1. Create"
	    <<"\n\t2. Search on the basis of salary"
	    <<"\n\t3. Search on the basis of department"
	    <<"\n\t4. Seach on the basis of age"
	    <<"\n\t5. Exit";
	cout<<"\n\t------------------------------------";
	cout<<"\n\n\tEnter your choice(1-5): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Invokes read() function
			clrscr();
			cout<<"\n\nEnter no. of employees(Max. 20): ";
			cin>>n;
			for (i=0; i<n; i++) {
				cout<<"\n\nDetails for employee #"<<i+1;
				e[i].read();
			}
			break;
		case 2: // Invokes s_salary() function
			clrscr();
			s_salary();
			getch();
			break;
		case 3: // Invokes s_dept() function
			clrscr();
			s_dept();
			getch();
			break;
		case 4: // Invokes s_age() function
			clrscr();
			s_age();
			getch();
			break;
		case 5: // Terminates the program
			exit(0);
			break;
		default:
			cout<<"\n\n\t\tInvalid option";
			delay(1000);
			break;
	}
	} while(1);
	getch();
}


