#include <bits/stdc++.h>

using namespace std;

int main () {
  vector<string> woman_child, man, rat;
  string cap;

  int qtt;
  cin >> qtt;
  string name, crew;
  while (qtt--) {
    cin >> name >> crew;
    if (crew == "rat")
      rat.push_back(name);
    else if (crew == "man")
       man.push_back(name);
    else if (crew == "woman" || crew == "child")
       woman_child.push_back(name);
    if (crew == "captain")
      cap = name;
  }

  for (auto it: rat)
    cout << it << endl;
  for (auto it: woman_child)
    cout << it << endl;
  for (auto it: man)
    cout << it << endl;
  cout << cap << endl;

  return 0;
}