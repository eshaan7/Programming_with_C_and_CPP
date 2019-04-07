// String manipulation

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void main()
{
	clrscr();
	char str[20],ch;
	cout<<"\n\tEnter a string (max. 20 characters) : ";
	gets(str);
	char palindrome[50]={"Hello Palindrome "};
	char non_palindrome[50]={"Hello Non-palindrome "};
	int len=strlen(str);
	int i,j,flag=1;
	for (i=0, j=len-1; i<len/2; i++, j--) {
		if(str[i]!=str[j]) {
			flag=0;
			break;
		}
	}
	if (flag==1) {
		strcat(palindrome, str);
		cout<<"\n\n\t\t"<<palindrome;
	}
	else  {
		strcat(non_palindrome, str);
		cout<<"\n\n\t\t"<<non_palindrome;
	}
	getch();

}
