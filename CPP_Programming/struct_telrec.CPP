// Telrec Structure, Menu Driven; display and search options

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{
	clrscr();
	int choice,i,j,count=1,flag=0;
	struct telrec { char name[20], country[10]; };
	telrec tel[5];
	do {
	// Fancy menu
	cout<<"\n\n\t----------------------------------------------" <<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Accept data in an array of 5 elements"
	    <<"\n\t2. Display telrec array"
	    <<"\n\t3. Search on the basis of name"
	    <<"\n\t4. Search on the basis of country";
	cout<<"\n\t----------------------------------------------" <<endl;
	cout<<"\n\tEnter choice(1-4): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Taking data inputs
			for (i=0; i<5; i++) {
				cout<<"\nName of member "<<i+1<<": ";
				gets(tel[i].name);
				cout<<"Country of member "<<i+1<<": ";
				gets(tel[i].country);
			}
			clrscr();
			break;
		case 2: // Display telrec array in tabular form
			clrscr();
			gotoxy(25,2);
			cout<<"Name";
			gotoxy(45,2);
			cout<<"Country";
			gotoxy(20,3);
			cout<<"--------------------------------------";
			for (i=0; i<5; i++) {
				gotoxy(25,5+i);
				cout<<tel[i].name;
				gotoxy(45,5+i);
				cout<<tel[i].country;
			}
			getch();
			clrscr();
			break;
		case 3: // Search on the basis of name
			char sname[20];
			cout<<"\n\n\tEnter search query(Max. 20 characters): ";
			gets(sname);
			for (i=0; i<5; i++) {
				if(strcmp(tel[i].name, sname)==0) {
					flag=1;
					cout<<"\n\tMember found !!";
					cout<<"\n\t"<<tel[i].name<<"\t"<<tel[i].country;
					break;
				}
			}
			if (flag==0)
				cout<<"\n\t No search results. Please try again.";
			getch();
			clrscr();
			break;
		case 4: // Search on the basis of country
			char scountry[20];
			cout<<"\n\n\tEnter search query(Max. 20 characters): ";
			gets(scountry);
			for (i=0; i<5; i++) {
				if(strcmp(tel[i].country, scountry)==0) {
					flag=1;
					cout<<"\n\tMember found !!";
					cout<<"\n\t"<<tel[i].name<<"\t"<<tel[i].country;
					break;
				}
			}
			if (flag==0)
				cout<<"\n\t No search results. Please try again.";
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




