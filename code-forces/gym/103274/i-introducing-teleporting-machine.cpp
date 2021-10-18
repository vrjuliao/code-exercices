#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k, t, ax;
  cin >> n >> k >> t;
  int total=0;
  vector<int> v;
  
  if(k>t){
    while(n--){
      cin >> ax;
      v.push_back(ax);
    }
    for(int idx=0; idx<v.size()-1; ++idx)
      total+= v.back() - v[idx];

    //get first window
    int i=0, j=0;
    while(v[j]-v[i] <= k && j<v.size())
      ++j;
    total-=v[j]-v[i] + t;

    int current = total;
    


  } else {
    cout << -1 << endl;
  }


  return 0;
}