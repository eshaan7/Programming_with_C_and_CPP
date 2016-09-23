// Prints a diamond

#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{ 	

	int n,i,j,k,a;
	cout<<"Enter any number: ";
	cin>>n;
        for (i=1; i<=n; i++) {
		cout<<endl; 
        cout<<setw(20-i);
		for (j=1; j<=(2*i)-1; j++) {			
			cout<<"*";
		}		       
	}
	for (k=1; k<=n; k++) {
		cout<<endl;
        cout<<setw(20-(i-k));
		for (a=j-1; a>=(2*k)-1; a--) {			
			cout<<"*";
		}		       
	}
	return 0;
}
