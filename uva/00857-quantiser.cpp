/* 
  WRONG
*/
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

struct note_st {
  int on, note, time, beat, tick;
  int idx_on_ans;
};

void calculate_time(int &time, int &beat, int &tick){
  int rest = tick%60;
  int div = tick/60;

  if(rest >= 30){
    tick = (div+1)*60;
  } else {
    tick = div*60;
  }
  if (tick == 480){
    tick = 0;
    if(beat == 4){
      ++time;
    }
    beat = (beat+1)%4;
  }
}

void solve (int rounds) {

  map<int, note_st> is_played;
  vector<note_st> ans;
  int on, note, time, beat, tick, aux;
  int erased = 0;
  while(rounds--){
    cin >> on >> note >> time >> beat >> tick;
    calculate_time(time, beat, tick);
    if(on) {
      is_played[note] = note_st {on, note, time, beat, tick, static_cast<int>(ans.size())};
      ans.push_back(note_st {on, note, time, beat, tick, static_cast<int>(ans.size())});
    } else {
      note_st aux = is_played[note];
      if (time == aux.time && beat == aux.beat && tick == aux.tick){
        ++erased;
        // ans[static_cast<int>(ans.size())].idx_on_ans = -1;
        ans[aux.idx_on_ans].idx_on_ans = -1;
      } else {
        ans.push_back(note_st {on, note, time, beat, tick, static_cast<int>(ans.size())});
      }
      is_played.erase(note);
    }
  }
  cout << ans.size() - erased << endl;
  for (auto it: ans) {
    if(it.idx_on_ans >= 0)
      printf("%d %d %d %d %d\n", it.on, it.note, it.time, it.beat, it.tick);
  }

}

int main (void) {

  int rounds;
  cin >> rounds;
  while(rounds >= 0){
    solve(rounds);
    cin >> rounds;
  }
  cout << -1 << endl;

	return 0;
}
