/* Programmer's name: Eshaan Bansal
   Date: 19/12/2016
   Title: Caesar Cipher
      */

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void Encode( char str[20], int shift )
{
    int len=strlen(str);
    for (int i=0; i<len; i++) {
	if (str[i] == ' ')
	    continue;
	else
	     str[i]+=shift;
    }
}

void Decode( char str[20], int shift )
{
    int len=strlen(str);
    for (int i=0; i<len; i++) {
	if (str[i] == ' ')
	    continue;
	else
	     str[i]-=shift;
    }
}

void main()
{
    clrscr();
    char str[20];
    int choice,shift;
    cout<<"\n\n\t----------------------------------------------" <<endl;
    cout<<"\t\t\t-- MENU --" <<endl;
    cout<<"\t\t1. Encode string"<<endl;
    cout<<"\t\t2. Decode string"<<endl;
    cout<<"\t----------------------------------------------" <<endl;
    cout<<"\n\tEnter choice(1/2): ";
    cin>>choice;
    // Passing paramaters wih switch case
    switch (choice)
    {
	case 1: // Encode
		cout<<"\n\tEnter a normal string(Max. 20 characters): ";
		gets(str);
		cout<<"\n\tEnter number for the amount of letter shifting: ";
		cin>>shift;
		Encode(str, shift);
		cout<<"\n\n\t\Encoded string: "<<str;
		break;
	case 2: // Decode
		cout<<"\n\tEnter an encoded string(Max. 20 characters): ";
		gets(str);
		cout<<"\n\tEnter number for the amount of letter shifting: ";
		cin>>shift;
		Decode(str, shift);
		cout<<"\n\n\tDecoded string: "<<str;
		break;
	default:
		break;
    }
    getch();
}






 