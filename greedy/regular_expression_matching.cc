#include <iostream>
#include <string>

using namespace std;

bool match(string s, string pat){

  int i = -1;
  
  if(pat.length() == 0){
    return s.length() == 0;
  }

  if(pat.length() == 1 || pat[1] != '*'){
    if(s.length() < 1 || (pat[0] != '.' && s[0] != pat[0]))
      return false;

    return match(s.substr(1, string::npos) , pat.substr(1, string::npos));

  }else{
    int n = s.length();
    
    while(i < n && (i < 0 || '.' == pat[0] || pat[0] == s[i])){
      if(match(s.substr(i+1, string::npos) , pat.substr(2, string::npos))){
	return true;
      }
      i++;
    }
    return false;
  }





}

int main(){

  cout << endl << match("aa", "a*"); // true
  cout << endl << match("ab", "a*"); // false
  cout << endl << match("abb", "a*"); // false
  cout << endl << match("abba", "a*"); // false
  cout << endl << match("abbb", "ab*"); // true
  cout << endl << match("aaaa", "a*"); 
  cout << endl << match("aaab", "a*aab"); 
}
