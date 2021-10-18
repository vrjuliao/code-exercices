#include <bits/stdc++.h>

using namespace std;

int main () {
  vector<int> v = {4, 34, 1, 65, 6};

  sort(v.begin(), v.end());
  for(auto it: v){
    cout << it << " ";
  }
  cout << endl;

}