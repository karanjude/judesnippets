#include <string>
#include <vector>
#include <iostream>

using namespace std;


int num_distinct_sub_sequences(string& s1, string& s2){
  vector< vector<int> > table;
  for(int i = 0; i <= s1.length();i++){
    vector<int> vv(s2.length() + 1,0);
    table.push_back(vv);
  }

  for(int i = 0; i < table.size();i++){
    table[i][0] = 1;
  }

  for(int i = 1;i < s1.length();i++){
    for(int j = 1; j< s2.length();j++){
      if(s1[i] == s2[j]){
	table[i][j] = table[i-1][j-1] + table[i-1][j];
      }else{
	table[i][j] = table[i-1][j];
      }
    }
  }

  return table[s1.length()-1][s2.length()-1];
}

int main(){
  string s1 = "rabbbit";
  string s2 = "rabbit";
  cout << endl << num_distinct_sub_sequences(s1,s2);
  return 0;
}
