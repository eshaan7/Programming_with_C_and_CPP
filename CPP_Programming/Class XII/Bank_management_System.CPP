/* Programmers' name: Eshaan Bansal & Anviti Singh
   Date (last worked upon on): 28/10/2017
   Title: Bank Management System
	*/

#include<iostream.h> // standard input/output operations
#include<conio.h> // fx: getch(), gotoxy(), clrscr()
#include<stdio.h> // fx: gets(), puts(), remove(), rename()
#include<process.h> // exit()
#include<ctype.h> // fx: toupper()
#include<dos.h> // fx: delay()
#include<time.h> // fx: ctime()
#include<fstream.h> // fx: read(), write(), open(), close(), seekg(), seekp()

// global variables

int flag=0;
struct tt {
  int tt_sec;      /* Seconds */
  int tt_min;      /* Minutes */
  int tt_hour;     /* Hour (0--23) */
  int tt_mday;     /* Day of month (1--31) */
  int tt_mon;      /* Month (0--11) */
  int tt_year;     /* Year (calendar year minus 1900) */
};

time_t t=time(NULL);
char* nowTime=ctime(&t);
tm* d=localtime(&t); // tm->A structure(included in time.h) defining the broken-down time
fstream fp;

// main class

class account
{
    long acnum, balance;
    tt DOB,DOA; // DOA=> Date Of Activation
    char name[20], address[30], type;
    int pin[4];
	tt tx_date[20];
	unsigned int tx_num;
	long tx_amt[20];
	char tx_type[20]; // S=> Debit/Sale/Payment, C=>Credit
    public:
	void pin_verify();
	void check_acnum(long n);
	void check_amt(long amt);
	void write_acc();
	void show_acc();
	void modify_acc();
	void delete_acc();
	void cheque_req();
	void dep(long amt);
	void WDR(long amt);
	void deposit_withdraw(int option);
	void transfer();
	void tx_history();
	void display_all();
	long retacnum()
	{
	    return acnum;
	}
	long retbalance()
	{
	    return balance;
	}

}acc; // object declaration in global scope

// end of main class defintion

void account::dep(long amt)
{
	balance+=amt;
}

void account::WDR(long amt)
{
	balance-=amt;
}


/* 	takes a 4 digit numeric code as input which is obscured as it is typed by using asterisks (*)
	and compares it with the PIN no.
	this function is invoked every time a user wishes to do some task for security purposes */

void account::pin_verify()
{
	int i, x[4];
	cout<<"\nEnter PIN: ";
	for(i=0; i<4; i++) {
		x[i]=getch();
		cout<<"*";
	}
	for(i=0; i<4; i++) {
		if (x[i]!=pin[i]) {
			::flag=1;
			cout<<"\n\n\tWrong PIN entered."
			    <<"\n\tPlease check the PIN code you entered and try again.";
			break;
		}
	}
}

void account::check_acnum(long n)
{
	int f=0;
	fstream fp2;
	fp2.open("account.dat",ios::binary|ios::in);
	while(fp2.read((char*)&acc,sizeof(account))) {
			if (acnum==n) {
				f=1;
				break;
			}
	}
	fp2.close();
	if (f==1) {
		cout<<"\n\tThis account number already exists."
			<<"\n\tPlease choose another one."
			<<"\n\nEnter account no.(ex: xxxx69): ";
		cin>>n;
		check_acnum(n); // Recursion
	}
	else
		acnum=n;
}

// check_amt() checks the initial amount of deposit to fit the specified criteria
void account::check_amt(long amt)
{
	if (type=='S' && amt >= 500)
			balance=amt;
	else if (type=='C' && amt >= 1000)
			balance=amt;
	else {
			cout<<"\n\tPlease deposit sufficient amount of funds.";
			cout<<"\n\nEnter the initial amount( >=500 for Saving and >=1000 for current ) >> ";
			cin>>amt;
			check_amt(amt); // Recursion
	}
}

