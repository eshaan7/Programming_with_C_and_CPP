// Prints a diamond which is hollow from the upper side

#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

int main()
{
	clrscr();
	int n,i,j,k,a;
	cout<<"Enter any number: ";
	cin>>n;
	for (i=1; i<=n; i++) {
		gotoxy(25-i,i+5);
		for (j=1; j<=(2*i)-1; j++) {
			cout<<"*";
		}
	}
	for (k=1; k<=n; k++) {
		gotoxy(25-(i-k),5+n+k);
		for (a=j-1; a>=(2*k)-1; a--) {
			cout<<"*";
		}
	}
	for (i=1; i<=n-1; i++) {
		gotoxy(25-i,i+6);
		for (j=1; j<=(2*i)-1; j++) {
			cout<<" ";
		}
	}
	getch();
	return 0;
}
