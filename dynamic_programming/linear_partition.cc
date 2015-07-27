#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sum(int* c, int start, int end, int n){
  int r = 0;
  for(int i = start; i < end && i < n;i++){
    r += c[i];
  }
  return r;
}


int max_partition(int* c, int n, int k){
  vector< vector<int> > table;

  for(int i = 0; i < n+1;i++){
    vector<int> vv(k+1,0);
    table.push_back(vv);
  }

  // if k = 1, 
  for(int i = 1;i <= n;i++){
    table[i][1] = sum(c, 0, i, n);
  }
  
  for(int i = 1; i <= k;i++){
    table[1][i] = c[0];
  }

  int r = INT_MAX;


  // partition for range 1..j , using 1..kk partitions
  for(int j = 2; j <= n;j++){
    for(int kk = 2; kk <= k; kk++){
      
      r = INT_MAX;
      for(int pos = 1; pos <= j; pos++){
	int xx = max(table[pos][kk-1], sum(c,0,j,n) - sum(c,0,pos,n));
	r = min(r , xx);
      }
      table[j][kk] = r; 
    }
  }

  return table[n][k];
}

int main(){
  int c[] = {100,200,300,400,500,600,700,800,900};
  int len = sizeof(c) / sizeof(int);
  
  cout << endl << endl << max_partition(c, len, 3);
  return 0;
}
