#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	double a, b, c, r1, r2;
	cout<<"Enter A, B & C: \n";
	cin >> a >> b >> c;
	try{	
		if(a==0) throw 1;
		if( b*b < 4*a*c ) throw 2;

		r1 = (-b + sqrt( b*b - 4*a*c ) ) / (2*a);
		r2 = (-b - sqrt( b*b - 4*a*c ) ) / (2*a);
		cout<<"Your roots are: " << r1 << " and " << r2 << endl;

	}catch(int x){
		switch(x){
			case 1:
				cout<<"Error: Zero devision!"<<endl;
			break;
			case 2:
				cout<<"Error: imaginary number!"<<endl;
			break;
		};
	}
	
	
	return 0;
}


//x= { -b (+/-) [ {b^2 -  4(a)(c)} ^ (1/2) ] } / 2a

