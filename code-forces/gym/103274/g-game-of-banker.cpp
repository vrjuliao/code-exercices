#include <bits/stdc++.h>

using namespace std;

int main () {

  unsigned long int i, j;
  cin >> i >> j;
  if (j<i) {
    if (j == 1){
      if (i&1) { 
        cout << "Free snacks!" << endl;
      } else {
        cout << "Pay the bill" << endl;
      }
    } else {
      if (i%j){
        cout << "Free snacks!" << endl;
      } else {
        cout << "Pay the bill" << endl;
      }
    }
  } else {
      cout << "Pay the bill" << endl;
  }
  return 0;
}