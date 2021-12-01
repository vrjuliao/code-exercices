#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;


ld cost(ld k, ld p, ld x, ld m) {
  return (x*m) + ((k/m)*p);
}

void solve (ld k, ld p, ld x, ll left, ll right) {
  ll mid = (right+left)/2;
  if(left==right){
    printf("%.3Lf\n", cost(k,p,x,static_cast<ld>(right)));
  } else {
    if(cost(k,p,x,static_cast<ld>(mid)) > cost(k,p,x,static_cast<ld>(mid+1))){
      solve(k,p,x,mid+1, right);
    } else {
      solve(k,p,x,left, mid);
    }
  }
}

ld get_start_point(ld k, ld p, ld x){
  ld m = 1.;
  ld cr_cost = cost(k,p,x,m);
  ld nx_cost;
  ld m_next = 2.0;
  
  while(true){
    nx_cost = cost(k, p, x, m_next);
    m = m_next;
    if(nx_cost > cr_cost)
      break;
    cr_cost = nx_cost;
    m_next *= 2.;
  }
  return m;
}

int main (void) {_
  ld k, p, x, m;
  cin >> k >> p >> x;

  m = get_start_point(k, p, x);
  //cout << "best m: " << m << endl;
  const ll left = static_cast<ll>(ceil(m/4.));
  solve(k, p, x, left, static_cast<ll>(m));

	return 0;
}
