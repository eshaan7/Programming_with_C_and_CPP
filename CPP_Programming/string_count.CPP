// String manipulation

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>

void main()
{
	clrscr();
	int alpha=0, non_alpha=0, small_alpha=0, cap_alpha=0, words=0;
	char str[20];
	cout<<"\n\tEnter a string (max. 20 characters) : ";
	gets(str);
	for (int i=0; str[i]!='\0'; i++) {
		if (islower(str[i])) {
			small_alpha++; // Number of small alphabets
			alpha++;
		}
		else if (isupper(str[i])) {
			cap_alpha++;  // Number of capital alphabets
			alpha++;
		}
		else if (str[i] == ' ') {
			words++;
			non_alpha++; // Counting space as non-alphabetic
		}
		else if (isdigit(str[i])) {
			non_alpha++;
		}
	}
	cout<<"\n\n\tNo. of capital alphabets: "<<cap_alpha;
	cout<<"\n\tNo. of small alphabets: "<<small_alpha;
	cout<<"\n\tNo. of non-alphabets(including spaces): "<<non_alpha;
	cout<<"\n\tNo. of words: "<<words+1; // No. of words= no. of spaces + 1
	getch();
}