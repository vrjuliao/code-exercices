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
  cin >> rounds;
  int k;

  while(rounds--){
    cin >> k;
    int i=0;
    while(k>=1){
      i++;
      if(i%3 != 0 && i%10 != 3){
        --k;
      }
    }
    cout << i << endl;
  }
	return 0;
}
