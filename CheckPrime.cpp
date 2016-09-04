// Check Prime number

#include<iostream>
using namespace std;

int main()
{
	int n,i,flag=0;
	cout<<"Enter any number: ";
	cin>>n;
	for (i=2; i<=n/2; i++) {
		if (n%i==0) 
			flag=1;
	}
	if (flag==0)
		cout<<n<<" is a prime number.";
	else
		cout<<n<<" is a composite number.";
	return 0;
}