void account::write_acc()
{
	fp.open("account.dat",ios::binary|ios::app);
	long amt;
	long n;
	gotoxy(30,1);
	cout<<"CREATE A NEW ACCOUNT";
	cout<<"\n\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	check_acnum(n);  // Invokes check_acnum() function
	cout<<"\nEnter name of the account holder: ";
	gets(name);
	cout<<"\nEnter Date of Birth in DD/MM/YYYY format: ";
	cin>>DOB.tt_mday;
	gotoxy(48, 8);
	cout<<"/ ";
	cin>>DOB.tt_mon;
	gotoxy(53, 8);
	cout<<"/ ";
	cin>>DOB.tt_year;
	cout<<"\nWhat type of account do you wish to open ? (C/S): ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter the initial amount( >=500 for saving and >=1000 for current ) >> ";
	cin>>amt;
	check_amt(amt); // Invokes check_amt() function
	cout<<"\nSet PIN code for your account(ex: xx00): ";
	for(int i=0; i<4; i++) {
		pin[i]=getch();
		cout<<"*";
	}
	cout<<"\n\nTime of account creation >> "<<nowTime;
	DOA.tt_mday=d->tm_mday;
	DOA.tt_mon=d->tm_mon;
	DOA.tt_year=d->tm_year;
	cout<<"\n\n\t-----------Account Created-----------";
	fp.write((char*)&acc,sizeof(account));
	fp.close();
}

void account::show_acc()
{
	long n;
	int f=0;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::binary|ios::in);
	while(fp.read((char*)&acc,sizeof(account)) && f==0) {
		if (n==acnum) {
			f=1;
			pin_verify();
			if (flag!=1) {
				cout<<"\n\n\t----------------------------------------------"<<endl;
				cout<<"\t\t -- ACCOUNT DETAILS --"
					<<"\n\tAccount no.: "<<acnum
					<<"\n\tAccount Holder Name: "<<name
					<<"\n\tDate of Birth: "<<DOB.tt_mday<<"/"<<DOB.tt_mon<<"/"<<DOB.tt_year
					<<"\n\tDate of account creation: "<<DOA.tt_mday<<"/"<<DOA.tt_mon<<"/"<<1900+DOA.tt_year
					<<"\n\tType of Account: ";
				if (type=='S')
					cout<<"Savings";
				else if (type=='C')
					cout<<"Current";
				cout<<"\n\tAccount Balance: "<<balance;
				cout<<"\n\t----------------------------------------------"<<endl;
				break;
			}
			else
				flag=0;
		}
	}
	fp.close();
	if (f==0)
			cout<<"\n\n\tNo record found."
				<<"\n\tPlease check the no. you've entered and try again.";

}

void account::modify_acc()
{
	gotoxy(28,1);
	cout<<"UPDATE ACCOUNT PREFERENCES";
	long n,num;
	int f=0;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to modify(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&acc,sizeof(account)) && f==0) {
		if (n==acnum) {
			f=1;
			pin_verify();
			if (flag!=1) {
				cout<<"\n\tAccount no.: "<<acnum;
				cout<<"\n\nDo you wish to change your account no. ? (y/N) >> ";
				/*	(y/N) represents that the user can give the input in
					lower as well as upppercase
							*/
				cin>>confirm;
				confirm=toupper(confirm);
				if(confirm=='Y') {
					cout<<"\n\n\tPlease enter new account no.: ";
					cin>>num;
					check_acnum(num); // Invokes check_acnum() function
				}
				cout<<"\n\nDo you wish to change the PIN code ? (y/N) >> ";
				cin>>confirm;
				confirm=toupper(confirm);
				if(confirm=='Y') {
					cout<<"\n\n\tSet new PIN code for your account: ";
					for(int i=0; i<4; i++) {
						pin[i]=getch();
						cout<<"*";
					}
				}
				cout<<"\n\n\t---------Account Details modified---------";
				fp.seekp(fp.tellp()-sizeof(account));
				fp.write((char*)&acc,sizeof(account));
			}
			else
				flag=0;
		}
	}
	fp.close();
	if (f==0)
		cout<<"\n\n\tNo record found."
			<<"\n\tPlease check the no. you've entered and try again.";
}

void account::delete_acc()
{
	gotoxy(34,1);
	cout<<"CLOSE AN ACCOUNT";
	long n;
	int f=0;
	char confirm=' ';
	cout<<"\n\nEnter account no. you wish to delete(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::binary|ios::in|ios::out);
	while(fp.read((char*)&acc,sizeof(account)) && f==0) {
		if (n==acnum) {
			f=1;
			cout<<"\nAre you sure you want to delete your account ? (y/N) >> ";
			cin>>confirm;
			confirm=toupper(confirm);
			if(confirm=='Y') {
				cout<<"\n\nNote:"
					<<"\nDo not forget to collect your cash from a nearby branch.";
				cout<<"\n";
				pin_verify();
				if(flag!=1) {
					fstream fp2;
					fp2.open("Temp.dat",ios::binary|ios::out);
					fp.seekg(0,ios::beg);
					while(fp.read((char*)&acc,sizeof(account))) {
						if(acnum!=n)
								fp2.write((char*)&acc,sizeof(account));
					}
					fp2.close();
					fp.close();
					remove("account.dat");
					rename("Temp.dat","account.dat");
					cout<<"\n\n\t-----------Account Deleted-----------";
				}
				else
					flag=0;
			}
			else
				cout<<"\n\n\tTask terminated.";
		}
	}
	if (f==0)
		cout<<"\n\n\tNo record found."
			<<"\n\tPlease check the no. you've entered and try again.";
}


