// Sum of Exponential

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n, i, power, p, sum=0;
	cout<<"Enter any number: ";
	cin>>n;
	cout<<"Enter power: ";
	cin>>power;
	for (i=1; i<=power; i++) {
		p=pow(n,i);
		sum+=p;
	}
	cout<<"sum of Exponential of "<<n<<" raised to power "<<power<<" = "<<sum<<endl;
	return 0;
}
