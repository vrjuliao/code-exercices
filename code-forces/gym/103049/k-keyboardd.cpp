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

void solve (void) {

}

int main (void) {_
  string correct, wrong;
  getline(cin, correct);
  getline(cin, wrong);

  set<char> sticky;

  int windex = 0, cindex = 0;
  while(windex<wrong.size() && cindex < correct.size()){
    if(wrong[windex] == correct[cindex]) {
      ++cindex;
    } else {
      sticky.insert(wrong[windex]);
    }
    ++windex;
  }
  while(windex < wrong.size()){
    sticky.insert(wrong[windex]);
    ++windex;
  }

  for(auto it: sticky)
    cout << it;
  cout << endl;
}
