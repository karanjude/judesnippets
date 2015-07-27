#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_v(vector<int> & r){
  cout << endl;
  for(int i = 0; i != r.size();i++){
    cout << " " << r[i];
  }
}

void combinations_sum(vector<int>& candidate_set, int number, vector<int> result, 
		      bool sorted, bool unique, vector<int>& used, int k){
  if(k > 0 && result.size() > k){
    return;
  }

  if(number <= 0){

    if(k > 0){
      if(result.size() == k)
	print_v(result);
    }else{
      print_v(result);
    }

    return;
  }

  for(int i = 0;i < candidate_set.size();i++){
    if(number - candidate_set[i] >= 0){

      if(sorted && result.size() > 0 && candidate_set[i] < result.back())
	continue;

      if(unique && used[i] == 1){
	continue;
      }
	
      if(unique){
	used[i] = 1;
      }

      result.push_back(candidate_set[i]);
      combinations_sum(candidate_set, number - candidate_set[i], result, sorted, unique, used, k);
      result.pop_back();

      if(unique){
	used[i] = 0;
      }

    }
  }
}


int main(){
  vector<int> candidate_set;
  for(int i = 1;i <= 9;i++)
    candidate_set.push_back(i);

  sort(candidate_set.begin(), candidate_set.end());

  vector<int> result;
  vector<int> used(candidate_set.size(), 0);

  bool sorted = true;
  bool unique = true;
  
  combinations_sum(candidate_set, 7, result , sorted, unique, used, 3);
  combinations_sum(candidate_set, 9, result , sorted, unique, used, 3);


  return 0;
}
