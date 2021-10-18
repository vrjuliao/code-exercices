#include <bits/stdc++.h>

using namespace std;

int main () {
  vector<bool> non_blank = vector<bool>(110);
  int pages;

  cin >> pages;
  while(pages){
    cout << "Printing order for " << pages << " pages:" << endl;
    if (pages == 1){
      cout << "Sheet 1, front: Blank, 1" << endl;
      cin >> pages;
      continue;
    }

    int i;
    for(i=1; i<=pages; i++)
      non_blank[i] = true;
    for(;i<110; i++)
      non_blank[i] = false;

    int front, back;
    front = 1;
    back = pages%4 ? pages + (4 - pages%4) : pages;

    int sheet = 1;
    while(front < back){
      cout << "Sheet "<< sheet << ", front: ";
      if(non_blank[back])
        cout << back;
      else
        cout << "Blank";

      cout << ", " << front << endl;
      front ++;
      back --;

      cout << "Sheet "<< sheet << ", back : " << front << ", ";
      if(non_blank[back])
        cout << back;
      else
        cout << "Blank";

      cout << endl;
      front ++;
      back --;
      sheet++;
    }


    cin >> pages;
  }


  return 0;
}