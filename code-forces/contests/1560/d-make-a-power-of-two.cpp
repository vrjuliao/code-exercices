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

ll calc_movements(ll &p2, ll &n){
  string pow2 = to_string(p2);
  string num = to_string(n);
  ll mov = 0;
  int p2idx = 0, numidx = 0;
  while(pow2 != num){
    if(numidx == num.size()){
      num[numidx] = pow2[p2idx];
      ++numidx;
      if(p2idx < pow2.size())
        ++p2idx;
    } else if(pow2[p2idx] != num[numidx]){
      num.erase(numidx);
      if(p2idx < pow2.size())
        ++p2idx;
    } else {
      if(p2idx < pow2.size())
        ++p2idx;
      ++numidx;
    }
  }
  return mov;
}

int main (void) {

  ll rounds;
  cin >> rounds;

  ll number;
  ll mov = LINF;
  while(rounds--){
    for(ll i=1; i<=1e9+10; i*=2){
      mov = min(mov, calc_movements(i, number));
    }


  }
	return 0;
}
