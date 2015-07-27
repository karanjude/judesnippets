#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max_proft(int *v , int n){
  int profit = 0;
  int min_element = INT_MAX;

  for(int i = 0;i < n;i++){
    profit = max(profit, v[i] - min_element);
    min_element = min(min_element, v[i]);
  }

  return profit;
}

int main(){
  int v[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << endl << trap_rain(v , sizeof(v) / sizeof(int));
}
