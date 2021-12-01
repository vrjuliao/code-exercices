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

void solve (int zeroes, int ones) {
  cout << ones * (static_cast<int>(pow(static_cast<double>(2), static_cast<double>(zeroes)))) << endl;
}

int main (void) {_

  int rounds, size, v, zeroes, ones;
  cin >> rounds;
  while (rounds--) {
    cin >> size;
    ones = 0;
    zeroes = 0;
    while(size--) {
      cin >> v;
      if (v == 1) ++ones;
      else if (v == 0) ++zeroes;
    }
    solve(zeroes, ones);
  }
	return 0;
}
