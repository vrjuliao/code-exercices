#include <bits/stdc++.h>

using namespace std;


bool is_mirrored(map<char, char> &mirror, string s){
    int size = s.size();
    int half = size/2;
    size--;
    for(int i=0; i<half; i++){
        if(s[i] == 'O' || s[i] == '0'){
            if(s[size-i] == 'O' || s[size-i] == '0'){
                continue;
            } else {
                return false;
            }
        } else {
            auto it = mirror.find(s[i]);
            if(it == mirror.end()){
                return false;
            } else {
                if(it->second != s[size-i]) {
                    return false;
                }
            }
        }
    }
    if(!(size & 1)){
        auto it = mirror.find(s[half]);
        if(it->second == 'O' || it->second == '0'){
            return true;
        } else if(it == mirror.end()){
            return false;
        } else if(it->second != it->first){
            return false;
        }
        return true;
    }
    return true;
}

bool is_palindrome(string s){
    int size = s.size();
    int half = size/2;
    size--;
    for(int i=0; i<half; i++){
        if(s[i] != s[size-i])
            return false;
    }
    return true;
}

int main(){
    map<char, char> mirror = map<char, char>();
    mirror['E'] = '3';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['0'] = 'O';
    mirror['O'] = '0';
    mirror['S'] = '2';
    mirror['Z'] = '5';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['A'] = 'A';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['M'] = 'M';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['8'] = '8';
    mirror['1'] = '1';

    string s;
    bool palindrome, mirrored;
    while(getline(cin, s)){
        mirrored = is_mirrored(mirror, s);
        palindrome = is_palindrome(s);
        cout << s;
        if(palindrome && mirrored){
            cout << " -- is a mirrored palindrome.";
        } else if(palindrome){
            cout << " -- is a regular palindrome.";
        } else if(mirrored){
            cout << " -- is a mirrored string.";
        } else {
            cout << " -- is not a palindrome.";
        }
        cout << endl << endl;

    }    
    return 0;
}