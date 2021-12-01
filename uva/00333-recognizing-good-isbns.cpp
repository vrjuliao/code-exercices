#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

bool solve (vector<int> &isbn) {
  vector<int> cum_sum(10);
  int csum = 0;
  for(int i=0; i<isbn.size(); ++i){
    csum += isbn[i];
    cum_sum[i] = csum;
  }
  csum = 0;
  for(auto it: cum_sum) {
    csum += it;
    // cout << it << ' ';
  }
  
  // cout << endl << csum << endl;
  return !(csum%11);
}

vector<int> get_isbn(string &st){
  vector<int> res;
  int i=0;
  // lpad
  while(i<st.size() && (st[i] == ' ' || st[i] == '\t')){ ++i; }
  int start = i;
  int end = st.size()-1;
  while(end >= 0 && (st[end] == ' ' || st[end] == '\t')) { --end; }

  bool error = false;
  while(i <= end){
    if(st[i] == ' ' || st[i] == '\t' || st[i] == '-') {
      ++i;
      continue;
    } else if (st[i] >= '0' && st[i] <= '9'){
      res.push_back(st[i]-'0');
    } else if(st[i] == 'X') {
      if(res.size() == 9){
        res.push_back(10);
      } else {
        error = true;
        break;
      }
    } else {
      error = true;
      break;
    }
    ++i;
  }
  st = st.substr(start, end-start+1);
  if(error) return {};
  return res;
}

int main (void) {_
  string st;
  vector<int> isbn;
  while(getline(cin, st)) {
    isbn = get_isbn(st);
    if(isbn.size()!= 10){
      cout << st << " is incorrect." << endl;
      continue;
    }
    // for(auto it: isbn){
    //   cout << it << ' ';
    // }
    // cout << endl;
    if (solve(isbn)){
      cout << st << " is correct." << endl;
    } else {
      cout << st << " is incorrect." << endl;
    }
  }


	return 0;
}
