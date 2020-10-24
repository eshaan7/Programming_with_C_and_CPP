/*  File Name: HCF.cpp
	Description: HCF of two numbers
	Author: Eshaan Bansal
	Date: 23/09/2016 */

#include<bits/stdc++.h>
using namespace std;
#include<conio.h>

int main() {


	int a,b,N,D,R=1,HCF;
	cout<<"Enter 2 numbers: "<<endl;
	cin>>a>>b;
	if (a>b) {
		N=a;
		D=b;
	}
	else {
		N=b;
		D=a;
	}
	while(R!=0) {
		R=N%D;
		if (R==0) {
			HCF=D;
		}
		else {
			N=D;
			D=R;
		}
	}
	cout<<"HCF of "<<a<<" and "<<b<<" is: "<<HCF;

}
