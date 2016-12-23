
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>

struct account { long num, balance; char name[20], type; int pin[4]; };
account acc;
int flag=0;

void pin_verify()
{
	int i, x[4];
	cout<<"\nEnter PIN: ";
	for(i=0; i<4; i++) {
		x[i]=getch();
		cout<<"*";
	}
	for(i=0; i<4; i++) {
		if (x[i]!=acc.pin[i]) {
			flag=1;
			cout<<"\n\n\tWrong PIN entered. Please check the PIN you entered and try again.";
			break;
		}
	}
}

void write_acc()
{
	cout<<"\nEnter account no.(ex: xxxx69): ";
	cin>>acc.num;
	cout<<"\nEnter name of the account holder: ";
	gets(acc.name);
	cout<<"\nWhat type of account do you wish to open ? (C/S): ";
	cin>>acc.type;
	acc.type=toupper(acc.type);
	cout<<"\nEnter the Initial amount(>=500 for Saving and >=1000 for current): ";
	cin>>acc.balance;
	cout<<"\nSet PIN code for your account(ex: xx00): ";
	for(int i=0; i<4; i++) {
		acc.pin[i]=getch();
		cout<<"*";
	}
	cout<<"\n\n\t-----------Account Created-----------";
}

void deposit_withdraw( int option )
{
	long n,amt;
	cout<<"\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			if (option==1) {
				cout<<"\n\n\tHow much amount do you want to add to your account ?\n\t>>";
				cin>>amt;
				acc.balance+=amt;
			}
			else if (option==2) {
				cout<<"\n\n\tHow much amount do you want to withdraw from your account ?\n\t>>";
				cin>>amt;
				acc.balance-=amt;
			}
			cout<<"\n\n\tAccount Balance: "<<acc.balance;
		}
		else
			flag=0;
	}
	else 
		cout<<"\n\n\tWrong account no. entered."
			<<"\n\tPlease check the no. you've entered and try again";
}

void show_acc()
{
	long n;
	cout<<"\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\n\t----------------------------------------------"<<endl;
			cout<<"\t\t\t-- ACCOUNT DETAILS --"
				<<"\n\n\n\tAccount no.: "<<acc.num
				<<"\n\tAccount Holder Name: "<<acc.name
				<<"\n\tType of Account: "<<acc.type
				<<"\n\tAccount Balance: "<<acc.balance;
			cout<<"\n\t----------------------------------------------"<<endl;
		}
		else
			flag=0;
	}
	else
		cout<<"\n\n\tWrong account no. entered."
			<<"\n\tPlease check the no. you've entered and try again";

}

void modify_acc()
{
	long n;
	char confirm=' ';
	cout<<"\nEnter account no. you wish to modify(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\nDo you wish to change your account no. ? (y/N) >> ";
			confirm=getch();
			confirm=toupper(confirm);
			if(confirm=='Y') {
				cout<<"\n\n\tPlease enter new account no.: ";
				cin>>acc.num;
			}
			cout<<"\n\nDo you wish to change the PIN code ? (y/N) >> ";
			confirm=getch();
			confirm=toupper(confirm);
			if(confirm=='Y') {
				cout<<"\n\n\tSet new PIN code for your account: ";
				for(int i=0; i<4; i++) {
					acc.pin[i]=getch();
					cout<<"*";
				}
			}
			cout<<"\n\n\t---------Account Details modified---------";
		}
		else
			flag=0;
	}
	else
		cout<<"\n\n\tWrong account no. entered."
			<<"\n\tPlease check the no. you've entered and try again";
}

void delete_acc()
{
	long n1;
	char confirm=' ';
	cout<<"\nEnter account no. you wish to modify(ex: xxxx69): ";
	cin>>n1;
	if (n1==acc.num) {
		cout<<"\nAre you sure you want to delete your account ? (y/N) >> ";
		confirm=getch();
		if(confirm=='Y') {
			pin_verify();
			if(flag!=1) {
				// delete statement
				cout<<"\n\n\t-----------Account Deleted-----------";
			}
			else
				flag=0;
		}
		else
				cout<<"\n\n\tTask terminated";
	}
	else
		cout<<"\n\n\tWrong account no. entered." 
			<<"\n\tPlease check the no. you've entered and try again";
}

void credits()
{
	
}

void main()
{
	clrscr();
	int count=0, choice;
	do {
	// Fancy menu
	cout<<"\n\n\t----------------------------------------------"<<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Open new account"
	    <<"\n\t2. Deposit amount"
	    <<"\n\t3. Withdraw amount"
	    <<"\n\t4. Account enquiry"
	    <<"\n\t5. Modify account"
	    <<"\n\t6. Close an account"
		<<"\n\t7. Credits"
		<<"\n\t8. Exit";
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\n\tEnter choice(1-8): ";
	cin>>choice;
    switch (choice)
    {
	 case 1: // Invoking write_acc() function
		 clrscr();
		 write_acc();
		 getch();
		 clrscr();
		 break;
	 case 2: // Invoking deposit_withdraw() function for deposit purpose
		 clrscr();
		 deposit_withdraw(1);
		 getch();
		 clrscr();
		 break;
	 case 3: // Invoking deposit_withdraw() function for withdraw purpose
		 clrscr();
		 deposit_withdraw(2);
		 getch();
		 clrscr();
		 break;
	 case 4: // Invoking show_acc() function
		 clrscr();
		 show_acc();
		 getch();
		 clrscr();
		 break;
	 case 5: // Invoking modify_acc() function
		 clrscr();
		 modify_acc();
		 getch();
		 clrscr();
		 break;
	 case 6: // Invoking delete_acc() function
		 clrscr();
		 delete_acc();
		 getch();
		 clrscr();
		 break;
	 case 7: // Invokes credits() function
	 	  clrscr();
		  credits();
		  getch();
		  clrscr();
		  break;
	 case 8: // Terminates the program
	 		exit(0);
			break; 
	 default:
		 break;
    }
    count++;
	/* To make the program run multiple times, so that we can use
		all  options before it terminates
			*/
    } while (count<=8);
    getch();
}