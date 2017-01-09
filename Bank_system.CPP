/* Programmer's name: Eshaan Bansal
   Date: 28/12/2016
   Title: Bank management system
	*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct account { long num, balance; char name[20], address[30], type; int pin[4]; };
account acc;
int flag=0;

/* 	takes a 4 digit numeric code as input which is obscured as it is typed by using asterisks (*)
	and compares it with the PIN no.
	this function is invoked every time a user wishes to do some task for security purposes */

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
			cout<<"\n\n\tWrong PIN entered."
			    <<"\n\tPlease check the PIN code you entered and try again.";
			break;
		}
	}
}

// check_amt() checks the initial amount of deposit to fit the specified criteria
void check_amt(long amt) 
{
	if (acc.type=='S' && amt >= 500)
			acc.balance=amt;
	else if (acc.type=='C' && amt >= 1000)
			acc.balance=amt;
	else {
			cout<<"\n\tPlease deposit sufficient amount of funds.";
			cout<<"\n\nEnter the initial amount( >=500 for Saving and >=1000 for current ) >> ";
			cin>>amt;
			check_amt(amt); // Recursion
	}
}

void write_acc()
{
	long amt;
	gotoxy(30,1);
	cout<<"CREATE A NEW ACCOUNT";
	cout<<"\n\nNote: Your new account will replace the previous account.";
	cout<<"\n\n\tIf you wish to continue. Press any key.";
	getch();
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>acc.num;
	cout<<"\nEnter name of the account holder: ";
	gets(acc.name);
	cout<<"\nWhat type of account do you wish to open ? (C/S): ";
	cin>>acc.type;
	acc.type=toupper(acc.type);
	cout<<"\nEnter the initial amount( >=500 for saving and >=1000 for current ) >> ";
	cin>>amt;
	check_amt(amt); // Invokes check_amt() function
	cout<<"\nSet PIN code for your account(ex: xx00): ";
	for(int i=0; i<4; i++) {
		acc.pin[i]=getch();
		cout<<"*";
	}
	cout<<"\n\n\t-----------Account Created-----------";
}

void deposit_withdraw( int option )
{
	gotoxy(28,1);
	cout<<"DEPOSIT / WITHDRAW MONEY";
	long n,amt;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			if (option==1) { 
				cout<<"\n\n\tHow much amount do you want to add to your account ?\n\t>> ";
				cin>>amt;
				acc.balance+=amt;
			}
			else if (option==2) {
				cout<<"\n\n\tHow much amount do you want to withdraw from your account ?\n\t>> ";
				cin>>amt;
				if (amt > acc.balance)
					cout<<"\n\n\tInsufficient funds. Please try again.";
				else 
					acc.balance-=amt;
				cout<<"\n\n\tAccount Balance: "<<acc.balance;
			}
		}	
		else
			flag=0;
	}
	else
		cout<<"\n\n\tWrong account no. entered."
		    <<"\n\tPlease check the no. you've entered and try again.";
}

void show_acc()
{
	long n;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\n\t----------------------------------------------"<<endl;
			cout<<"\t\t -- ACCOUNT DETAILS --"
			    <<"\n\tAccount no.: "<<acc.num
			    <<"\n\tAccount Holder Name: "<<acc.name
			    <<"\n\tType of Account: ";
			if (acc.type=='S')
				cout<<"Savings";
			else if (acc.type=='C')
				cout<<"Current";
			cout<<"\n\tAccount Balance: "<<acc.balance;
			cout<<"\n\t----------------------------------------------"<<endl;
		}
		else
			flag=0;
	}
	else
		cout<<"\n\n\tWrong account no. entered."
		    <<"\n\tPlease check the no. you've entered and try again.";

}

