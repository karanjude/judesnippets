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

int index_of_last_suffix_element_greater_than_pivot_element(vector<int> &v, int pivot){
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

void handle_case_when_mid_number_has_9_and_number_has_even_digits(vector<int> &v, int lmid, int rmid, int len){
      v[lmid] = 0;
      v[rmid] = 0;
      
      while(lmid-- >=0 && rmid++ < len){
	if(v[lmid] == 9 && v[rmid] == 9){
	  v[lmid] = 0;
	  v[rmid] = 0;
	}else{
	  v[lmid] += 1;
	  v[rmid] += 1;
	  break;
	}
      }

      if(v[lmid] == 0 && v[rmid] == len - 1 && v[lmid] == 0 && v[rmid] == 0){
	v.insert(v.begin(), 1);
	v.push_back(1);
      }
}

int val(vector<int> & v){
  int num = 0;
  for(int i = 0; i < v.size();i++){
    int x = 10 * num + (v[i] - '0');
    num += x;
  }

  return num;
}

void next_palindrome(vector<int> &v){
  int old_number = val(v);

  int len = v.size();
  int mid = len / 2;
  for(int i = 0;i <= mid; i++){
    v[len - i - 1] = v[i];
  }

  int new_number = val(v);

  if(len % 2 == 0){
    int lmid = mid-1;
    int rmid = mid;

    if(new_number < old_number){
      if(v[lmid] == 9 && v[rmid] == 9){
	handle_case_when_mid_number_has_9_and_number_has_even_digits(v, lmid, rmid, len);
      }else{
	v[lmid] += 1;
	v[rmid] += 1;
      }
    }
  }

  print_v(v);
}

long fact(int n){
  int r = 1;
  for(int i = 1;i <= n;i++){
    r *= i;
  }

  return r;
}

string kth_permutation(string s, int k){
  if(s.length() == 1 || k == 0){
    return s;
  } 

  int n = s.length();

  int i = k / fact(n-1);
  int j = k % fact(n-1);
  
  return s[i] + kth_permutation(s.substr(0,i) + s.substr(i+1,string::npos), j);

}

int smaller(string& s, int start, int end){
  int r = 0;
  for(int i = start+1; i < end;i++){
    if(s[i] < s[start])
      r++;
  }

  return r;
}

int _rank(string s){
  int len = s.length();
  int mul = fact(len);
  int rank = 1;

  for(int i = 0; i < len;i++){
    mul /= len - i; // 4 * 5! + 4 * 4! + 3 * 3! .. 
    int number_of_chars_smaller_than_char_at_i_to_the_right = smaller(s, i, len);
    rank += number_of_chars_smaller_than_char_at_i_to_the_right * mul;
  }
  return rank;
}

int main(){
  cout << endl << _rank("string");


  return 0;
}
