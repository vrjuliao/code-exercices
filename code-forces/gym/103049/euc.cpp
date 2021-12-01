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

int main (int argc, char *argv[]) {_
  int x1 = stoi(argv[1]);
  int y1 = stoi(argv[2]);
  int x2 = stoi(argv[3]);
  int y2 = stoi(argv[4]);
  cout << ((x1-x2)*(x1-x2)) + (((y1-y2)*(y1-y2))) << endl;

	return 0;
}
