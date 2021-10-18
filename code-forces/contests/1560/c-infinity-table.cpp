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
  ll num;
  while(rounds--){
    cin >> num;
    ll sqroot = sqrt(num);
    if(sqroot*sqroot == num) {
      cout << sqroot << ' ' << 1 << endl;
    }
    else {
      ll diag = sqroot+1;
      ll mid = (sqroot*sqroot) + (((diag*diag) - (sqroot*sqroot)+1)/2);
      if(num > mid){
        cout << diag << ' ' << diag - (num - mid) << endl;
      } else {
        cout << diag - (mid - num) << ' ' << diag << endl;
      }
    }

  }
  
	return 0;
}
