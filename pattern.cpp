
#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{ 	

	int n,i,j;
	cout<<"Enter any number: ";
	cin>>n;
        for (i=1; i<=n; i++) {
		cout<<endl; 
        	cout<<setw(20-i);
		for (j=n; j>n-i; j--) {			
			cout<<j;
		}		       
	}
	return 0;
}
