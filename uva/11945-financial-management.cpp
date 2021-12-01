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

void print_recursively(ll value){
  if(value/1000) {
    print_recursively(value/1000);
    printf("%03Ld,", value%1000);
  } else {
    printf("%Ld,", value%1000);
  }
}

void print_formated (long double value) {
  
  ll ival = static_cast<ll>(value);
  if(ival/1000) {
    print_recursively(ival/1000);
    printf("%03Ld.", ival%1000);
  } else {
    printf("%Ld.", ival%1000);
  }
  value *= 100.0;
  ll cents = static_cast<ll>(round(value));
  printf("%02Ld\n", cents%100);
}

int main (void) {

  int rounds;
  cin >> rounds;
  for(int i=1; i<= rounds; ++i){
    long double sum, aux;
    sum = 0.0;
    for(int j=0; j<12; ++j){
      cin >> aux;
      sum += aux;
    }
    cout << i << " $";
    print_formated(sum/12);
  }
	return 0;
}
