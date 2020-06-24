#include <bits/stdc++.h>

using namespace std;

void clear_vector(vector<bool> &bag, int n){
    for(int i=0; i<=n; i++)
        bag[i] = false;
}

void apply_all_numbers(vector<bool> &bag, int n, vector<int> &remaining, int b){
    for(int i=0; i<b; i++){
        for(int j=0; j<b; j++){
            bag[abs(remaining[i] - remaining[j])] = true;
        }
    }
}

int main(){
    vector<bool> bag = vector<bool>(100);
    vector<int> remaining = vector<int>(100);

    int n, b;
    bool result;
    cin >> n >> b;
    while(n && b) {
        clear_vector(bag, n);
        for(int i=0; i<b; i++)
            cin >> remaining[i];
        
        apply_all_numbers(bag, n, remaining, b);
        result = true;
        for(int i=0; i<=n; i++)
            result = (result && bag[i]);

        if(result) cout << 'Y' << endl;
        else cout << 'N' << endl;
        cin >> n >> b;
    }
    
    return 0;
}