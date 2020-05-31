#include <bits/stdc++.h>

using namespace std;

int queen(int x, int y);
int king(int x, int y);
int knight(int x, int y);
int rook(int x, int y);


int main(){
    int rounds, x, y, i;
    char c;
    cin >> rounds;
    while(rounds--){
        cin >> c >> x >> y;
        switch (c){
            case 'K': i=king(x,y); break;
            case 'Q': i=queen(x,y); break;
            case 'k': i=knight(x,y); break;
            case 'r': i=rook(x,y); break;
        }
        cout << i << endl;
    }
    return 0;
}

int queen(int x, int y){
    if(x>y) return y;
    return x;
}

int king(int x, int y){
    return static_cast<int>(ceil(x/2.0)*ceil(y/2.0));
}

int knight(int x, int y){
    return static_cast<int>(ceil((x*y)/2.0));
}

int rook(int x, int y){
    if(x > y) return y;
    return x;
}