#include <bits/stdc++.h>

using namespace std;

void print_value(array<int, 3> &prince, array<int, 3> &princess){
    while(prince[0]==prince[1] || prince[0]==prince[2] ||prince[0]==princess[2])
        prince[0]++;
    if(prince[0]>52) cout << -1 << endl;
    else cout << prince[0] << endl;
}

int main(){
    array<int, 3> princess = {0, 0, 0};
    array<int, 3> prince = {0, 0, 0};

    while(true){
        for(int i=0; i<3; i++){
            prince[i] = 0;
            princess[i] = 0;
        }

        cin >> princess[0] >> princess[1] >> princess[2];
        cin >> prince[0] >> prince[1];
    
        if(!princess[0]) break;

        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());

        
        if(prince[1] > princess[2]){
            prince[0] = 1;
            if(princess[0]==1) prince[0]++;
            if(princess[1]==2) prince[0]++;
            print_value(prince, princess);
        } else if(prince[2] > princess[1] &&
        prince[1] > princess[1]){
            prince[0] = princess[1]+1;
            print_value(prince, princess);
        } else if(prince[2] > princess[2] && prince[1] < prince[2]){
            prince[0] = princess[2];
            print_value(prince, princess);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}