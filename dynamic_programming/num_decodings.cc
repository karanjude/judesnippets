#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool is_valid(string s){
  if(s == "0")
    return false;

  istringstream iss(s);
  int v;
  iss >> v;

  return v >= 1 && v <= 26;
}

int num_decodings(string s){
  if(s.length() == 0)
    return 0;

  vector<int> v(s.length(), 0);
  
  v[0] = 1;
  if(is_valid(s.substr(0,1))){
    v[1] = 1;
  }else{
    v[1] = 0;
  }
    
  for(int i = 2;i < s.length();i++){
    if(is_valid(s.substr(i-1,1))){
      v[i] += v[i-1];
    }
    
    if(is_valid(s.substr(i-2,2))){
      v[i] += v[i-2];
    }
  }
  
  return v[s.length() - 1];
}

int main(){
  cout << endl << num_decodings("126");
  cout << endl << num_decodings("1264");
  cout << endl << num_decodings("26");
}
