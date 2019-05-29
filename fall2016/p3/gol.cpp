/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * Work:
 * Update - Matthew and Candy 
 * initFromFile - Candy
 * dumpState - Andrew
 * 
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 * Matthew - at least 5 hours each day since the project was given
 * Candy- 10+ hours a week.
 *
 * #sources:
 * Matthew's Mentor Sid
 * www.cplusplus.com/doc/tutorials/files/
 * www.cplusplsu.com/doc/tutorials/cstdio/
 * candy's Mentor Kem 
 * programiz.com thenewboston youtune channels stackoverflow
 * Andrew's Mentor (mentor name)
 */

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; 				// if > 0, fast forward to this generation.
string wfilename =  "/tmp/gol-world-current"; 	// write state here 
FILE* fworld = 0; 				// handle to file wfilename. 
string initfilename = "/tmp/gol-world-current"; // read initial state from here.

//create the new state based on the initial state
vector<vector<bool> > update(vector<vector<bool> >& g){
	//clear new state befor adding new values
	vector<vector<bool> > q;
	vector<bool> rows;
	//loop through all the cells in the grid
	for(int i=0; i<g.size();i++){
		for(int j =0; j< g[i].size();j++){
			//count the neighboring cells that are alive
			int counter=0, length =g.size(),width = g[i].size();
			for(int row=i-1; row <= i+1; row++){
				for(int column=j-1; column <= j+1; column++){
					if(g[row % length][column % width] && !(row == i && column == j)){ counter++;
					};
				};
			};
			//check to see what conditions the cuttent cell meets 
			//to determine the value put in the new state
				if(g[i][j] == true){
					if((counter==2)||(counter==3)){rows.push_back(true);}
					else{rows.push_back(false);};
				}else{
					if(counter==3){rows.push_back(true);}
					else{rows.push_back(false);};
					break;
				};
			};
		//place row in new state and clear row for next iteration
		q.push_back(rows); rows.clear();
	};
	return q;
};

//create the initial state from the file 
vector<vector<bool> >  initFromFile(/*const string& fname*/){
	//open file for reading 
	string line;
	ifstream myfile;
	myfile.open("res/glider-40x20");
	vector< vector<bool> >grid;
	vector<bool> row;
	while(getline(myfile,line)){
		for(int i=0; i< line.length(); i++ ){
			char check = char(line[i]);
			switch(check) {
       			case '.':
    	   			row.push_back(false);
           			break;
       			default:
           			row.push_back(true);
           			break;  
			};
		};
           	grid.push_back(row);
			row.clear();
   };
	return grid;
};

//write world to "tmp/gol-world-current" 
//so we can see the ittereations
void dumpState(vector<vector<bool> >& a){
//initialize string and look at each cell 
	ofstream myfile;
	myfile.open("/tmp/gol-world-current", ios::trunc);
	string world;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			//build string here
			if(a[i][j] == false){
			world += ".";
			}
			else{
				world += "0";
			};
		};
		world+="\n";
	};
	//somehow print string to file 
	myfile << world;
	myfile.close();

};
char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	};
	//WRITE ALL CODE HERE FOR MAIN FUNCTION 
	//ALL VARIABLES HAVE BEEN DECLARED AT THIS POINT
	vector<vector<bool> > init;
	init = initFromFile();
	
	while(1){
	init = update(init);
	dumpState(init);
	sleep(1);
	}
	
	return 0;
}