void account::cheque_req()
{
	gotoxy(25,1);
	cout<<"REQUEST FOR A NEW CHEQUE BOOK";
	long n;
	int f=0;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::binary|ios::in|ios::out);
	while(fp.read((char*)&acc,sizeof(account)) && f==0) {
		if (n==acnum) {
			f=1;
			pin_verify();
			if (flag!=1) {
				cout<<"\n\nEnter communication address(ex: flat no., street name, city, zip code)\n>> ";
				gets(address);
				cout<<"\n\n\tAccount no.: "<<acnum
					<<"\n\tAccount Holder Name: "<<name
					<<"\n\tCommunication address: "<<address;
				cout<<"\n\n\tPress enter to submit.";
				getch();
				cout<<"\n\nNote:"
					<<"\n1. The cheque book will be sent to your communication address as updated in our records."
					<<"\n2. The first delivery will be attempted by Courier within 5 working days.";
			}
			else
				flag=0;
		}
	}
	fp.seekp(fp.tellp()-sizeof(account));
	fp.write((char*)&acc,sizeof(account));
	fp.close();
	if (f==0)
			cout<<"\n\n\tNo record found."
				<<"\n\tPlease check the no. you've entered and try again.";
}


void account::deposit_withdraw( int option )
{
	gotoxy(28,1);
	cout<<"DEPOSIT / WITHDRAW MONEY";
	long n,amt;
	int f=0;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&acc,sizeof(account))) {
		if (n==acnum) {
			f=1;
			pin_verify();
			if (flag!=1) {
				if (option==1) {
					cout<<"\n\n\tHow much amount do you want to add to your account ?\n\t>> ";
					cin>>amt;
					dep(amt);
					tx_num++;
					tx_type[tx_num]='C';
					tx_amt[tx_num]=amt;
					tx_date[tx_num].tt_sec=d->tm_sec;
					tx_date[tx_num].tt_min=d->tm_min;
					tx_date[tx_num].tt_hour=d->tm_hour;
					tx_date[tx_num].tt_mday=d->tm_mday;
					tx_date[tx_num].tt_mon=d->tm_mon;
					tx_date[tx_num].tt_year=d->tm_year;
					cout<<"\n\n\tAccount Balance: "<<balance;
					break;
				}
				else if (option==2) {
					cout<<"\n\n\tHow much amount do you want to withdraw from your account ?\n\t>> ";
					cin>>amt;
					if (amt > balance )
						cout<<"\n\n\tInsufficient funds. Please try again.";
					else {
						WDR(amt);
						tx_num++;
						tx_type[tx_num]='S';
						tx_amt[tx_num]=amt;
						tx_date[tx_num].tt_sec=d->tm_sec;
						tx_date[tx_num].tt_min=d->tm_min;
						tx_date[tx_num].tt_hour=d->tm_hour;
						tx_date[tx_num].tt_mday=d->tm_mday;
						tx_date[tx_num].tt_mon=d->tm_mon;
						tx_date[tx_num].tt_year=d->tm_year;
						cout<<"\n\n\tAccount Balance: "<<balance;
						break;
					}
				}
			}
			else
				flag=0;
		}
	}
	fp.seekp(fp.tellp()-sizeof(account));
	fp.write((char*)&acc,sizeof(account));
	fp.close();
	if (f==0)
		cout<<"\n\n\tNo record found."
		    <<"\n\tPlease check the no. you've entered and try again.";
}


