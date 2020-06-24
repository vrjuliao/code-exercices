#include <bits/stdc++.h>

using namespace std;

int field[101][101];

void clear_matrix(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            field[i][j] = 0;
        }
    }
}

int main(){
    int n, m, round = 1;
    string input;
    cin >> n >> m;
    while (n>0){
        clear_matrix(n, m);
        cout << "Field #" << round << ':' << endl;
        round++;
        for(int i=0; i<n; i++){
            cin >> input;
            for(int j=0; j<m; j++){
                if(input[j] == '*'){
                    field[i][j] = -1;
                    int i_, j_;
                    i_ = i-1;
                    if(i_>=0){
                        j_ = j-1;
                        if(j_>=0 && field[i_][j_]>=0) field[i_][j_]++;
                        j_++;
                        if(field[i_][j_]>=0) field[i_][j_]++;
                        j_++;
                        if(j_<m && field[i_][j_]>=0) field[i_][j_]++;
                    }
                    i_++;
                    j_=j-1;
                    if(j_>=0 && field[i_][j_]>=0) field[i_][j_]++;
                    j_+=2;
                    if(j_<m && field[i_][j_]>=0) field[i_][j_]++;
                    i_++;
                    if(i_<n){
                        j_=j-1;
                        if(j_>=0 && field[i_][j_]>=0) field[i_][j_]++;
                        j_++;
                        if(field[i_][j_]>=0) field[i_][j_]++;
                        j_++;
                        if(j_<m && field[i_][j_]>=0) field[i_][j_]++;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(field[i][j] != -1){
                    cout << field[i][j];
                } else {
                    cout << '*';
                }
            }
            cout << endl;
        }
        cin >> n >> m;
        if(n) cout << endl;
        
    }
    return 0;
}