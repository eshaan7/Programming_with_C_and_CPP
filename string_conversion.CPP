// String manipulation
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>

void main()
{
	clrscr();
	char str[20];
	cout<<"\n\tEnter a string (max. 20 characters) : ";
	gets(str);
	for (int i=0; str[i]!='\0'; i++) {
		if (islower(str[i]))
			str[i]=toupper(str[i]);
		else if (isupper(str[i]))
			str[i]=tolower(str[i]);
		else if (str[i] == ' ')
			str[i]='#';
	}
	cout<<"\n\tConverted String: ";
	puts(str);
	getch();
}