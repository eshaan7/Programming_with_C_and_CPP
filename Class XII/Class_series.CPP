/* Programmer's name: Eshaan & anviti
   Topic: Program to generate Fibonacci and Tribonacci series upto n terms.
   Date:  20/04/17
*/

#include<iostream.h>
#include<conio.h>   

class series
{
    int a,b,c,d;
    public:
    series ()
    {
        a=0;
        b=1;c=1;
    }
    void fib(int);
    void trib(int);
}s;

void series::fib(int n)
{
    int i;
    cout <<"\n\n\t\tFibonacci series\n";
    cout<<a<<" "<<b<<" ";
    for (i=1; i<=n; i++) {   
        cout<<c<<" ";
        a=b;
        b=c;
        c=a+b;
    }   
}

void series::trib(int n)
{
    int i;
    a=0;b=1;c=2; // The first three elements of the Tribonacci Series will be always 0, 1 and 2.
    cout <<"\n\n\t\tTribonacci series\n";
    cout<<a<<" "<<b<<" "<<c<<" ";
    for(i=1;i<=n;i++) {
        d=a+b+c;
        cout<<d<<" ";
        a=b;
        b=c;
        c=d;
    }
}

void main()
{
    clrscr();
    int num;
    cout<<"\n\n\t\tEnter the Number: ";
    cin>>num;
    s.fib(num);
    s.trib(num);
    getch();
}


