#include <bits/stdc++.h>

using namespace std;

pair<int, int> compare(int n, vector<int> &secret, vector<int> &guess){
    vector<int> secret_chars = vector<int>(10);
    vector<int> guess_chars = vector<int>(10);
    int i, strong, weak;

    for(i=0; i<10; i++){
        secret_chars[i] = 0;
        guess_chars[i] = 0;
    }

    for(i=0; i<n; i++){
        secret_chars[secret[i]]++;
    }

    strong = 0;
    weak = 0;
    for(i=0; i<n; i++){
        if(secret[i] == guess[i]){
            strong++;
            secret_chars[secret[i]]--;
        } else {
            guess_chars[guess[i]]++;
        }
    }
    
    for(i=0; i<10; i++){
        weak += min(guess_chars[i], secret_chars[i]);
    }

    return make_pair(strong, weak);

}

int main(){
    int n, i, first_guess, round=0;

    vector<int> secret = vector<int>(1000);
    vector<int> guess = vector<int>(1000);
    pair<int, int> result;
    cin >> n;
    while(n > 0){
        for(i=0; i<n; i++){
            cin >> secret[i];
        }

        round++;
        cout << "Game " << round << ':' << endl;
        cin >> first_guess;
        while(first_guess > 0){
            guess[0] = first_guess;
            for(i=1; i<n; i++){
                cin >> guess[i];
            }
            result = compare(n, secret, guess);
            cout << "    (" << result.first << ',' << result.second << ')' << endl;
            cin >> first_guess;
        }
        for(i=1; i<n; i++){
            cin >> first_guess;
        }
        cin >> n;
    }

    return 0;
}