#include <bits/stdc++.h>

using namespace std;


bool allgreen(vector<int> &v, vector<int> &vx2, int size, int time){
  for(int i=0; i<size; i++)
    if(time%vx2[i] >= v[i]-5) return false;

  return true;
}

int main (){

  int input, count, exit_count;
  vector<int> v = vector<int>(110);
  vector<int> vx2 = vector<int>(110);
  while (true){
    count = 0;
    cin >> input;

    if(!input) {
      cin >> input;
      if(!input){
        cin >> input;
        if(!input) return 0;
      }
    }
    
    
    while(input){
      v[count] = input;
      vx2[count] = input*2;
      cin >> input;
      count++;
    }

    int time = 999999999;
    for (int i=0; i<count; i++) time = (time > vx2[i]) ? vx2[i] : time;

    bool found;
    while ( !(found = allgreen(v, vx2, count, time))  && time < 18000) time++;

    if(found){
      int h, m, s;
      h = time/3600;
      m =  (time - (h*3600))/60;
      s = time%60;
      printf("0%d:%02d:%02d", h, m, s);
      cout << endl;
    } else {
      cout << "Signals fail to synchronise in 5 hours" << endl;
    }
  }

  return 0;
}