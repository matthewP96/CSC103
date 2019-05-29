#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
#include <iostream>
#include <set>
#include <strings.h>
#include <string>
using namespace std;

//sort text in file by character:
//# first 		48 - 57
//LC second		97 - 122
//CAPS third	65 - 90
/*
void LineSsort(set<sting>& s){
	set<string>::iterator i;
	for(i = s.begin(); i != s.edd(); i++){
		//numbers first
		//		if(i[0] == 48 - 57 )
		//		CHECK FOR DUPLICATES AND GROUP

		//lowercase second
		//		if(i[0] ==  97 - 122 )
		//		CHECK FOR DUPLICATES AND GROUP

		// uppercase third
		//		if(i[0] ==  65 - 90 )		
		//		CHECK FOR DUPLICATES AND GROUP
	};
};
*/
void CharSort(set<string>& s);

int main(int argc, char* argv[]){
	//set to hold the values from file
	set<string> input;
	set<string>::iterator i;
	input.insert("Hello");
	i = input.begin();
	cout<< *i << endl;
	/*
	string line;
	//taking input from file
	fstream file;
	file.open(argv[1]);
	//build set from file 
	while(getline(file,line)){
		input.insert(line);
	};
	*/


	return 0;
};
