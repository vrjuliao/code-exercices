// start 2020/09/09 9:45pm
// end 2020/09/10 9:57pm
#include <bits/stdc++.h>

using namespace std;

struct word {
    string value;
    int quantity;
    map<char, int> wmap;
};

string str_tolower(const string s){
    string result = s;
    for_each(result.begin(), result.end(), [](char &c){
        c = ::tolower(c);
    });
    return result;
}

bool in_map(vector<word> &words, const map<char, int> &wmap){
    bool match_word = false;
    map<char, int>::iterator k;
    for(auto it = words.begin(); it != words.end(); ++it){

        if(it->wmap.size() == wmap.size()){
            match_word = true;
        
            for(auto jt =wmap.begin(); jt != wmap.end(); ++jt){
                k = it->wmap.find(jt->first);
                // se o caractere de um mapa está no outro mapa
                if(k != it->wmap.end()){
                    // se a quantidade de ocorrências do caractere
                    // é igual nos dois maps
                    if(k->second != jt->second){
                        match_word = false;
                        break;
                    }
                } else {
                    match_word = false;
                    break;
                }
            }
            if(match_word){
                it->quantity++;
                return true;
            }
        }
    }
    return match_word;
}

map<char, int> word_map(string s){
    map<char, int> wmap = map<char, int>();
    int size = s.size();
    map<char, int>::iterator it;
    for(int i=0; i<size; i++){
        it = wmap.find(s[i]);
        if(it != wmap.end()){
            it->second++;
        } else {
            wmap[s[i]] = 1;
        }
    }
    return wmap;
}

bool compare(const word &a, const word &b){
    return a.value < b.value;
}

int main(){
    vector<word> words_map = vector<word>();
    
    string input, lower_str;
    cin >> input;

    while(input != "#"){
        lower_str = str_tolower(input);
        map<char, int> wmap = word_map(lower_str);
        if(!in_map(words_map, wmap)){
            word _w = word();
            _w.value = input;
            _w.wmap = wmap;
            _w.quantity = 1;
            words_map.push_back(_w);
        }
        cin >> input;
    }
    sort(words_map.begin(), words_map.end(), compare);
    for(auto it: words_map){
        if(it.quantity == 1){
            cout << it.value << endl;
        }
    }


    return 0;
}