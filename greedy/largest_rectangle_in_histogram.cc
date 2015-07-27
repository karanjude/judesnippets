#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max_histogram(int * v, int n){
  int i = 0;

  stack<int> s;
  int m = 0;

  while(i < n){
    if(s.empty() || v[i] >= v[s.top()]){
      s.push(i);
      i++;
    }else{
      int p = s.top();s.pop();
      int h = v[p];
      int w = s.empty() ? i : i - s.top() - 1;
      m = max(h * w, m);
    }
  }

  while(!s.empty()){
    int p = s.top();s.pop();
    int h = v[p];
    int w = s.empty() ? i : i - s.top() - 1;
    m = max(h * w, m);
  }
  
  return m;
}

int main(){
  int v[] = {2,1,5,6,2,3};
  cout << endl << max_histogram(v , sizeof(v) / sizeof(int));
}
