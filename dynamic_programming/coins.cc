#include <string>
#include <vector>
#include <iostream>

using namespace std;


int max_coins(int* c, int len){
  vector< vector<int> > table;

  for(int i = 0; i < len;i++){
    vector<int> vv(len,0);
    table.push_back(vv);
  }

  int i,j;

  for(int l = 0; l < len;l++){
    for(int i = 0, j = l; j < len; i++, j++){

      // I take left coin initially
      // o takes left
      int o_left = (i + 2 < len) ? table[i+2][j] : 0;
      // o takes right
      int o_right = ((i+1<len) && (j-1>=0)) ? table[i+1][j-1] : 0;
      int left = c[i] + min(o_left, o_right);

      // I take right coin initially
      // o takes left
      o_left = ((i+1<len) && (j-1>=0)) ? table[i+1][j-1] : 0;
      // o takes right
		o_right = (j-2 >= 0) ? table[i][j-2] : 0;
      int right = c[j] + min(o_left, o_right);

      table[i][j] = max(left, right);

    }
  }

	cout << endl;

  return table[0][len-1];
}

int main(){
  int c[] = {3,2,2,3,1,2};
  int len = sizeof(c) / sizeof(int);
  
  cout << endl << endl << max_coins(c, len);
  return 0;
}
