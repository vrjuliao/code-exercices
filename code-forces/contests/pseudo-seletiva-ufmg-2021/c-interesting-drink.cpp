#include <bits/stdc++.h>

using namespace std;

vector<int> places(100100);
int bin_search_index(int num, vector<int> &places, int size) {
  int pos = size/2;
  while (true) {
    if(places[pos] == num || (places[pos] < num && pos+1 < size && places[pos+1] > num) )
      return pos+1;
    else if(pos >= size)
      return size;
    else if (pos < 0)
      return 0;
    else if (places[pos] < num)
      pos += pos >= 2 ? pos/2 : 1;
    else if (places[pos] > num)
      pos -= pos >= 2 ? pos/2 : 1;
  }
  return 0;
}

int bin_search(vector<int> &places, int l, int r, int num) { 
  if (r >= l) {
    int pos = l + (r - l) / 2;

    if(places[pos] == num || (places[pos] < num && pos+1 < places.size() && places[pos+1] > num) )
      return pos+1;

    if (places[pos] > num)
      return bin_search(places, l, pos - 1, num);

    return bin_search(places, pos + 1, r, num);
  } 
  return -1;
}

int main () {
  int qtt1, aux;
  cin >> qtt1;
  for (int i=0; i<qtt1; ++i){
    cin >> aux;
    places.push_back(aux);
  }

  sort(places.begin(), places.begin()+qtt1);
  
  int qtt;
  cin >> qtt;
  while(qtt--){
    cin >> aux;
    int x = bin_search(places, 0, places.size()-1, aux);
    if(x >= 0)
      cout  << x << endl;
    else {
      if (aux < places[0]) cout << 0 << endl;
      else cout << places.size() << endl;
    }
  }
  return 0;
}