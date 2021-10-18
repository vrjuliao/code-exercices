#include<bits/stdc++.h>

using namespace std;

template<typename T>
std::vector<int> argsort(const std::vector<T> &array) {
    std::vector<int> indices(array.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&array](int left, int right) -> bool {
                  // sort indices according to corresponding array element
                  return array[left] < array[right];
              });

    return indices;
}

void check_sociability(vector<int> &v, vector<int> &x){
  vector<pair<int,string>> ans;
  int ans_count = 0;
  int aux;
  for(int i=x.size()-1; i>=0; --i){
    if(v[i]>0) {
      for(int j=i-1; j>=0 && v[i] > 0; --j){
        if(v[i]>=v[j]){
          aux = v[j];
          v[i]-= v[j];
          v[j] = 0;
        } else if (v[j] > 0) {
          aux = v[i];
          v[j] -= v[i];
          v[i] = 0;
        }
        ans_count += aux;
        ans.push_back(make_pair(aux, ""+to_string(x[i]+1)+' '+to_string(x[j]+1)));
      }
    }
  }
  cout << ans_count << endl;
  for (auto it: ans)
    for(int i=0; i<it.first; ++i)
      cout << it.second << endl;

}

int main () {
  int rounds;
  cin >> rounds;

  int people, aux;

  while(rounds--){
    cin >> people;
    vector<int> v(people);
    for (int i=0; i<people; ++i){
      cin >> aux;
      v[i] = aux;
    }

    vector<int> x = argsort(v);
    sort(v.begin(), v.end());
    check_sociability(v, x);
  }
  

  return 0;
}