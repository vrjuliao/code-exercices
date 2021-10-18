#include <bits/stdc++.h>

using namespace std;

bool dfs_run(vector<vector<pair<char, bool>>> &t, int i, int j){
  // if(i-1 >= 0 && t[i-1][j].first == t[i][j].first){
  //   if (t[i-1][j].second) return true;
  //   else {
  //     t[i-1][j].second = true;
  //     if(dfs_run(t, i-1, j)) return true;
  //   }
  // }
  if(i+1 < t.size() && t[i+1][j].first == t[i][j].first){
    if (t[i+1][j].second) return true;
    else{
      t[i+1][j].second = true;
      if(dfs_run(t, i+1, j)) return true;
    } 
  }
  // if(j-1 >= 0 && t[i][j-1].first == t[i][j].first){
  //   if (t[i][j-1].second) return true;
  //   else {
  //     t[i][j-1].second = true;
  //     if(dfs_run(t, i, j-1)) return true;
  //   }
  // }
  if(j+1 < t[0].size() && t[i][j+1].first == t[i][j].first){
    if (t[i][j+1].second) return true;
    else {
      t[i][j+1].second = true;
      if(dfs_run(t, i, j+1)) return true;
    }
  }
  return false;
}

bool dfs(vector<vector<pair<char, bool>>> &t, int n, int m) {
  for (int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(!t[i][j].second){
        t[i][j].second = true;
        if(dfs_run(t, i, j)){
          return true;
        }
      }
    }
  }
  return false;
}

int main () {
  int n,m;
  cin >> n >> m;
  vector<vector<pair<char,bool>>> table(n);

  string s;
  for(int i = 0; i<n; ++i){
    cin >> s;
    table[i] = vector<pair<char, bool>>(m);
    for(int j=0; j<m; ++j){
      table[i][j] = make_pair(s[j], false);
    }
  }

  if(dfs(table, n, m)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}