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

void swap(int& a, int& b){
  int c = a;
  a = b;
  b = c;
}

void permute(vector<int> &v, int start, int end, vector<int> &r){
  if(!(start < end)){
    print_v(v);
    return;
  }

  for(int i = start;i < end;i++){
    swap(v[i],v[start]); // note
    permute(v, start + 1, end, r); // note
    swap(v[i],v[start]); // note
  }
}

void permute(vector<int> &v){
  vector<int> r;
  permute(v,0,v.size(), r);
}


bool equals(vector<int> &a, vector<int> &b){
  for(int i =0; i < a.size();i++){
    if(a[i] != b[i])
      return false;
  }

  return true;
}

int start_index_of_longest_increasing_suffix(vector<int> &v){
  int end = v.size() - 1;
  int start = end - 1;
  while(start >=0 && start < end && v[start] > v[end]){
    start--;
    end--;
  }

  return start;
}

int last_suffix_element_greater_than_pivot_element(vector<int> &v, int pivot){
  int end = v.size() - 1;
  while(end >= 0 && end >= pivot){
    if(v[end] >= v[pivot])
      break;

    end--;
  }

  return end;
}

void reverse_range(vector<int> &v, int start, int end){
  int l = end - start + 1;
  int mid = (int)(l/2);
  while(start <= end){
    swap(v[start], v[end]);
    start++;
    end--;
  }
}

void next_permute(vector<int> &v){
  int pivot = start_index_of_longest_increasing_suffix(v);
  int swap_suffix_pivot = last_suffix_element_greater_than_pivot_element(v, pivot);
  swap(v[pivot], v[swap_suffix_pivot]);
  reverse_range(v, pivot + 1, v.size()-1);
}

void valid_parenthesis(string s,int left, int right){
  if(!(left <= right)){
    return;
  }

  if(0 == left && 0 == right){
    cout << endl << s;
    return;
  }

  if(left > 0)
    valid_parenthesis(s + "(", left-1, right);

  if(right > 0)
    valid_parenthesis(s + ")", left, right-1);

}

void valid_parenthesis(int n){
  valid_parenthesis("",n,n);
}

int main(){
  valid_parenthesis(3);

  return 0;
}
