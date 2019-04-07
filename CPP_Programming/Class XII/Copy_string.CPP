#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

void main()
{
	clrscr();
	char fname[20], word[30], ch;
	int n;
	cout<<"\n\nEnter name of text file(with \".txt\"): ";
	gets(fname);
	ifstream fin;
	ofstream fout;
	fin.open(fname);
	fout.open("copy.txt");
	cout<<"\n\tText file: "<<endl;
	while (!fin.eof()) {
		fin.get(ch);
		cout<<ch;
	}
	fin.close();
	fin.open(fname);
	while (!fin.eof()) {
		fin>>word;
		n=strlen(word)-1;
		if (!(word[n]=='a' || word[n]=='e' || word[n]=='i' || word[n]=='o' || word[n]=='u') )
			fout<<word<<" ";
	}
	fout.close();
	fin.close();
	fin.open("copy.txt");
	cout<<"\n\n\tThe updated text file is: "<<endl;
	while (!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
	}
	fin.close();
	getch();
}
	