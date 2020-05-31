#include <bits/stdc++.h>

using namespace std;

void renew_vector(bool *map_char){
    for(int i=0; i <26; i++) map_char[i] = false;
}

int main(){
    string word, contestant;
    bool map_char[26];
    bool verified_char[26];
    int round;
    int errors, different_letters;
    int s, index;
    cin >> round;
    while(round != -1){
        renew_vector(map_char);
        renew_vector(verified_char);
        cin >> word;
        cin >> contestant;
        //char presence
        s = word.size();
        different_letters = 0;
        for(int i=0; i<s; i++){
            index = word[i]-'a';
            if(!map_char[index]) different_letters++;
            map_char[index] = true;
        }

        //verifying char existence
        s = contestant.size();
        for(int i=0; i<s; i++){
            index = contestant[i]-'a';
            verified_char[index] = true;
        }

        errors = 0;
        s = contestant.size();
        for(int i=0; i<s; i++){
            index = contestant[i]-'a';
            if(verified_char[index]) {
                verified_char[index] = false;
                if(map_char[index]) different_letters--;
                else errors++;
            }
            if(!different_letters || errors==7) break;
        }

        cout << "Round " << round << endl << "You ";
        if(!different_letters) cout << "win";
        else if(errors == 7) cout << "lose";
        else cout << "chickened out";

        cout << "." << endl;
        
        cin >> round;
    }
    return 0;
}