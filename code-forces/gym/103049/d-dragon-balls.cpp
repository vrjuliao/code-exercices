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

int ask(int x, int y){
  int d;
  cout << x << ' ' << y << endl;
  cin >> d;
  return d;
}
int main (void) {_
  int qtt;
  ll d, d1, d2, x=0, y=0;
  ll cx=0, cy=0;
  cin >> qtt;
  bool xloop=true, yloop=true;
  while(qtt) {
    x=0; y=0;
    d=ask(x, y);
    ll initd = d;
    while(d){
      cx = static_cast<ll>(floor(sqrt((d)-(y*y))));

      xloop = (cx != x);
      if(xloop) {
        cout << "xloop: " << xloop <<endl;
        d1 = ask(cx, y);
        cout << "    d1+(cx*cx) " << d1+(cx*cx) << endl << endl;
        if(d1+(cx*cx) == initd){
          y = static_cast<ll>(floor(sqrt(d1)));
          d2 = ask(cx, y);
          d1 = min(d1, d2);
        }

        if(d1 <= d) {
          d = d1;
          x = cx;
          continue;
        }
      }

      cy = static_cast<ll>(floor(sqrt((d)-(x*x))));
      yloop = (cy != y);
      if (yloop) {
        d1 = ask(x, cy);
        cout << "    d1+(cy*cy) " << d1+(cx*cx) << endl << endl;
        if(d1+(cy*cy) == initd){
          x = static_cast<ll>(floor(sqrt(d1)));
          d2 = ask(x, cy);
          d1 = min(d1, d2);
        }

        if(d1 <= d) {
          d = d1;
          y = cy;
          continue;
        }
      }
      ++y;
      ++x;
    }
    cout << x << ' ' << y << endl;
    --qtt;
  }
  return 0;
}
