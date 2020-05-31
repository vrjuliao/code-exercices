#include <bits/stdc++.h>

using namespace std;

int translate_value_card(string s){
    switch(s[0]){
        case 'A':
        case 'K':
        case 'Q':
        case 'J':
        case 'T':
            return 10;
        default: return s[0] - '0';
    }
}

int main(){
    string cards[55];
    int y, x, rounds;
    cin >> rounds;

    for(int i=1; i<=rounds; i++){
        y=0;
        for(int j=0; j<52; j++){
            cin >> cards[j];
        }
        int top_index = 26;
        for(int j=0; j<3; j++){
            x = translate_value_card(cards[top_index]);
            y+=x;
            top_index = top_index - (10-x);
        }

        cout << "Case " << i << ": ";
        if(y<=top_index)
            cout << cards[y];
        else 
            cout << cards[28+(y-top_index)];
        cout << endl;
    }
    return 0;
}