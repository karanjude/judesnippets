#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

vector<int> computeLPSArray(const string& pattern){
  vector<int> lps(pattern.size());

  int len = 0;
  int i = 1;
  int M = pattern.size();

  lps[len] = 0;
  i = 1;

  while(i < M){
    if(pattern[i] == pattern[len]){
      len++;
      lps[i] = len;
      i++;
    }else{
      if(len != 0){
	len = lps[len - 1];
      }else{
	lps[i] = 0;
	i++;
      }
    }
  }

  return lps;
  
}

void print(vector<int> & v1){
  cout << endl;
  for(vector<int>::iterator i = v1.begin(); i != v1.end(); i++){
    cout << " " << *i;
  }
}

void period(int len, vector<int> & lps){
  for(int i = 1;i < len;i++){
    int k = lps[i];
    int p = (i+1) - k;
    if ( (((i+1) % p) == 0) && k > 0 ){
      cout << endl << i+1 << " " << (i+1)/p;
    }
  }
  cout << endl;
}

int main(){
  string s1 = "aaa";
  vector<int> v1 = computeLPSArray(s1);
  //print(v1);
  cout << endl << s1;
  period(s1.size(), v1);

  string s2 = "aabaabaabaab";
  vector<int> v2 = computeLPSArray(s2);
  //print(v2);
  cout << endl << s2;
  period(s2.size(), v2);

}
