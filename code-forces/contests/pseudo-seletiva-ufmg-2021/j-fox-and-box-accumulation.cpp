#include <bits/stdc++.h>

using namespace std;

int main () {
  int qtt;
  cin >> qtt;

  vector<pair<int, bool>> v;

  int i;
  while(qtt--){
    cin >> i;
    v.push_back(make_pair(i, false));
  }

  sort(v.begin(), v.end());


  int start = 0;
  bool already_marked = true;
  int piles = 0;
  while(already_marked){
    int acc = 0;
    already_marked = false;
    int k = 1;
    v[start].second = true;
    for(int j = start+1; j<v.size(); ++j){
      if(!v[j].second) {
        if(k <= v[j].first){
          ++k;
          v[j].second = true;
        } else {
          if (!already_marked) {
            start = j;
            already_marked = true;
          }
        }
      }
    }
    ++piles;
  }

  cout << piles << endl;
  return 0;
}