void account::transfer()
{
	gotoxy(34,1);
	cout<<"FUNDS TRANSFER";
	long n,n2,amt;
	int f=0;
	char confirm=' ';
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&acc,sizeof(account)) && f==0) {
		if (n==acnum) {
			f=1;
			cout<<"\nAre you sure you want to transfer funds to another account? (y/N): ";
			cin>>confirm;
			confirm=toupper(confirm);
			if(confirm=='Y') {
				cout<<"\n";
				pin_verify();
				if (flag!=1)  {
					cout<<"\n\n\tEnter the account no. of the beneficiary(ex: xxxx69): ";
					cin>>n2;
					cout<<"\n\tHow much amount do you want to transfer ?\n\t>> ";
					cin>>amt;
					WDR(amt);
					tx_num++;
					tx_type[tx_num]='S';
					tx_amt[tx_num]=amt;
					tx_date[tx_num].tt_sec=d->tm_sec;
					tx_date[tx_num].tt_min=d->tm_min;
					tx_date[tx_num].tt_hour=d->tm_hour;
					tx_date[tx_num].tt_mday=d->tm_mday;
					tx_date[tx_num].tt_mon=d->tm_mon;
					tx_date[tx_num].tt_year=d->tm_year;
					fp.seekp(fp.tellp()-sizeof(account));
					fp.write((char*)&acc,sizeof(account));
					fp.close();
					fstream fp2;
					fp2.open("account.dat",ios::in|ios::out|ios::binary);
					while(fp2.read((char*)&acc,sizeof(account))) {
						if (n2==acnum) {
							dep(amt);
							tx_num++;
							tx_type[tx_num]='C';
							tx_amt[tx_num]=amt;
							tx_date[tx_num].tt_sec=d->tm_sec;
							tx_date[tx_num].tt_min=d->tm_min;
							tx_date[tx_num].tt_hour=d->tm_hour;
							tx_date[tx_num].tt_mday=d->tm_mday;
							tx_date[tx_num].tt_mon=d->tm_mon;
							tx_date[tx_num].tt_year=d->tm_year;
							break;
						}
					}
					fp2.seekp(fp2.tellp()-sizeof(account));
					fp2.write((char*)&acc,sizeof(account));
					fp2.close();
					cout<<"\n\n\t-----------Funds transferred-----------";
					break;
				}
				else
					flag=0;
			}
			else
				cout<<"\n\n\tTask terminated.";
		}
	}
	if (f==0)
		cout<<"\n\n\tNo record found."
		    <<"\n\tPlease check the no. you've entered and try again.";
}

void account::tx_history()
{
	gotoxy(32,1);
	cout<<"TRANSACTION HISTORY";
	long n;
	int f=0;
	cout<<"\n\nEnter account no.(ex: xxxx69): ";
	cin>>n;
	fp.open("account.dat",ios::binary|ios::in);
	while(fp.read((char*)&acc,sizeof(account))) {
		if (acnum==n) {
			f=1;
			pin_verify();
			if (flag!=1)  {
				clrscr();
				gotoxy(32,1);
				cout<<"TRANSACTION HISTORY";
				gotoxy(10,3);
				cout<<"S No.";
				gotoxy(30,3);
				cout<<"Date";
				gotoxy(50,3);
				cout<<"Type";
				gotoxy(65,3);
				cout<<"Amount";
				gotoxy(10,4);
				cout<<"-------------------------------------------------------------";
				for (int i=1; i<=tx_num; i++) {
					gotoxy(10,5+i);
					cout<<i;
					gotoxy(22,5+i);
					cout<<tx_date[i].tt_mday<<"/"<<tx_date[i].tt_mon<<"/"<<1900+tx_date[i].tt_year
						<<"  "<<tx_date[i].tt_hour<<":"<<tx_date[i].tt_min<<":"<<tx_date[i].tt_sec;
					gotoxy(50,5+i);
					if (tx_type[i]=='S')
					cout<<"Debit";
					else if (tx_type[i]=='C')
					cout<<"Credit";
					gotoxy(65,5+i);
					if (tx_type[i]=='C')
						cout<<"+"<<tx_amt[i];
					else
						cout<<"-"<<tx_amt[i];
				}
			}
			else
				flag=0;
		}
	}
	fp.close();
	if (f==0)
			cout<<"\n\n\tNo record found."
		    	<<"\n\tPlease check the no. you've entered and try again.";
}


void account::display_all()
{
	int i=0;
	clrscr();		
	gotoxy(32,1);
	cout<<"ACCOUNT HOLDERS LIST";
	gotoxy(10,3);
	cout<<"A/c no.";
	gotoxy(25,3);
	cout<<"Name";
	gotoxy(49,3);
	cout<<"Type";
	gotoxy(65,3);
	cout<<"Balance";
	gotoxy(10,4);
	cout<<"-------------------------------------------------------------";
    fp.open("account.dat",ios::binary|ios::in);
    if(!fp) {
       cout<<"\n\n\tERROR!!!\n\tDATAFILE COULD NOT BE FOUND\n\n\tGo To Account Management Menu to create File";
       return;
    }
    while(fp.read((char*)&acc,sizeof(account))) {
		gotoxy(10,6+i);
		cout<<acnum;
		gotoxy(25,6+i);
		puts(name);
		gotoxy(50,6+i);
		cout<<type;
		gotoxy(65,6+i);
		cout<<balance;
		i++;
	}
     fp.close();
}

// STANDALONE FUNCTIONS

