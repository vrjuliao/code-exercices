#include <bits/stdc++.h>

using namespace std;

int vec[10000010];

int main(){
    int rounds, n, has_n;
    cin >> rounds;
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 1;
    has_n = 2;
    while(rounds--){
        cin >> n;
        while(n > has_n){
            has_n++;
            vec[has_n] = vec[has_n-1] + vec[has_n-2] - vec[has_n-3];
        }
        cout << vec[n] << endl;
    }

    return 0;
}