#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <iterator>

using namespace std;

#define max(a,b) ((a) > (b)) ? (a) : (b)

void print_v(vector<int> x){
  cout << endl;
  for(vector<int>::iterator it = x.begin(); it != x.end(); it++){
    cout << " " << *it;
  }
  cout << endl;
}

class BadNeighbors{
  map < pair<int,int> , int> cache;

public:
  int dp_seq(vector<int> &seq, vector<int> r){
    for(int x = 0;x < seq.size(); x++){
      int a1 = seq[x];
      if((x-2) >= 0)
	a1 += r[x-2];
      
      int b1 = 0;
      if((x-1) >= 0){
	b1 += seq[x-1];
	if((x-3) >= 0)
	  b1 += r[x-3];
      }

      r[x] = max(a1, b1);
    }

    //print_v(r);

    return r[r.size() - 1];
  }

  int dp(vector<int> d){
    vector<int> a(d.begin(), d.end() - 1);
    vector<int> b(d.begin() + 1, d.end());
    vector<int> ra(a.begin(), a.end());
    vector<int> rb(b.begin(), b.end());

    return max(dp_seq(a,ra), dp_seq(b,rb));

  }


  int maxDonations(vector<int> d, int start, int end, string x){
    //cout << endl << x << start << ":" << end;

    pair<int, int> key = make_pair(start , end);
    if(cache.find(key) != cache.end())
      return cache[key];

    if(end < start)
      return 0;

    if(end < 0)
      return 0;

    int a = 0;

    if((end >= start) && (end >= 0)){
      a = d[end] + maxDonations(d,start, end-2, x + "-");
    }

    int b = 0;

    if((end - 1 >= start) && ((end - 1 ) >= 0)){
      b = d[end - 1] + maxDonations(d, start, end  - 3, x + "-");
    }
    
    int result = 0;

    if(a > b){
      result = a;
    }else{
      result = b;
    }

    cache[make_pair(start, end)] = result;
    
    //    cout << endl << a << "," << b << "=" << result;

    return result;
  }

  int maxDonations(vector<int> d){
    cache.clear();

    /*
    int a = maxDonations(d,0,d.size() - 2, "-");
    int b = maxDonations(d,1,d.size() - 1, "-");
      
    if(a > b)
      return a;
    
    return b;
    */

    return dp(d);
  }
};

vector<int> to_v(int * a, int n){
  return vector<int>(a, a + n);
}

int main(){
  BadNeighbors b;
  
  int a[] = { 10, 3, 2, 5, 7, 8 };
  cout << endl << b.maxDonations(to_v(a, sizeof(a)/sizeof(int))) << endl;

  int a1[] = { 11, 15 };
  cout << endl << b.maxDonations(to_v(a1, sizeof(a1)/sizeof(int))) << endl;

  int a2[] = { 7, 7, 7, 7, 7, 7, 7 };
  cout << endl << b.maxDonations(to_v(a2, sizeof(a2)/sizeof(int))) << endl;

  int a3[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
  cout << endl << b.maxDonations(to_v(a3, sizeof(a3)/sizeof(int))) << endl;

  int a4[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
	       6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
	       52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
  cout << endl << b.maxDonations(to_v(a4, sizeof(a4)/sizeof(int))) << endl;

  return 0;
}