void credits()
{
	// Scrolling animation
	for ( int i=0; i<23; i++ ) {
		clrscr();
		gotoxy(30,23-i);
		cout<<"BANK MANAGEMENT SYSTEM";
		gotoxy(5,25-i);
		cout<<"MADE BY: ESHAAN BANSAL & ANVITI SINGH";
		gotoxy(5,27-i);
		cout<<"CLASS: XII-C";
		gotoxy(5,29-i);
		cout<<"ROLL. NO.: 17 & 8";
		delay(200);
    }
}
void acc_mng()
{
	clrscr();
	gotoxy(32,1);
	cout<<"ACCOUNT MANAGEMENT";
	int choice,a;
	cout<<"\n\n\t----------------------------------------------"<<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Open a new account"
	    <<"\n\t2. Modify account"
	    <<"\n\t3. Close an account"
	    <<"\n\t4. Go back";
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\n\tEnter choice(1-4): ";
	cin>>choice;
	switch(choice)
	{
		case 1:	// Invokes write_acc() function
			clrscr();
			acc.write_acc();
			getch();
			clrscr();
			break;
		case 2:  // Invokes modify_acc() function
			clrscr();
			acc.modify_acc();
			getch();
			clrscr();
			break;
		case 3: // Invokes delete_acc() function
			clrscr();
			acc.delete_acc();
			getch();
			clrscr();
			break;
		case 4:
			break;
		default:
			cout <<"\n\n\t\tInvalid input. Try again in  ";
			for (a=5; a>=0; a--) {
					delay(500);
					cout<<"\b"<<a;
			}
			clrscr();
			break;
	}
}

void acc_tx()
{
	clrscr();
	gotoxy(32,1);
	cout<<"ACCOUNT TRANSACTIONS";
	int choice,a;
	cout<<"\n\n\t----------------------------------------------"<<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Deposit amount"
	    <<"\n\t2. Withdraw amount"
	    <<"\n\t3. Transfer funds to another account"
	    <<"\n\t4. Go back";
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\n\tEnter choice(1-4): ";
	cin>>choice;
	switch(choice)
	{
		case 1: // Invokes deposit_withdraw() function for deposit purpose
			clrscr();
			acc.deposit_withdraw(1); // 1 => deposit
			getch();
			clrscr();
			break;
		case 2: // Invokes deposit_withdraw() function for withdraw purpose
			clrscr();
			acc.deposit_withdraw(2); // 2 => withdraw
			getch();
			clrscr();
			break;
		case 3: // Invokes transfer() function
			clrscr();
			acc.transfer();
			getch();
			clrscr();
			break;
		case 4:
			break;
		default:
			cout <<"\n\n\t\tInvalid input. Try again in  ";
			for (a=5; a>0; a--) {
					delay(500);
					cout<<"\b"<<a;
			}
			clrscr();
			break;
	}
}

// MAIN FUNCTION

void main()
{
	int choice,a;
	clrscr();
	do {
	// Fancy menu
	gotoxy(30,1);
	cout<<"BANK MANAGEMENT SYSTEM";
	cout<<"\n\n\tNow is "<<nowTime;
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\t\t\t-- MENU --";
	cout<<"\n\t1. Account management"
	    <<"\n\t2. Account transactions"
	    <<"\n\t3. Account enquiry"
	    <<"\n\t4. Request a cheque book"
	    <<"\n\t5. View Transaction History"
	    <<"\n\t6. Display all account holders list"
	    <<"\n\t7. Credits"
	    <<"\n\t8. Exit";
	cout<<"\n\t----------------------------------------------"<<endl;
	cout<<"\n\tEnter choice(1-8): ";
	cin>>choice;
	switch (choice)
	{
	 case 1: // Invokes acc_mng() function
		acc_mng();
		clrscr();
		break;
	 case 2: // Invokes acc_tx() function
		acc_tx();
		clrscr();
		break;
	 case 3: // Invokes show_acc() function
		clrscr();
		acc.show_acc();
		getch();
		clrscr();
		break;
	 case 4: // Invokes cheque_req() function
		clrscr();
		acc.cheque_req();
		getch();
		clrscr();
		break;
	 case 5: // Invokes tx_history() function
	 	clrscr();
		acc.tx_history();
		getch();
		clrscr();
		break;
	 case 6: // Invokes display_all() function
	 	clrscr();
		acc.display_all();
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
		cout <<"\n\n\t\tInvalid input. Try again in  ";
			for (a=5; a>=0; a--) {
					delay(500);
					cout<<"\b"<<a;
			}
		clrscr();
		break;
    }
    } while (1);
}
/*  *********************** End of code ***********************  */

