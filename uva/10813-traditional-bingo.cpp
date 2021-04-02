#include <bits/stdc++.h>

using namespace std;

pair<int, int> get_location(vector<vector<pair<int, bool>>> &card, int number){    
    int column = -1, row = -1;
    if(number >=1 && number <=15){
        column = 0;
    } else if(number >=16 && number <=30){
        column = 1;
    } else if(number >=31 && number <=45){
        column = 2;
    } else if(number >=46 && number <=60){
        column = 3;
    } else {
        column = 4;
    }

    for(int i=0; i<5; i++){
        if (card[i][column].first == number){
            row = i;
        }
    }
    return make_pair(row, column);
}

void put_number(vector<vector<pair<int, bool>>> &card, const pair<int, int> &location){
    if(location.first != -1){
        card[location.first][location.second].second = true;
    }
}

bool is_complete(vector<vector<pair<int, bool>>> &card, const pair<int, int> &location){

    if(location.first != -1){
        bool aux = false;
        if(location.first == location.second){
            aux = true;
            for(int i=0; i<5; i++){
                aux = aux && card[i][i].second;
            }
        } else if((location.second + location.first) == 4){
            aux = true;
            for(int i=0; i<5; i++){
                aux = aux && card[i][4-i].second;
            }
        }
        if(aux){
            return aux;
        } else {
            int column, row;
            aux = true;
            column = location.second;
            for(int i=0; i<5; i++){
                aux = aux && card[i][column].second;
            }
            
            if(aux) return aux;

            aux = true;
            row = location.first;
            for(int i=0; i<5; i++){
                aux = aux && card[row][i].second;
            }
            return aux;
        }
    }
    return false;
}

int main(){
    vector<vector<pair<int, bool>>> card = vector<vector<pair<int, bool>>>(5);

    int n; // games number
    int input, number, rounds;
    pair<int, int> location;
    bool complete;
    cin >> n;

    for(int i=0; i<5; i++){
        card[i] = vector<pair<int, bool>>(5);
    }
    while(n--){
        for(int i=0; i<2; i++){
            for(int j=0; j<5; j++){
                cin >> input;
                card[i][j] = make_pair(input, false);
            }
        }
        cin >> input;
        card[2][0] = make_pair(input, false);
        cin >> input;
        card[2][1] = make_pair(input, false);
        card[2][2] = make_pair(0, true);
        cin >> input;
        card[2][3] = make_pair(input, false);
        cin >> input;
        card[2][4] = make_pair(input, false);

        for(int i=3; i<5; i++){
            for(int j=0; j<5; j++){
                cin >> input;
                card[i][j] = make_pair(input, false);
            }
        }

        complete = false;
        for(int i=1; i<=75; i++){
            cin >> input;

            if(!complete){
                location = get_location(card, input);

                put_number(card, location);
                if(is_complete(card, location)){
                    complete = true;
                    rounds = i;
                }
            }
        }
        cout << "BINGO after " << rounds << " numbers announced" << endl;
    }
}