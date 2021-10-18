#include <bits/stdc++.h>

using namespace std;

int main () {
  int round, aux, input, last;

  cin >> round;
  while(round--) {
    cin >> input;
    deque<int> v;
    for (int i=0; i<input; ++i){
      cin >> aux;
      if(!v.empty() && v.front() >= aux){
        v.push_front(aux);
      } else {
        v.push_back(aux);
      }
    }

    auto it = v.begin();
    if(it!= v.end()){
      cout << *it;
      it++;
    }
    while (it != v.end()){
      cout << ' ' << *it;
      it++;
    }
    cout << endl;
  }


  return 0;
}