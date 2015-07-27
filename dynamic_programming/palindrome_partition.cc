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

void palindrome_partitions(string& s){
  vector< vector<int> > t;
  for(int i = 0 ;i < s.length();i++){
    vector<int> vv(s.length(), 0);
    t.push_back(vv);
  }
  
  int n = s.length();
  for(int i = 0; i < n;i++){
    t[i][i] = 1;
  }

  for(int i = 0;i < n - 1;i++){
    if(s[i] == s[i+1]){
      t[i][i+1] = 1;
    }
  }

  for(int i = 0;i < n;i++){
    for(int len = 3; len <= n;len++){
      int j = i + len - 1;

      if(j >= n)
	continue;

      if(s[i] == s[j]){
	t[i][j] = t[i+1][j-1];
      }else{
	t[i][j] = 0;
      }

      if(t[i][j]){
	cout << endl << s.substr(i, len);
      }
    }
  }

}

int main(){
  string s = "aaab";
  palindrome_partitions(s);
}
