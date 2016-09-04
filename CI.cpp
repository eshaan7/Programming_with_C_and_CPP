//Calculate Simple Interest and Compound Interest

#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{
	clrscr();
	float P,R,T,SI,CI;
	cout<<"Enter Principal, Rate and Time : ";
	cin>>P>>R>>T;
	SI=(P*R*T)/100;
	CI=P*pow((1+R/100),T) - P;
	cout<<"\n\n\n Simple Interest is : "<<SI;
	cout<<"\n\n\n Compound Interest is : "<<CI;
	getch();

}

