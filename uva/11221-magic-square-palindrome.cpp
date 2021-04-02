// start 2020/09/08 10:10pm
// end 2020/09/08 10:50pm
#include <bits/stdc++.h>

using namespace std;

bool is_invalid_char(char c){
    return (
        c == ' ' ||
        c == ',' ||
        c == ':' ||
        c == '?' ||
        c == '!' ||
        c == ')' ||
        c == '(' ||
        c == '.');
}

int fill_table(vector<vector<char>> &table, const string &s){
    int size = s.size();
    int normalized_size = size;
    string a = "";
    for(int i=0; i<size; i++){
        if(is_invalid_char(s[i])) {
            normalized_size--;
        } else {
            a += s[i];
        }
    }
    double _k = sqrt(normalized_size);
    int k = floor(_k);

    if(k != _k){
        return -1;
    } else {
        for(int i=0; i<k; i++){
            for (int j=0; j<k; j++){
                table[i][j] = a[(i*k)+j];
            }
        }
    }
    return k;
}

bool is_squared_palindrome(const vector<vector<char>> &table, int k){
    for(int i=0; i<k; i++){
        if(table[i][0] != table[0][i]) return false;
        else if(table[i][0] != table[k-1][k-i-1]) return false;
        else if(table[i][0] != table[k-i-1][k-1]) return false;
    }
    return true;
}


int main(){
    vector<vector<char>> table = vector<vector<char>>(110);
    for(int i=0; i<110; i++)
        table[i] = vector<char>(110);

    int rounds, k;
    cin >> rounds;
    string s;
    cin.ignore();
    for(int i=1; i<=rounds; i++){
        getline(cin, s);

        k = fill_table(table, s); 
        cout << "Case #" << i << ':' << endl;
        if(k >= 0){
            if(is_squared_palindrome(table, k)){
                cout << k << endl;
            } else {
                cout << "No magic :(" << endl;
            }
        } else {
            cout << "No magic :(" << endl;
        }
    }

    
    return 0;
}