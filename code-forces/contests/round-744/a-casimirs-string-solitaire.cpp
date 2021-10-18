#include <bits/stdc++.h>

using namespace std;

int main () {
  unsigned A, B, C;

  int rounds;
  cin >> rounds;
  string input;
  while(rounds--) {
    cin >> input;
    A=0;
    B=0;
    C=0;
    for(auto it: input) {
      if (it == 'A')
        ++A;
      else if(it == 'B')
        ++B;
      else if(it == 'C')
        ++C;
    }

    if (A+C == B)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }

  return 0;
}