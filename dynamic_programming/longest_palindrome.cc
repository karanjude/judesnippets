#include <string>
#include <vector>
#include <iostream>

using namespace std;


int longest_palindrome(string& s1){
  vector< vector<int> > table;

  for(int i = 0; i <= s1.length();i++){
    vector<int> vv(s1.length(),0);
    table.push_back(vv);
  }

  for(int i = 0; i < table.size();i++){
    table[i][i] = 1;
  }

  int max_len = 1;

  for(int i = 0; i < s1.length() - 1;i++){
    if(s1[i] == s1[i+1]){
      table[i][i+1] = 1;
      max_len = 2;
    }
  }

  for(int len = 3; len < s1.length(); len++){
    for(int i = 0;i < s1.length() - len;i++){
      int j = i + len - 1;

      if(s1[i] == s1[j]){
	table[i][j] = table[i+1][j-1];
	if(table[i][j] == 1 && len > max_len){
	  max_len = len;
	}
      }else{
	table[i][j] = 0;
      }
    }
  }

  return max_len;
}

int main(){
  string s1 = "rabbbait";
  
  cout << endl << longest_palindrome(s1);
  return 0;
}
