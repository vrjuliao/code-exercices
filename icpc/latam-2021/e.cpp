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

void solve (deque<int> &right, deque<int> &left, int first) {
  deque<int> *running, *waiting, *aux;
  if(first){
    running = &right;
    waiting = &left;
  } else {
    waiting = &right;
    running = &left;
  }

  int stopped_time = 0;
  bool stopped = true;
  while(!running->empty()){
    while(!running->empty() && stopped_time >= running->front()){
      stopped = false;
      running->pop_front();
    }
    
    int end_at=0;
    // cout << "stopped_time: " << stopped_time << endl;
    if(!stopped){
      stopped_time+=10;
      end_at = stopped_time;
    }

    while(!running->empty()){
      int curr = running->front();
      // cout << "curr: " << curr << endl;
      // cout << "stopped: " << stopped << endl;
      // cout << "end_at: " << end_at << endl;
      if(stopped){
        stopped = false;
        end_at = curr+10;
        stopped_time = end_at;
        running->pop_front();
      } else {
        if(curr < end_at){
          end_at = curr+10;
          stopped_time = end_at;
          running->pop_front();
        } else {
          stopped_time = end_at;
          stopped = true;
          break;
        }
      }
    }
    if(!stopped){
      running = waiting;
    } else if(running->front() > waiting->front()){
      aux = waiting;
      waiting = running;
      running = aux;
    }
  }
  cout << stopped_time << endl;
}

int main (void) {_

  int qtt, side, time;
  cin >> qtt;
  deque<int> right, left;
  bool start_side;
  int first = -1;
  while(qtt--){
    cin >> time >> side;
    if(first < 0){
      first = side;
    }
    if(side){
      right.push_back(time);
    } else {
      left.push_back(time);
    }
  }

  solve(right, left, first);

	return 0;
}