void modify_acc()
{
	gotoxy(28,1);
	cout<<"UPDATE ACCOUNT PREFERENCES";
	long n;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to modify(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\nDo you wish to change your account no. ? (y/N) >> ";
			/*	(y/N) represents that the user can give the input in 
				  lower as well as upppercase		
						*/
			cin>>confirm;
			confirm=toupper(confirm);
			if(confirm=='Y') {
				cout<<"\n\n\tPlease enter new account no.: ";
				cin>>acc.num;
			}
			cout<<"\n\nDo you wish to change the PIN code ? (y/N) >> ";
			cin>>confirm;
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
			<<"\n\tPlease check the no. you've entered and try again.";
}

void delete_acc()
{
	gotoxy(34,1);
	cout<<"CLOSE AN ACCOUNT";
	long n;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to delete(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		cout<<"\nAre you sure you want to delete your account ? (y/N) >> ";
		cin>>confirm;
		confirm=toupper(confirm);
		if(confirm=='Y') {
			cout<<"\n\nNote:"
			    <<"\nDo not forget to collect your cash from a nearby branch.";
			cout<<"\n";
			pin_verify();
			if(flag!=1) {
				// resetting values
				acc.num=rand() % 999999;
				acc.balance=0;
				acc.type='\0';
				for (int i=0; i<20; i++)
					acc.name[i]='\0';
				for (i=0; i<30; i++)
					acc.address[i]='\0';
				for (i=0; i<4; i++)
					acc.pin[i]=rand() % 10;
				cout<<"\n\n\t-----------Account Deleted-----------";
			}
			else
				flag=0;
		}
		else
			cout<<"\n\n\tTask terminated.";
	}
	else
		cout<<"\n\n\tWrong account no. entered."
		    <<"\n\tPlease check the no. you've entered and try again.";
}

void transfer()
{
	gotoxy(34,1);
	cout<<"FUNDS TRANSFER";
	long n,n2,amt;
	char confirm=' ';
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		cout<<"\nAre you sure you want to transfer funds to another account? (y/N): ";
		cin>>confirm;
		confirm=toupper(confirm);
		if(confirm=='Y') {
			cout<<"\n";
			pin_verify();
			if (flag!=1)  {
				cout<<"\n\n\tEnter the account no. of the beneficiary(ex: xxxx69):";
				cin>>n2;
				cout<<"\n\tHow much amount do you want to transfer ?\n\t>> ";
				cin>>amt;
				acc.balance-=amt;
				cout<<"\n\n\t-----------Funds transferred-----------";
			}
			else
				flag=0;
		}
		else
			cout<<"\n\n\tTask terminated.";
	}
	else
		cout<<"\n\n\tWrong account no. entered."
		    <<"\n\tPlease check the no. you've entered and try again.";
}

void cheque_req()
{
	gotoxy(25,1);
	cout<<"REQUEST FOR A NEW CHEQUE BOOK";
	long n;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\nEnter communication address(ex: flat no., street name, city, zip code)\n>> ";
			gets(acc.address);
			cout<<"\n\n\tAccount no.: "<<acc.num
			    <<"\n\tAccount Holder Name: "<<acc.name
			    <<"\n\tCommunication address: "<<acc.address;
			cout<<"\n\n\tPress enter to submit.";
			getch();
			cout<<"\n\nNote:"
				<<"\n1. The cheque book will be sent to your communication address as updated in our records."
				<<"\n2. The first delivery will be attempted by Courier within 5 working days.";
		}
		else
			flag=0;
	}
	else
		cout<<"\n\n\tWrong account no. entered."
		    <<"\n\tPlease check the no. you've entered and try again.";
}


void credits()
{
	long j;
	// Scrolling animation
	for ( int i=0; i<23; i++ ) {
		clrscr();
		gotoxy(30,23-i);
		cout<<"BANK MANAGEMENT SYSTEM";
		gotoxy(5,25-i);
		cout<<"MADE BY: ESHAAN BANSAL";
		gotoxy(5,27-i);
		cout<<"CLASS: XI-C";
		gotoxy(5,29-i);
		cout<<"ROLL. NO.: 16";
		for (j=0;j<9900000;j++) {} // time delay
    }
}

void main()
{
	clrscr();
	int count=0, choice;
	clrscr();
	do {
	// Fancy menu
	gotoxy(30,1);
	cout<<"BANK MANAGEMENT SYSTEM";
	cout<<"\n\n\t----------------------------------------------"<<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Open a new account"
	    <<"\n\t2. Deposit amount"
	    <<"\n\t3. Withdraw amount"
	    <<"\n\t4. Account enquiry"
	    <<"\n\t5. Modify account"
	    <<"\n\t6. Close an account"
	    <<"\n\t7. Transfer funds to another account"
	    <<"\n\t8. Request a cheque book"
	    <<"\n\t9. Credits"
	    <<"\n\t10. Exit";
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\n\tEnter choice(1-10): ";
	cin>>choice;
	switch (choice)
	{
	case 1: // Invokes write_acc() function
		clrscr();
		write_acc();
		getch();
		clrscr();
		break;
	 case 2: // Invokes deposit_withdraw() function for deposit purpose
		clrscr();
		deposit_withdraw(1); // 1 => deposit
		getch();
		clrscr();
		break;
	 case 3: // Invokes deposit_withdraw() function for withdraw purpose
		clrscr();
		deposit_withdraw(2); // 2 => withdraw
		getch();
		clrscr();
		break;
	 case 4: // Invokes show_acc() function
		clrscr();
		show_acc();
		getch();
		clrscr();
		break;
	 case 5: // Invokes modify_acc() function
		clrscr();
		modify_acc();
		getch();
		clrscr();
		break;
	 case 6: // Invokes delete_acc() function
		clrscr();
		delete_acc();
		getch();
		clrscr();
		break;
	 case 7: // Invokes transfer() function
		clrscr();
		transfer();
		getch();
		clrscr();
		break;
	 case 8: // Invokes cheque_req() function
		clrscr();
		cheque_req();
		getch();
		clrscr();
		break;
	 case 9: // Invokes credits() function
		clrscr();
		credits();
		getch();
		clrscr();
		break;
	 case 10: // Terminates the program
		exit(0);
		break;
	 default:
		break;
    }
    count++;
	/* To make the program run multiple times, so that we can use
		all  options before it terminates
			*/
    } while (count<=20);
    getch();
}