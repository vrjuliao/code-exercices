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

int main (void) {
  ll rounds;

  cin >> rounds;
  ll a, b, c;
  while(rounds--){
    cin >> a >> b >> c;
    ll incr = abs(a-b);
    ll mx = max(a,b), mn = min(a,b); 
    if (c<1 || c > 2*incr ||
      mx-incr != mn || mx > 2*incr){
      cout << -1 << endl;
    }
    else {
      if(c > incr){
        cout << c - incr << endl;
      } else {
        cout << c + incr << endl;
      }
    }
  }
	return 0;
}
