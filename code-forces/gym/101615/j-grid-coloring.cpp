#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);
#include <unistd.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

void solve (vector<string> &v, int l, int c) {
  int total = 1;
  for(int i=0; i<l; ++i){
    for(int j=0; j<c; ++j){
      if(v[i][j] == '.'){
        deque<pair<int,int>> bfs;
        int count = 0;
        bfs.push_back(make_pair(i, j));
        while(!bfs.empty()){
          pair<int,int> p = bfs.front();
          bfs.pop_front();
          if(v[p.f][p.s] != '.') continue;

          bool has_neigh = false;
          if(p.f + 1 < l) {
            if (v[p.f+1][p.s] == '.'){
              bfs.push_back(make_pair(p.f+1,p.s));
              has_neigh = true;
            } else  if (v[p.f+1][p.s] == 'B'){
              has_neigh = true;
            }
          }

          if(p.s + 1 < c) {
            if(v[p.f][p.s+1] == '.'){
              bfs.push_back(make_pair(p.f,p.s+1));
              has_neigh = true;
            } else if(v[p.f][p.s+1] == 'B'){
              has_neigh = true;
            }
          }
          count += has_neigh ? 1 : 2;
          v[p.f][p.s] = 'B';
        }
        total *= count;       
      }
    }
  }
  cout << total << endl;
}

void top_left_blue(vector<string> &v, int l, int c){
  for(int i=0; i<=l; ++i){
    for(int j=0; j<=c; ++j){
      if(v[i][j] == 'R'){
        cout << 0 << endl;
        exit(0);
      }
      v[i][j] = 'B';
    }
  }
}

void bottom_right_red(vector<string> &v, int l, int c){
  for(int i=l; i<v.size(); ++i){
    for(int j=c; j<v[i].size(); ++j){
      if(v[i][j] == 'B'){
        cout << 0 << endl;
        exit(0);
      }
      v[i][j] = 'R';
    }
  }
}

void start_writting(vector<string> &v, int l, int c){
  for(int i=0; i<l; ++i){
    for(int j=0; j<c; ++j){
      if(v[i][j] == 'B'){
        top_left_blue(v, i, j);
      } else if(v[i][j] == 'R'){
        bottom_right_red(v, i, j);
      }
    }
  }
}


int main (void) {_
  int lines, cols;
  cin >> lines >> cols;
  vector<string> v(lines);
  for(int i=0; i<lines; ++i){
    cin >> v[i];
  }
  // cout << "good input reading" << endl;
  // sleep(1);
  start_writting(v, lines, cols);
  // cout << "good start writting" << endl;
  // sleep(1);
  solve(v, lines, cols);

	return 0;
}
