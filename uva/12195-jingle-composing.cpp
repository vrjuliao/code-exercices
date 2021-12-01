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

void solve (string &s) {
  long double sum = 0.0;
  ll qtt=0;
  for(int i=1; i<s.size(); ++i){
    sum = 0.0;
    while(s[i] !=  '/'){
      switch(s[i]){
        case 'W':
          sum += 1.0; break;
        case 'H':
          sum += 1.0/2.0; break;
        case 'Q':
          sum += 1.0/4.0; break;
        case 'E':
          sum += 1.0/8.0; break;
        case 'S':
          sum += 1.0/16.0; break;
        case 'T':
          sum += 1.0/32.0; break;
        case 'X':
          sum += 1.0/64.0; break;
      }
      ++i;
    }
    // if (sum >= (1.0 - 1e-16) && sum >= (1.0 + 1e-16)){
    if(sum == 1.0) {
      ++qtt;
    }
  }
  cout << qtt << endl;
}

int main (void) {_
  string s;
  cin >> s;
  while(s[0] != '*'){
    solve(s);
    cin >> s;
  }

	return 0;
}
