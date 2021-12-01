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

void solve (const vector<int> &v, const string &op) {
  int size = v.size();
  ll r;
  ll paths = 0;
  int seq_size;
  int x;
  for (ll l=0; l<size; ++l) {
    x = 1;
    r = l;
    seq_size=0;
    while(r < size) {
      if (op[r] == '*'){
        x*=v[r];
        ++r;
        ++seq_size;
      } else if(x%v[r]){
        break;
      } else {
        x/=v[r];
        ++r;
        ++seq_size;
      }
    }
    paths += seq_size;
  }
  cout << paths << endl;
}

int main (void) {_

  int size;
  cin >> size;
  vector<int> v(size);
  for(int i=0; i<size; ++i){
    cin >> v[i];
  }
  string op;
  cin >> op;
  solve(v, op);

	return 0;
}
