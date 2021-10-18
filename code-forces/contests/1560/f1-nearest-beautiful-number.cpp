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

bool is_k_beautiful(const ll &n, const ll &k){
  string s = to_string(n);
  unordered_set<char> st = unordered_set<char>(s.begin(), s.end());
  return st.size() == k; 
}

ll mount_k_beautiful(ll &n, ll &k){
  do {
    ++n;
  } while(!is_k_beautiful(n, k));
  return n;
}

int main (void) {_
  ll rounds, n, k;
  cin >> rounds;
  while(rounds--){
    cin >> n >> k;
    if(is_k_beautiful(n, k)){
      cout << n << endl;
    } else {
      cout << mount_k_beautiful(n,k) << endl;
    }
  }


	return 0;
}
