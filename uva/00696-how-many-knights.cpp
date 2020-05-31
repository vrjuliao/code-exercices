#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, k, k1, k2;
    
    while(true){
        cin >> x >> y;
        if(!x && !y) break;

        if(x==2 && y>=4){
            k1 = y/2;
            k = k1*2;
            if(y&1 || k1&1) k+=2;
        } else if(y==2 && x>=4){
            k1 = x/2;
            k = k1*2;
            if(x&1 || k1&1) k+=2;
        } else if((x>=3 && y>=3)){
            k = static_cast<int>(ceil(x*y/2.0));
        } else if(x==1) k = y;
        else if(y==1) k = x;
        else if(!x || !y) k = 0;
        else k = 4;
        cout << k << " knights may be placed on a " << x << " row " << y << " column board." << endl;
    }
    
    return 0;
}