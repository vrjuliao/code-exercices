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

int dp[1010][1010]; 

int dfs(const vector<string> &table, int r, int c, char last);

int dfs(const vector<string> &table, int r, int c, char last){
  if(r< 0 || c < 0 || r >= table.size() || c >= table[0].size())
    return 0;
  else {
    if (last+1 == table[r][c]) {
      if (dp[r][c] == -1) {
        dp[r][c] = max(dp[r][c], dfs(table, r-1, c-1, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r-1, c, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r-1, c+1, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r, c+1, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r+1, c+1, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r+1, c, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r+1, c-1, table[r][c]));
        dp[r][c] = max(dp[r][c], dfs(table, r, c-1, table[r][c]));
      }
      return dp[r][c] + 1;
    } else {
      return 0;
    }
  }
}

void solve (const vector<string> &table) {
  int mx = -1;
  for(int i=0; i<table.size(); ++i){
    for(int j=0; j<table[i].size(); ++j){
      mx = max(mx, dfs(table, i-1, j-1, table[i][j]));
      mx = max(mx, dfs(table, i-1, j, table[i][j]));
      mx = max(mx, dfs(table, i-1, j+1, table[i][j]));
      mx = max(mx, dfs(table, i, j+1, table[i][j]));
      mx = max(mx, dfs(table, i+1, j+1, table[i][j]));
      mx = max(mx, dfs(table, i+1, j, table[i][j]));
      mx = max(mx, dfs(table, i+1, j-1, table[i][j]));
      mx = max(mx, dfs(table, i, j-1, table[i][j]));
    }
  }
  cout << mx+1 << endl;
}

int main (void) {
  for(int i=0; i < 1010; ++i){
    memset(dp[i], -1, sizeof(dp[i]));
  }

  int r, l;
  cin >> r >> l;
  vector<string> table(r);
  for(int i=0; i<r; ++i){
    cin >> table[i];
  }
  solve(table);

	return 0;
}
