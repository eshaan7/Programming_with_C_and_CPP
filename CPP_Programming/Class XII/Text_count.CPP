/* Programmaers' name: Eshaan & Anviti
   Topic: Program to accept a text file name; Frequency table
   Date: 18/09/2017
*/


#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>

int c_char=0,c_up=0,c_dig=0,c_word=0,c_str=0;

void wordcount(char file[])
{
	ifstream fin;
	char word[30];
	fin.open(file);
	while (!fin.eof())
	{
		fin>>word;
		c_word++;
	}
	cout<<"\n\t\tNo. of words in the file: "<<c_word;
	fin.close();
}

void count(char file[])
{
	ifstream fin;
	fin.open(file);
	char ch;
	while (!fin.eof()) {
		fin.get(ch);
		c_char++;
		if (isupper(ch))
			c_up++;
		if (isdigit(ch))
			c_dig++;
	}
	fin.close();
	cout<<"\n\t\tNo. of characters: "<<c_char
	    <<"\n\t\tNo. of uppercase characters: "<<c_up
		<<"\n\t\tNo. of digits: "<<c_dig;
}

void countlines(char file[])
{
	ifstream fin;
	char str[80];
	fin.open(file);
	while (!fin.eof())
	{
		fin.getline(str,80);
		c_str++;
	}
	cout<<"\n\t\tNo. of lines in the file: "<<c_str;
	fin.close();
}

void main()
{
	clrscr();
	char file[10];
	cout<<"\n\nEnter name of text file: ";
	gets(file);
	ifstream fin;
	fin.open(file);
	char ch;
	cout<<"\n\tText file: ";
	while (!fin.eof()) {
		fin.get(ch);
		cout<<ch;
	}
	fin.close();
	count(file);
	wordcount(file);
	countlines(file);
	getch();
}