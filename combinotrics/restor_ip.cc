#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void print_v(vector<int> & r){
  cout << endl;
  for(int i = 0; i != r.size();i++){
    cout << " " << r[i];
  }
}

bool valid(string val){
  int v = 0;
  for(int i = 0; i < val.length();i++){
    int x = (10 * v) + (val[i] - '0');
    v = x;
  }

  if(v >= 0 && v <= 255)
    return true;

  return false;
}

void possible_ip(string ip_address, int slot, int start, string r){
  if(slot == 4){
    cout << endl << r + ip_address;
    return;
  }

    int max_valid_suffix_length = (4 - slot) * 3;

    for(int len = 1; len <= 3;len++){
      if((ip_address.length() - len) <= max_valid_suffix_length){
	string local_prefix = ip_address.substr(0,len);
	string suffix = ip_address.substr(len,string::npos);

	if(!valid(local_prefix))
	  continue;

	possible_ip(suffix, slot + 1, start + len,r + local_prefix + ".");
      }
    }

}


int main(){
  string s = "25525511135";
  possible_ip(s, 1, 0, "");

  return 0;
}
