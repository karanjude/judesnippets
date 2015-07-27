#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap_rain(int * v, int n){
  vector<int> left(n, 0);
  vector<int> right(n, 0);
  int max = 0;

  max = v[0];
  left[0] = v[0];

  for(int i = 1;i < n;i++){
    if(v[i] > max){
      max = v[i];
      left[i] = max;
    }else{
      left[i] = max;
    }
  }

  max = v[n-1];
  left[n-1] = max;
  for(int i = n-2;i >= 0;i--){
    if(v[i] > max){
      max = v[i];
      right[i] = max;
    }else{
      right[i] = max;
    }
  }
  
  int r = 0;
  for(int i = 0;i < n;i++){
    r += min(left[i], right[i]) - v[i];
  }
  
  return r;
}

int main(){
  int v[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << endl << trap_rain(v , sizeof(v) / sizeof(int));
}
