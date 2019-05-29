/*
* 
* OBJECTIVE: CONTINNUOUSLY TAKE INPUT UNTIL BLANK INPUT IS TAKEN 
* THEN TAKE TEXT BOX WIDTH NO SMALLER THAN THE LARGEST WORD 
* AND FIT THE WORDS INNTO THE TEXT BOX 
*  
*/
#include <iostream>
#include <vector>
using namespace std;

//To take STD input
vector<string> getText(){
	vector<string> Input;
	string text;

	cout<<"Input taken till blank:\n";
	
	while( getline(cin,text)  ){
		if(text != ""){ 
			Input.push_back(text);
		}else{ 
			cout<<"Ending input phase\n\n";
			break;
		};
	}
	return Input;
};

//To help trivialize printinng the text box
vector<string> delimitText(vector<string> x){
	vector<string> vect;
	string text;
	for(int i=0; i<x.size();i++){

		for(int j=0; j<x[i].size();j++){
			
			if( x[i][j] == char(32) ){
				vect.push_back(text);
				text.clear();

			}else if( (j+1) == x[i].size() ){
				text+=x[i][j];
				vect.push_back(text);
				text.clear();

			}else{
				text+=x[i][j];
			}
		};
		
	};	
	return vect;
};


void Print_Text_Box(vector<string> vect){
	
	int base = 0,width;
	// To create a litmus test for valid input
	for (int i = 0; i < vect.size(); ++i){ 
		( base < vect[i].size() )? base = vect[i].size(): NULL ;
	};
	int counter = base;
	cout<<"Minimum box width: "<<base<<"\nEnter desired box width: ";
	cin>>width;
		
	//fix to limit input type to INT only
	if( width<base ){ cout<<"Invalid input!!\n"; Print_Text_Box(vect);}

//////////////////////////////////////////////
	cout<<"|";
	for (int i = 0; i < vect.size(); i++){
		if( vect[i].size() <= counter ){ 
			cout << vect[i] << " "; 
			counter -= vect[i].size();
		} else{  
			for (int i = 0; i < counter; i++){ cout << " "; }
			cout << "|\n|" ; counter = base;	
		}
	}

};

int main() {

	vector<string> text = getText();
	text = delimitText(text);

	for (int i = 0; i < text.size(); i++) cout<<text[i]<<" ";
		cout<<endl;
	Print_Text_Box(text);
	

	return 0;
}
