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

void solve (int round, int a, int b) {
  long double weight = 0.5*a + 0.05*b;
  cout << "Case " << round << ": " << weight << endl;
}

int get_num(string &st){
  int index = 0;
  string num;
  while(index < st.size() && (st[index] < '0' || st[index]>'9'))
    ++index;
  
  while(index < st.size() && (st[index] >= '0' && st[index] <='9')){
    num.push_back(st[index]);
    ++index;
  }

  if (index < st.size())
    st = st.substr(index);
  if(num.empty())
    return 0;
  return stoi(num);
}

int main (void) {_

  int rounds, a, b;
  string st;
  char cc[20];
  cin >> rounds;
  cin.ignore();
  bool a_read = false;
  for(int i=1; i<=rounds; ++i) {
    cin.getline(cc, 20, '\n');
    st = string(cc);
    // cout << "st: " << st << endl;
    a = get_num(st);
    // cout << "st: " << st << endl;
    b = get_num(st);
    solve(i, a, b);
    // cout << endl;
  }
	return 0;
}
