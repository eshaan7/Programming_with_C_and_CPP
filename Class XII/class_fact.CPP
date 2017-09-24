/* Programmer's name: Eshaan & Anviti
   Topic: class to calculate factorial of a number
   Date:  20/04/17
*/

#include<iostream.h>
#include<conio.h>


class factorial
{
    public:
    fact_cal(float);
}fact;

factorial::fact_cal(float n)
{
    float f=1;
    for(int i=1; i<=n; i++)
	f*=i;
    cout<<"\n\n\t\tFactorial = "<<f;
}

void main()
{
    float n;
    clrscr();
    cout<<"\n\n\tEnter the Number: ";
    cin>>n;
    fact.fact_cal(n);
    getch();
}