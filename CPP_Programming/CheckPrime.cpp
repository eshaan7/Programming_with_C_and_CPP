// Check Prime number

#include<iostream>
using namespace std;
int prime(int n)
{
    int flag=0;
    for (int i=2; i<=n/2; i++) {
		if (n%i==0)
			flag=1;
	}
	return flag;
}
int main()
{
	int n,ans=0;
	cout<<"Enter any number: ";
	cin>>n;

	if (prime(n))
		cout<<n<<" is a prime number.";
	else
		cout<<n<<" is a composite number.";
	return 0;
}
