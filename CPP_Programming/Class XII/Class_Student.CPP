#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>

fstream fp;

class stud
{
	int rno;
	char name[20];
	public:
		void enter()
		{
			cout<<"\n\n\tEnter student details: ";
			cout<<"\n\n\t\tRoll no.: ";
			cin>>rno;
			cout<<"\n\t\tName: ";
			gets(name);
		}
		void display()
		{
			cout<<"\n\n\tSTUDENT DETAILS";
			cout<<"\n\n\t\tRoll no.: "<<rno;
			cout<<"\n\t\tName: ";
			puts(name);
		}
		int ret_rno()
		{
			return rno;
		}

}s;


void create()
{
	fp.open("student.dat", ios::binary|ios::app);
	cout<<"\n\n\t-----------Data file created-----------";
	fp.close();
}

void add()
{
	fp.open("student.dat", ios::binary|ios::app);
	s.enter();
	fp.seekp(fp.tellp()-sizeof(stud));
	fp.write((char*)&s, sizeof(stud));
	fp.close();
}

void del()
{	
	cout<<"\n\n\tDELETE RECORD";
	int n;
	cout<<"\n\n\tEnter roll number of the student whose record you wish to delete : ";
	cin>>n;
	fp.open("student.dat", ios::binary|ios::in);
	fstream fp2;
	fp2.open("Temp.dat",ios::binary|ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&s,sizeof(stud))) {
		if(s.ret_rno()!=n)
			fp2.write((char*)&s,sizeof(s));
	}
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\t-----------Record Deleted-----------";
}

void disp()
{
	fp.open("student.dat", ios::binary|ios::in);
	if(!fp) {
       cout<<"\n\n\tERROR!!!\n\tDATAFILE COULD NOT BE FOUND\n\n\tGo To main Menu to create File";
       return;
    }
	while(fp.read((char*)&s,sizeof(stud))) {
		s.display();
	}
	fp.close();
}

void main()
{
	clrscr();
	int choice,a;
	do
	{
	clrscr();
	cout<<"\n\n\t------------------------------------";
	cout<<"\n\t\t-------MENU-------"
	    <<"\n\t1. Create record file"
	    <<"\n\t2. Add record"
	    <<"\n\t3. Delete record"
	    <<"\n\t4. Display record"
	    <<"\n\t5. Exit";
	cout<<"\n\t------------------------------------";
	cout<<"\n\n\tEnter your choice(1-5): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Invokes create() fucntion
			clrscr();
			create();
			clrscr();
			break;
		case 2: // Invokes add() fucntion
			clrscr();
			add();
			clrscr();
			break;
		case 3: // Invokes del() function
			clrscr();
			del();
			getch();
			clrscr();
			break;
		case 4: // Invokes disp() fucntion
			clrscr();
			disp();
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