
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>

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
			cout<<"\n\n\tWrong PIN entered. Please check the PIN you entered and try again.";
			break;
		}
	}
}

void write_acc()
{
	gotoxy(30,1);
	cout<<"CREATE A NEW ACCOUNT";
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
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
				acc.balance-=amt;
			}
			cout<<"\n\n\tAccount Balance: "<<acc.balance;
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
	cout<<"\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		pin_verify();
		if (flag!=1) {
			cout<<"\n\n\t----------------------------------------------"<<endl;
			cout<<"\t\t -- ACCOUNT DETAILS --"
				<<"\n\tAccount no.: "<<acc.num
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
			<<"\n\tPlease check the no. you've entered and try again.";

}

void modify_acc()
{
	gotoxy(26,1);
	cout<<"UPDATE ACCOUNT PREFERENCES";
	long n;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to modify(ex: xxxx69): ";
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
			<<"\n\tPlease check the no. you've entered and try again.";
}

void delete_acc()
{
	gotoxy(29,1);
	cout<<"CLOSE AN ACCOUNT";
	long n;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to modify(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		cout<<"\nAre you sure you want to delete your account ? (y/N) >> ";
		confirm=getch();
		confirm=toupper(confirm);
		if(confirm=='Y') {
			cout<<"\n";
			pin_verify();
			if(flag!=1) {
				// delete statement
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
	gotoxy(32,1);
	cout<<"FUNDS TRANSFER";
	long n,n2,amt;
	char confirm=' ';
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	if (n==acc.num) {
		cout<<"\nAre you sure you want to transfer funds to another account? (y/N): ";
		confirm=getch();
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
			cout<<"\n\tEnter communication address(ex: flat no., street name, city, zip code) :";
			gets(acc.address);
			cout<<"\n\tAccount no.: "<<acc.num
				<<"\n\tAccount Holder Name: "<<acc.name;
			cout<<"\nPress enter to submit.";
			getch();
			cout<<"\nNotes:"
				<<"\n\tThe cheque book will be sent to your communication address as updated in our records."
				<<"\n\tThe first delivery will be attempted by Courier within 5 working days.";
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
	int i,a,b;
	long j;
	for (i=0; i<27; i++ ) {
		clrscr();
		gotoxy(38,27-i);
		cout<<"MADE BY";
		gotoxy(35,28-i);
		cout<<"ESHAAN BANSAL";
		gotoxy(35,29-i);
		cout<<"ESHAAN BANSAL";
		for (j=0;j<9000000;j++) {} // time
       }
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
    } while (count<=11);
    getch();
}