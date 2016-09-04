//File Name: RPS.cpp
//Author: Eshaan Bansal
//Description: Rock Paper Scissors Game

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	
	char confirm,confirm2;
	string username= "";
	string userchoice= "";
	string computerchoice = "";
	string result = "";
	// Fancy printed title, well as fancy as I can do.
	cout<<"\n\n\t\t\t--------------------------------------" <<endl;
	cout<<"\t\t\t-- Lets play Rock, Paper, Scissors! --" <<endl;
	cout<<"\t\t\t--------------------------------------" <<endl;
	cout<<"\nRULES: \"rock crushes scissors\", \"paper covers rock\", \"scissors cut paper\"";
	cout<<"\n\nWhat\'s your good name? >> ";
	cin>>username;
	cout<<"\nWould you like to play \'Rock, Paper, Scissors\' ? (y/N): ";
	cin>>confirm;
	do {
	if(confirm=='y' || confirm=='Y') {
		cout<<"\nDo you choose rock, paper or scissors? >> ";
		cin>>userchoice;
		// Generating computerchoice
		srand(time(NULL));
		float Rand_compChoice=(float)rand() / (float)(RAND_MAX);
		if (Rand_compChoice < 0.38 && Rand_compChoice < 0.71)
            		computerchoice = "rock";
		else if (Rand_compChoice<= 0.71 && Rand_compChoice > 0.38)
            		computerchoice = "paper";
		else
            		computerchoice = "scissors";
		// Comparing userchoice and computerchoice
		if (userchoice==computerchoice) {
			result="The result is a tie!";
		}
		else if (userchoice == "rock") {
			if (computerchoice == "scissors")
				result="Rock crushes scissors! User wins!";
			else
				result="Paper covers rock! Computer wins!";
		}
		else if (userchoice == "paper") {
                	if(computerchoice == "rock") 
                    		result="Paper covers rock! User wins";
                	else  
                    		result="Scissors cuts paper! Computer wins!"; 
                }
		else if(userchoice == "scissors") {
                	if(computerchoice== "rock") 
                    		result="Rock crushes scissors! Computer wins!";
                	else 
                    		result="Scissors cut paper! User wins";
		}          
		// Outcomes
		cout<<"\n\n\t\t\t--------------------------------------" <<endl;
		cout<<"\t\t\t\t-- "<<username<<" Vs. Computer --" <<endl;
		cout<<"\t\t\t--------------------------------------" <<endl;
		cout<<"\n\tUser: "<<userchoice;
		cout<<"\n\tComputer: "<<computerchoice;
		cout<<"\n\tResult: "<<result<<endl;
		cout<<"\n\nFancy another game, mate? (y/N) >> ";
		cin>>confirm2;
		if(confirm2=='n' || confirm2=='N')
			cout<<"\n\n\t\tWell, See ya around then. Cheerio!\n\n\n";
	}
	else if (confirm=='n' || confirm=='N')
		cout<<"\n\n\t\tWell, See ya around then. Cheerio!\n\n\n";
	else
		cout<<"\nCorrect inputs (y|Y|n|N). Please try again.\n\n\n"; 
	} while(confirm2=='y' || confirm2=='Y');
	return 0;
}
		
				
		
			
	
	
