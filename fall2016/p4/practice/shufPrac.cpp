#include <cstdio>   // printf
#include <cstdlib>  // rand
#include <time.h>   // time
#include <getopt.h> // to parse long arguments.
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// randomly permute vals'
void permute(vector<string>& v){
    int i = 0;
    int random;
    srand(time(0));
    while(v.size()>i){
     random = rand() % v.size();
      cout << v[random] << endl;
      v.erase(v.begin()+random);
  }
}

/*void print(vector<string>& v){
      for(int i = 0; i < v.size(); i++){
      cout<<v[i]<<" ";
    }cout<<endl;}*/

int main(){
    //int a = 0;
    string s;
    vector <string> v;  // value container

    while (cin >> s){
      v.push_back(s);
       // a++;
    }
    cout << "\n";
   //cout << a << " elements entered!\n\n";

    permute(v);
return 0;
    }