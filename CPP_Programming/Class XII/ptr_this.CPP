/* Programmers' name: Eshaan & Anviti
   Date: 13/11/2017
   Topic: Pointers: Program illustrating the use of 'this' pointer
*/

#include<iostream.h>
#include<conio.h>

class MyClass
{
	int data;
    public:
      MyClass() { data = 100; };
      void Print1();
      void Print2();
};

// Not using this pointer
void MyClass::Print1() 
{
    cout<<data<<endl;
}

// Using this pointer
void MyClass::Print2()
{
    cout<<"My address in function Print2( ) is : "<<this<<endl;
    cout<<this->data<<endl;
}
void main()
{
    clrscr();
    // First  Object
    MyClass a;
    cout<<"Address of object as checked in main()  is : "<<&a<<endl;
    a.Print1();
    getch();
    a.Print2();
    getch();
    // Sizeof doesn't include this pointer
    cout<<sizeof(a)<<endl;
    getch();
    // Second  Object
    MyClass b;
    cout<<"Address of second object as checked in main() is : "<<&b<<endl;
    b.Print1();
    getch();
    b.Print2();
    getch();
}
