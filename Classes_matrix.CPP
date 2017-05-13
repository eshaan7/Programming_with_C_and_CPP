/* Programmers' name: Eshaan & Anviti
   Date: 11/05/2017
   Topic: class - 2D array
*/

#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>

void matrix(int m)
{
	int i;
	for (i=0; i<m; i++) {
			gotoxy(15+(5*i),7);
			cout<<i;
			gotoxy(15+(5*i),8);
			cout<<"-----";
			gotoxy(12,9+i);
			cout<<i<<"|";
		}
}
class arr2d
{
	int a[5][5];
	int m,n;
	public:
	void create2d();
	void show2d();
	void show2d_lower1();
	void show2d_lower2();
	void show2d_upper1();
	void show2d_upper2();
	void show2d_diag1();
	void show2d_diag2();
}arr;

void arr2d::create2d()
{
	cout<<"\nEnter order of matrix(max. 5): ";
	cin>>m;
	n=m;
	matrix(m);
	int i,j;
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			cin>>a[i][j];
		}
	}
}

void arr2d::show2d()
{
	int i,j;
	matrix(m);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			cout<<a[i][j];
		}
	}
}

void arr2d::show2d_upper1()
{
	int i,j;
	matrix(m);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			if (j>=i)
				cout<<a[i][j];
		}
	}
}

void arr2d::show2d_lower1()
{
	int i,j;
	matrix(m);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			if (i>=j)
				cout<<a[i][j];
		}
	}
}

void arr2d::show2d_upper2()
{
	int i,j;
	matrix(m);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			if (i+j<=m-1)
				cout<<a[i][j];
		}
	}
}

void arr2d::show2d_lower2()
{
	int i,j;
	matrix(m);
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			gotoxy(15+(5*j),9+i);
			if (i+j>=m-1)
				cout<<a[i][j];
		}
	}
}

void main()
{
	int choice,i,a;
	do
	{
	clrscr();
	cout<<"\n\n\t------------------------------------------";
	cout<<"\n\t\t----------MENU----------"
	    <<"\n\t1. Create 2D array"
	    <<"\n\t2. Show 2D array"
	    <<"\n\t3. Show upper right triangular matrix"
	    <<"\n\t4. Show upper left triangular matrix"
	    <<"\n\t5. Show lower left triangular matrix"
	    <<"\n\t6. Show lower right triangular matrix"
	    <<"\n\t7. Exit";
	cout<<"\n\t-------------------------------------------";
	cout<<"\n\n\tEnter your choice(1-7): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Invokes create2d() function
			clrscr();
			arr.create2d();
			getch();
			break;
		case 2: // Invokes show2d() function
			clrscr();
			arr.show2d();
			getch();
			break;
		case 3: // Invokes show2d_upper1() function
			clrscr();
			arr.show2d_upper1();
			getch();
			break;
		case 4: // Invokes show2d_upper2() function
			clrscr();
			arr.show2d_upper2();
			getch();
			break;
		case 5: // Invokes show2d_lower1() function
			clrscr();
			arr.show2d_lower1();
			getch();
			break;
		case 6: // Invokes show2d_lower2() function
			clrscr();
			arr.show2d_lower2();
			getch();
			break;
		case 7: // Terminates the program
			exit(0);
			break;
		default :
			cout <<"\n\n\t\tInvalid input. Try again in  ";
			for (a=5; a>=0; a--) {
					delay(500);
					cout<<"\b"<<a;
			}
	}
	} while (1);
	getch();
}




