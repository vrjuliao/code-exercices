#include <bits/stdc++.h>

using namespace std;


int winner(char a, char b){
    if(a == 'R'){
        if(b == 'P') return -1;
        else if (a==b) return 0;
        else return 1;
    } else if(a == 'S'){
        if(b == 'R') return -1;
        else if (a==b) return 0;
        else return 1;
    } else {
        if(b == 'S') return -1;
        else if (a==b) return 0;
        else return 1;
    }
}

void battle(vector<vector<char>> *current, vector<vector<char>> *after, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            (*after)[i][j] = (*current)[i][j];
        }
    }

    int i, j, win;
    for(i=0; i<r-1; i++){
        for(j=0; j<c-1; j++){
            win = winner((*current)[i][j], (*current)[i][j+1]);
            if(win > 0)
                (*after)[i][j+1] = (*current)[i][j];
            else if(win < 0)
                (*after)[i][j] = (*current)[i][j+1];
            
            win = winner((*current)[i][j], (*current)[i+1][j]);
            if(win > 0)
                (*after)[i+1][j] = (*current)[i][j];
            else if(win < 0)
                (*after)[i][j] = (*current)[i+1][j];
        }
        win = winner((*current)[i][j], (*current)[i+1][j]);
        if(win > 0)
            (*after)[i+1][j] = (*current)[i][j];
        else if(win < 0)
            (*after)[i][j] = (*current)[i+1][j];
    }
    for(j=0; j<c-1; j++){
        win = winner((*current)[i][j], (*current)[i][j+1]);
        if(win > 0)
            (*after)[i][j+1] = (*current)[i][j];
        else if(win < 0)
            (*after)[i][j] = (*current)[i][j+1];
    }
}


void print_matrix(vector<vector<char>> *after, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << (*after)[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int rounds;
    int columns, rows, days;
    char c;
    vector<vector<char>> m1, m2, *current, *last, *aux;
    m1 = vector<vector<char>>(110);
    m2 = vector<vector<char>>(110);

    for(int i=0; i<110; i++){
        m1[i] = vector<char>(110);
        m2[i] = vector<char>(110);
    }

    current = &m1;
    last = &m2;
    cin >> rounds;
    while(rounds--){
        cin >> rows >> columns >> days;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                cin >> c;
                (*current)[i][j] = c;
                (*last)[i][j] = c;
            }
            cin.ignore();
        }
        // print_matrix(current, rows, columns);
        while(days--){
            battle(current, last, rows, columns);
            aux = last;
            last = current;
            current = aux;
            // print_matrix(current, rows, columns);
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                cout << (*current)[i][j];
                if((*current)[i][j] != 'R'
                && (*current)[i][j] != 'S'
                && (*current)[i][j] != 'P'){
                    cout << static_cast<int>((*current)[i][j]);
                }
            }
            cout << endl;
        }
        if(rounds >= 1) cout << endl;
    }
    
    return 0;
}