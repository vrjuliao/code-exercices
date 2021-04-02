#include <bits/stdc++.h>

using namespace std;

int main(){

  int rounds;
  string phrase, anagram;
  cin >> rounds;
  cin.ignore();
  getline(cin, phrase);
  while(rounds--){
    unordered_map<string, unordered_map<char, int>> words_map;
    vector<string> results;
    while(getline(cin, phrase) && phrase.size()){
      // create a map
      unordered_map<char, int> new_phrase;
      
      for(int i=0; i<phrase.size(); i++){
        if(phrase[i] != ' '){
          if(new_phrase.find(phrase[i]) != new_phrase.end()){
            new_phrase[phrase[i]]++;
          }else {
            new_phrase[phrase[i]] = 1;
          }
        }
      }

      char c;
      bool found;
      for(auto it = words_map.begin(); it != words_map.end(); ++it){
        found = true;
        if (it->second.size() != new_phrase.size()) continue;
        for(auto jt = new_phrase.begin(); jt != new_phrase.end(); ++jt){
          c = (jt->first);
          if(it->second.find(c) == it->second.end() 
          || it->second[c] != jt->second){
            found = false;
            break;
          }
        }
        if(found) {
          if (it->first > phrase){
            results.push_back(phrase + " = " + it->first);
          }
          else {
            results.push_back(it->first+" = " + phrase);
          }
        }
      }
      words_map[phrase] = new_phrase;
      // has_anagram(words_map, new_phrase, phrase);
    }
    sort(results.begin(), results.end());
    for(int i=0; i<results.size(); i++){
      cout << results[i] << endl;
    }
    if(rounds >= 1)
      cout << endl;
  }

  return 0;
}