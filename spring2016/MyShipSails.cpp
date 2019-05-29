#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void Prompt(vector<vector<string>>& Players, vector<string>& Options, vector<string> CardDrop){
	for(int i=0; i<Players.size(); i++){
	    for(int j=0; j<Players[i].size();j++){
	        cout<<Players[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	

/*
	string C;
	for(int i=0; i<Players[0].size(); i++){
	    cout<<Options[i]<<Players[0][i]<<" ";if(i == (Players[0].size() - 1) )cout<<"\n";
	}cout<<"Which one to replace? "; //cin>> C;
    
    for(int i=0; i<Options.size(); i++){
        if(C == Options[i]){
            string card = Players[0][i];
            //CardDrop.push_back(Players[0][i]); Players[0].erase(remove(Players[0].begin(),Players[0].end, card), Players[0].end());
        }else if( C == "?"){
            for(int i=0; i<Players.size(); i++){
                for(int j=0; j<Players[i].size(); j++){
                    cout<<"("<<Options[j]<<") "<<Players[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    }
*/    
}

void GenPlayers(vector<string>& Deck, vector<vector<string>>& Players){
    for(int i=0; i<5; i++){
        vector<string> Player;
        for(int i= 0; i<7;i++) {
            int index = rand()%52; 
            string Card = Deck[index]; // gives me one card. 
		    Player.push_back(Card);     //will push the vector Hand back and add the card in
		    Deck.erase(Deck.begin() + index);     //add card to picked pile 
        }     
        Players.push_back(Player);
    }
}

void SuitCounter(vector<vector<string>>& Players, vector<vector<int>>& SuitCount){
vector<char> Suit= {'H','C','D','S'}; vector<int>SuitsInHand; int Counter=0;
    for(int i=1; i<5; i++){
        for(int j=0; j<Suit.size(); j++){
            for(int k=0; k<Players[i].size(); k++){
                if(Players[i][k].at(0) == Suit[j]) Counter += 1;
            }
            SuitsInHand.push_back(Counter); Counter = 0;
        }
        SuitCount.push_back(SuitsInHand); SuitsInHand.clear();
    }
}

void cardExchange(vector<vector<string>>& Players, vector<vector<int>>& SuitCount, vector<string>& CardDrop){
    int INDEX, INDEX1,INDEX2; vector<char> Suit = {'H','C','D','S'}; int pos=0;string card;
    for(int i=1; i<Players.size(); i++){
        
        INDEX1 = min(SuitCount[i-1][0],SuitCount[i-1][1]);                                  //set index1 to the smallets non-zero value of the first set 
            if(min(SuitCount[i-1][0],SuitCount[i-1][1]) <= 0) INDEX1 = max(SuitCount[i-1][0],SuitCount[i-1][1]);
        
        INDEX2 = min(SuitCount[i-1][2],SuitCount[i-1][3]);                                  //set index2 to the smallets non-zero value of the second set 
            if(min(SuitCount[i-1][2],SuitCount[i-1][3]) <= 0) INDEX2 = max(SuitCount[i-1][2],SuitCount[i-1][3]);
        
        INDEX = min(INDEX1,INDEX2);                                                         //primary index set to the smallest vaalue in suit count
        
        for(int j=0; j<SuitCount[i-1].size();j++)if(INDEX == SuitCount[i-1][j]) INDEX=j;    //redefine index as the index inwhich the num apears in suitcount
        cout<<INDEX1<<" "<<INDEX2<<" \n"
            <<"The index of the suit is: "<<INDEX
            <<"\nWhich corresponds to: "<<Suit[INDEX]<<endl;
        for(int j=0; j< Players[i].size(); j++){
            
             if(Players[i][j].at(0) == Suit[INDEX]){ 
                 card = Players[i][j]; 
                 cout<<card<<" "<< card.at(0)<<" "<< Suit[INDEX]<<" \n\n"; 
                 CardDrop.push_back(card); 
                 Players[i].erase(remove(Players[i].begin(), Players[i].end(), card), Players[i].end()); 
                 break;
                 
             }
        
            
        }
    }
//    for(){}     SWAP CARDS
}
 
int main() {
    srand(time(0));
	vector<vector<string>> Players; vector<vector<int>> SuitCount; vector<string> Options = {"a","b","c","d","e","f","g"}; vector<string> Deck;vector<string> CardDrop;
	Deck={"HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK","CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK"};
	
	GenPlayers(Deck, Players); //gives all player their 7 random card
    
    Prompt(Players, Options, CardDrop);
	
	cout<<"\n"; 
	
	SuitCounter(Players, SuitCount);     //Count the number of each suit in players 1 - 4 
    
    cout<<"H C D S\n"; 

    for(int i=0; i<SuitCount.size(); i++){
        for(int j=0; j<SuitCount[i].size(); j++){
            cout<<SuitCount[i][j]<<" ";
        }
        cout<<"\n";
    }
    
cout<<"\n";
    
    cardExchange( Players, SuitCount, CardDrop);
    
    cout<<"\n";
    
    for(int i=0; i<CardDrop.size(); i++)cout<<CardDrop[i]<<" ";

    cout<<"\n\n";    
    
    Prompt(Players, Options, CardDrop);

    cout<<"\n";
	return 0;
}
