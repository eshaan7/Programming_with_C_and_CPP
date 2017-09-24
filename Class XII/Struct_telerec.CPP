/* Programmmers' name: Eshaan & Anviti
   Date: 11/05/2017
   Topic: Structure telerec
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<dos.h>

struct telrec { char name[20], num[10]; };

fstream fp;

class record
{
    telrec tel;
	public:
    void create();
    void display();
    void s_name();
    void s_num();
}rec;

void record::create()
{
	fp.open("tel.dat", ios::binary|ios::app);
	cout<<"\n\tName of member: ";
	gets(tel.name);
	cout<<"\n\tTelephone number of member(10 digits): ";
	gets(tel.num);
	fp.write((char*)&rec, sizeof(record));
	fp.close();
}

void record::display()
{
	int i=0;
	fp.open("tel.dat", ios::binary|ios::in);
	gotoxy(25,2);
	cout<<"Name";
	gotoxy(45,2);
	cout<<"Telephone number";
	gotoxy(20,3);
	cout<<"---------------------------------------------";
	if(!fp) {
		cout<<"\n\n\tERROR!!!\n\tDATAFILE COULD NOT BE FOUND\n\n\tGo To main Menu to create File";
		return;
	}
	while(fp.read((char*)&rec, sizeof(record))) {
		gotoxy(25,5+i);
		puts(tel.name);
		gotoxy(45,5+i);
		puts(tel.num);
		i++;
	}
	fp.close();
}

void record::s_name()
{
	fp.open("tel.dat", ios::binary|ios::in);
	char sname[20], flag=0;
	cout<<"\n\n\tEnter search query(Max. 20 characters): ";
	gets(sname);
	while(fp.read((char*)&rec, sizeof(record))) {
	    if(strcmp(tel.name, sname)==0) {
			flag=1;
			cout<<"\n\tMember found !!\n\t";
			puts(tel.name);
			cout<<"\t";
			puts(tel.num);
			break;
		}
	}
	fp.close();
	if (flag==0)
	    cout<<"\n\t No search results. Please try again.";
}

void record::s_num()
{
	fp.open("tel.dat", ios::binary|ios::in);
    char snum[20], flag=0;
	cout<<"\n\n\tEnter search query(Max. 20 characters): ";
	gets(snum);
	while(fp.read((char*)&rec, sizeof(record))) {
		if(strcmp(tel.num, snum)==0) {
		    flag=1;
			cout<<"\n\tMember found !!\n\t";
			puts(tel.name);
			cout<<"\t";
			puts(tel.num);
			break;
		}
	}
	fp.close();
    if (flag==0)
	cout<<"\n\t No search results. Please try again.";
}

void main()
{
	clrscr();
	int choice,a;
	do {
	// Fancy menu
	cout<<"\n\n\t----------------------------------------------" <<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Create telephone record"
	    <<"\n\t2. Display telephone record"
	    <<"\n\t3. Search on the basis of name"
	    <<"\n\t4. Search on the basis of telephone number"
	    <<"\n\t5. Exit";
	cout<<"\n\t----------------------------------------------" <<endl;
	cout<<"\n\tEnter choice(1-4): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Taking data inputs
			clrscr();
			rec.create();
			getch();
			clrscr();
			break;
		case 2: // Display telrec data in tabular form
			clrscr();
			rec.display();
			getch();
			clrscr();
			break;
		case 3: // Search on the basis of name
			clrscr();
			rec.s_name();
			getch();
			clrscr();
			break;
		case 4: // Search on the basis of tel_num
			clrscr();
			rec.s_num();
			getch();
			clrscr();
			break;
		case 5: // Terminates the program
			exit(0);
			break;
		default:
			cout <<"\n\n\t\tInvalid input. Try again in  ";
			for (a=5; a>=0; a--) {
				delay(500);
				cout<<"\b"<<a;
			}
		clrscr();
		break;
	}
	} while (1);
	getch();
}




