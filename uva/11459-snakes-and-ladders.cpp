#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> snakes = vector<pair<int, int>>(50);
vector<int> players = vector<int>(1000000);

void clear_vector(int qt_players){
    for(int i=0; i<qt_players; i++){
        players[i] = 1;
    }
}

int get_position(int current, int die, int qt_snakes){
    int new_pos = current+die;
    if(new_pos >= 100){
        return 100;
    }
    for(int i=0; i<qt_snakes; i++){
        if(snakes[i].first == new_pos) return snakes[i].second;
    }
    return new_pos;
}

int main(){
    int rounds, qt_players, qt_snakes, rolls, tail, mouth, die;
    cin >> rounds;
    bool wins;
    while(rounds--){
        cin >> qt_players >> qt_snakes >> rolls;
        clear_vector(qt_players);
        wins = false;
        for(int i=0; i<qt_snakes; i++){
            cin >> mouth >> tail;
            snakes[i] = make_pair(mouth, tail);
        }

        for(int i=0; i<rolls; i++){
            cin >> die;
            if(!wins){
                players[i%qt_players] = get_position(players[i%qt_players],
                                                     die, qt_snakes);
                wins = players[i%qt_players] == 100;
            }
        }

        for(int i=0; i<qt_players; i++){
            cout << "Position of player " << i+1 << " is " << players[i] << '.' << endl;
        }

    }

    return 0;
}