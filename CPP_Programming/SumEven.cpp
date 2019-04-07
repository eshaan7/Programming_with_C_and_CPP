// Program to calculate sum of all even numbers between 1 to n

#include<iostream.h>
#include<conio.h>

void main() 
{
	clrscr();
	int i, n, sum=0;
	cout<<"Enter any number: ";
	cin>>n;
	for(i=2; i<=n; i+=2) {
        	sum += i;
        }
	cout<<"\nSum of all even number between 1 to "<<n<<" = "<<sum;
	getch();
}
  
