/*
GAME OBJECTIVE:
PLAYERS PLACE BETS AND BET ON WHETHER DICE ROLL WILL BE ODD OR EVEN 
IF PLAYER GOE BANKRUPT THEY LOSE 
IF THE PLAYER HAS MORE THAT THE COMPUTER THE COMPUTER:
WILL ONT EXCEED 50% OF THE BANK VAL FOR ANY GIVEN BET 
IF THE PLAYER HAS LESS:
THE COMPUTER CAN BET UP TO 100% OF BANK VAL
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int numGen(int x){ return rand()%x; };

int bets( int bank ){
	cout<<"Bank: "<<bank<<endl;
	int bet; 
	cin>>bet;
	if(bet > bank || bet < 0){
		cout<<"Invalid input!\n";
		bets(bank);
	}else{ return bet; }
}


int main(){
	srand(time(NULL));
	int p1[3] {500,0,0}, p2[3] = new p1 , bet=0;
	

	while(p1_bank > 0 && p2_bank > 0){
		cout<<"Place bets!\n";
		
		p1[1] =  bets(p1[0]);
		
		(p1[0] > p2[0] )? p2[1] = (numGen( (p2[0]/2) )+1): p2[1] = (numGen( p2[0] )+1);
		
		cout<<"The die is cast...\n";
		while(bet != 2 || bet != 1){ 
			cout<<"Enter:\n1 for Odd \n2 for Even\n";
			cin>>bet;
			if(bet > 2 || bet < 1) cout<<"Invalid input!\n";
		};

		p2[2] = numGen(2)+1;
		dice = numGen(2)+1;	
		
		//Show Initial values
		cout<<"Player Bank befor: "<<p1[0]<< 
		cout<<"\nComputer Bank befor: "<<p2[0]<<endl;
		
		//validate and adjust banks
		(p1[2] == dice)? p1[0]+=p1[1]: p1[0]-=p1[1];
		(p2[2] == dice)? p2[0]+=p2[1]: p2[0]-=p2[1];
		
		//Show adjusted values
		cout<<"Player Bank after: "<<p1[0]<<"\nComputer Bank after: "<<p2[0]<<endl;

		p1[1]=0, p1[2]=0, p2[1]=0, p2[2]=0;
	}

	return 0;
}
