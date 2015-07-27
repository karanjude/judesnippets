#include <iostream>
#include <vector>

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


int main(){
  int arr[] = {1,1,2};
  int n = sizeof(arr) / sizeof(int);
  vector<int> v(arr, arr + n);

  sort(v.begin(), v.end());

  permute(v);

  return 0;
}
