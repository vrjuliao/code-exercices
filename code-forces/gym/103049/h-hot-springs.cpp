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

void solve (vector<ll> &v) {
  sort(v.begin(), v.end());
  int l, r;
  r = v.size()/2;
  if(v.size()&1){
    cout << v[r] << ' ';
    l=r-1;
    ++r;
  } else {
    l = r-1;
  }

  if(l>=0) {
    cout << v[l] << ' ' << v[r];
    --l;
    ++r;
  }

  while(l>=0){
    cout << ' ' << v[l] << ' ' << v[r];
    --l;
    ++r;
  }
  cout << endl;

}

int main (void) {_


  int qtt;
  cin >> qtt;
  vector<ll> v(qtt);
  while(qtt--){
    cin >> v[qtt];
  }
  solve(v);
	return 0;
}
