#include <iostream>
using namespace std;

int main(){
	double feet, inch, weight, hight, BMI;
	
	cout << "Enter your height in feet: " ;
	cin >> feet;
	cout << "Enter your height in inches: " ;
	cin >> inch;
	cout << "Enter your weight in pounds: " ;
	cin >> weight;
	try{
		if(feet == 0 && inch == 0 || weight == 0) throw 422;

		hight = 12 * feet + inch;
		BMI = (weight/(hight * hight)) * 703;
		
		cout << "Your BMI is " << BMI << "%`" << endl;

	}catch(int x){
		cout<<"Invalid inpupt - Error: "<< x;
	}

	return 0;
}

