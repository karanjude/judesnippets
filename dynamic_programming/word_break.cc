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

int main(){
  map <string, bool> dict;

  dict.insert(make_pair("programcree", true));
  dict.insert(make_pair("program", true));
  dict.insert(make_pair("creek", true));

  cout << endl <<  print_sentence(dict, "programcreek");
}
