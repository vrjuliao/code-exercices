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

  int rounds;
  ll sum, diff;
  cin >> rounds;
  while(rounds--){
    cin >> sum >> diff;
    if(diff > sum){
      cout << "impossible" << endl;
    } else {
      ll a = (sum + diff)/2;
      ll b = (sum - diff)/2;
      if(a+b == sum && a-b == diff){
        cout << a << ' ' << b << endl;
      } else {
        cout << "impossible" << endl;
      }
    }
  }
	return 0;
}
