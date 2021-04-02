// start 2020/09/08 9:45pm
// end 2020/09/08 10:06pm
#include <bits/stdc++.h>

using namespace std;

bool is_invalid_char(char c){
    return (c == ' ' || c == '.' || c == '!' || c == '?' || c == ',');
}

bool is_palindrome(string s){
    int size = s.size();
    int left = 0, right = size-1;
    
    for_each(s.begin(), s.end(), [](char &c){
        c = tolower(c);
    });

    while(left<right){
        if(is_invalid_char(s[left])){
            left++;
            continue;
        }
        if(is_invalid_char(s[right])){
            right--;
            continue;
        }

        if(s[left] != s[right]){
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main(){
    string s;

    getline(cin, s);
    while(s != "DONE"){
        if(is_palindrome(s)){
            cout << "You won't be eaten!" << endl;
        } else {
            cout << "Uh oh.." << endl;
        }        
        getline(cin, s);
    }
    
    return 0;
}