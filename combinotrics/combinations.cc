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

void combinations(vector<int>& candidate_set, vector<int> result, int k, vector<int>& used, set< vector<int> > &r){
  if(result.size() == k){
    vector<int> v(result.begin(), result.end());
    sort(v.begin(), v.end());
    pair< set< vector<int> >::iterator, bool> ret = r.insert(v);

    if(ret.second == true)
      print_v(result);
    return;
  }

  for(int i = 0;i < candidate_set.size();i++){
    if(result.size() < k) {
      if(used[i] == 1)
	continue;
 
      used[i] = 1;
      result.push_back(candidate_set[i]);
      combinations(candidate_set, result, k, used, r);
      result.pop_back();
      used[i] = 0;
    }
  }
}


int main(){
  int n = 4;

  vector<int> candidate_set;
  for(int i = 1;i <= n;i++)
    candidate_set.push_back(i);

  
  vector<int> used(candidate_set.size(), 0);
  vector<int> result;
  set< vector<int> > r;
  combinations(candidate_set, result , 2, used, r);


  return 0;
}
