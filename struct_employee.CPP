// Employee Structure, Menu Driven; input and search options

#include<iostream.h>
#include<conio.h>

struct phone { int area_code, exchange, num; };
struct employee { int emp_num, salary; phone p; };

void main()
{
	clrscr();
	int choice,i,j,count=1,flag=0, squery, sum_salary=0;
	employee emp[5];
	do {
	// Fancy menu
	cout<<"\n\n\t----------------------------------------------" <<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Accept data of 5 employees"
	    <<"\n\t2. Search on the basis of area code"
	    <<"\n\t3. Search on the basis of exchange"
	    <<"\n\t4. Find the total salary of all employees";
	cout<<"\n\t----------------------------------------------" <<endl;
	cout<<"\n\tEnter choice(1-4): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Taking data inputs
			for (i=0; i<5; i++) {
				cout<<"\nEmployee number for employee "<<i+1<<": ";
				cin>>emp[i].emp_num;
				cout<<"Salary of employee "<<i+1<<": ";
				cin>>emp[i].salary;
				cout<<"Phone details of employee "<<i+1<<": ";
				cout<<"\n\t\tarea code: ";
				cin>>emp[i].p.area_code;
				cout<<"\t\texchange: ";
				cin>>emp[i].p.exchange;
				cout<<"\t\tphone no. : ";
				cin>>emp[i].p.num;
			}
			clrscr();
			break;
		case 2: // Search on the basis of area code
			cout<<"\n\n\tEnter search query(Max. 20 characters): ";
			cin>>squery;
			for (i=0; i<5; i++) {
				if(emp[i].p.area_code==squery) {
					flag=1;
					cout<<"\n\tResult found !!";
					cout<<"\n\tEmployee no.: "<<emp[i].emp_num;
					break;
				}
			}
			if (flag==0)
				cout<<"\n\tNo search results. Please try again.";
			getch();
			clrscr();
			break;
		case 3: // Search on the basis of exchange
			cout<<"\n\n\tEnter search query(Max. 20 characters): ";
			cin>>squery;
			for (i=0; i<5; i++) {
				if(emp[i].p.exchange==squery) {
					flag=1;
					cout<<"\n\Result found !!";
					cout<<"\n\tEmployee no.: "<<emp[i].emp_num;
					break;
				}
			}
			if (flag==0)
				cout<<"\n\tNo search results. Please try again.";
			getch();
			clrscr();
			break;
	case 4: // Total salary of all the emps
		for (i=0; i<5; i++)
		    sum_salary+=emp[i].salary;
		cout<<"\n\tSum of salaries of all the employees: "<<sum_salary;
		getch();
		clrscr();
		break;
	default:
		break;
	}
	count++;
	/* To make the program run multiple times, so that we can use
		all 4 options before it terminates
			*/
	} while (count<=5);
	getch();
}




