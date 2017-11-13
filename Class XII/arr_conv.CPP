/* Programmers' name: Eshaan & Anviti
   Date: 13/11/2017
   Topic: Conversion of 1D array into 2D. 
*/

#include<iostream.h>
#include<conio.h>

void create1D(int arr1D[], int n)
{
    cout<<"\nEnter the array elements: ";
    for (int i=0; i<n; i++) {
    	cin>>arr1D[i];
    }
}

void show2D(int arr2D[][10], int n)
{
	cout<<"\n\nThe required 2D array is: ";
	int i,j;
	for (i=0; i<n; i++) {
			gotoxy(15+(5*i),10);
			cout<<i;
			gotoxy(15+(5*i),11);
			cout<<"-----";
			gotoxy(12,12+i);
			cout<<i<<"|";
			for (j=0; j<n; j++) {
				gotoxy(15+(5*j),12+i);
				cout<<arr2D[i][j];
			}	
	}
}

void create2D(int arr1D[], int n)
{
	int arr2D[10][10];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j<=i)
				arr2D[i][j]=arr1D[j];
			else
				arr2D[i][j]=0;
		}
	}
	show2D(arr2D, n);
}

void main()
{
    int arr1D[10],n;
    clrscr(); 
    cout<<"\n\nEnter size of array(max 10): ";
    cin>>n;
    create1D(arr1D, n);
    create2D(arr1D, n);
	getch();
} 
