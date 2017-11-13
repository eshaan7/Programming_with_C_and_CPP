/* Programmers' name: Eshaan & Anviti
   Date: 13/11/2017
   Topic: Pointers: telephone structure
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>

struct telephone { char tno[10], name[20]; };
telephone tel[5];

void create()
{
	telephone *p=tel;
   	 for (int i=0; i<5; i++) {
		cout<<"\nName of member "<<i+1<<": ";
		gets(p->name);
		cout<<"Telephone no. of member "<<i+1<<": ";
		gets(p->tno);
        		p++;
	}
}

void show()
{
	telephone *p=tel;
   	gotoxy(25,2);
	cout<<"Name";
	gotoxy(45,2);
	cout<<"Telephone number";
	gotoxy(20,3);
	cout<<"-----------------------------------------";
	for (int i=0; i<5; i++) {
		gotoxy(25,5+i);
		puts(p->name);
		gotoxy(45,5+i);
		puts(p->tno);
     		p++;
   	 }    
	getch();
}

void main()
{
	clrscr();
	int choice,a;
    	do {
	// Fancy menu
	cout<<"\n\n\t----------------------------------------------" <<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Accept data in an array of 5 elements"
	        <<"\n\t2. Display the telephone details"
        	        <<"\n\t3. Exit";
	cout<<"\n\t----------------------------------------------" <<endl;
	cout<<"\n\tEnter choice(1-3): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Invokes create() function
			clrscr();
              			create();
               			clrscr();     
			break;
        		case 2: // Invokes show() function
               			clrscr();
                			show();
                			clrscr();
               			break;
       		 case 3: // Terminates the program
			exit(0);
			break;
		default:
			  cout <<"\n\n\t\tInvalid input. Try again in  ";
			   for (a=5; a>=0; a--) {
			       	delay(500);
				cout<<"\b"<<a;
			    }
	}
	} while (1);
	getch();
}
                