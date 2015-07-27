#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

string print_sentence(map < string, bool> & dict, const string& in){
  cout << endl << "input : " << in;
  
  string prefix = "";
  string rest = "";

  int len = in.length();
  for(int i = 0; i < len; i++){
    string prefix = in.substr(0, i+1);

    if(dict.find(prefix) == dict.end()){
      continue;
    }

    cout << endl << "prefix : " << prefix;

    string suffix = in.substr(i+1, len - i);
 
    string rest = print_sentence(dict, suffix);
    
    cout << ">>" << prefix + " " << rest;

  }

  return prefix + " " + rest;
}

int max_subarray(int *c, int len){
  int sum = c[0];
  int nsum = c[0];
  
  for(int i = 1; i < len;i++){
    nsum = max(nsum + c[i], c[i]);
    sum = max(sum, nsum);
  }

  return sum;
}

int main(){
  int c[] = {-2,1,-3,4,-1,2,1,-5,4};
  int n = sizeof(c) / sizeof(int);
  cout << endl <<  max_subarray(c, n); 
}
