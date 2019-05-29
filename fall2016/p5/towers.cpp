/*
 * CSc103 Project 7: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 *  10
 */

// TODO: write the program.
#include <iostream>
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function
#include <typeinfo>
using namespace std;


void hanoi(int a, int b, int c, int d){
    if (a != 0) {
        hanoi(a-1,b,d,c);
        cout<< b << "\t" << d<<endl;
        hanoi(a-1,c,b,d);
    }
};

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {;/
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=0,end=0,tmp=0; 
	/* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				return 1;
		}
	}

	/*TODO: now that you have the options and arguments,
	 * solve the puzzle. 
	 */
    if( (start>0 && start<4) && (end>0 && end<4) && (start!=end) ){
        switch(start){
            case 1:
                (end == 2)? tmp=3:tmp=2;
                break;
            case 2:
                (end == 1)? tmp=3:tmp=1;
                break;
            case 3:
                (end == 1)? tmp=2:tmp=1;
                break;
        }
        hanoi(n,start,tmp,end);
    }else{cout<<"Invalid input!\n";};
    return 0;	
}
