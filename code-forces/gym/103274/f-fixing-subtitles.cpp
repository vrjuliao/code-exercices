#include <bits/stdc++.h>

using namespace std;

int main () {
  int rounds;
  int i_aux;
  long int min, sec;
  long double delay, msec, d_aux;
  string s_aux;
  cin >> rounds >> delay;
  // while(rounds--){
    cin >> i_aux;
    cout << i_aux;
    scanf("%ld:%ld:%Lf", &min, &sec, &msec);
    d_aux = (((min*60.0)+sec)*1000.0)+msec;
    d_aux += delay;
    min = d_aux/60000;
    sec = (d_aux- (min*60000))/10000;
    msec = d_aux - (min*60000) - (sec*1000);
    cout << min << ':' << sec << ':' << msec << endl;
    

  // }




  return 0;
}