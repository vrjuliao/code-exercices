#include <bits/stdc++.h>

using namespace std;

bool stopped(int v[]){
    int qtt_cards = v[4]-1;
    return v[0] || (v[1] && qtt_cards>=1) || (v[2] && qtt_cards>=2);
}

int qtt_cards(int v[]){
    return v[4];
}
int qtt_points_by_cards(int v[]){
    int points = 0;
    int cards = qtt_cards(v);
    if(cards == 2) points=1;
    else if(!cards || cards == 1) points=2;

    return points;
}

int suit_points(int v[]){
    int points = 0;
    if(v[0]) points+=4;
    if(v[1]) points+=3;
    if(v[2]) points+=2;
    if(v[3]) points+=1;

    int qtt_other = v[4]-1;
    if(v[1] && !qtt_other) points-=1;
    if(v[2] && (!qtt_other || qtt_other==1)) points-=1;
    if(v[3] && (!qtt_other || qtt_other==1 || qtt_other==2)) points-=1;

    return points;
}

void renew(int S[], int H[], int C[], int D[]){
    for(int i=0; i<5; i++){
        S[i] = 0;
        H[i] = 0;
        D[i] = 0;
        C[i] = 0;
    }
}

int main(){
    // 0 = A, 1 = K, 2 = Q, 3 = J, 4 = cards qtt
    int S[5] = {0};
    int H[5] = {0};
    int C[5] = {0};
    int D[5] = {0};

    string s;
    int *pointer;
    int points;
    while(cin >> s){
        int i=1;
        points = 0;
        renew(S, H, C, D);
        do{
            switch(s[1]){
                case 'S':
                    pointer = S;
                    break;
                case 'H':
                    pointer = H;
                    break;
                case 'C':
                    pointer = C;
                    break;
                case 'D':
                    pointer = D;
                    break;
            }

            switch(s[0]){
                case 'A':
                    pointer[0] = 1;
                    break;
                case 'K':
                    pointer[1] = 1;
                    break;
                case 'Q':
                    pointer[2] = 1;
                    break;
                case 'J':
                    pointer[3] = 1;
                    break;
            }
            pointer[4]++;
            if(i==13) break;
            cin >> s;
            i++;
        } while(true);
        points += suit_points(S);
        points += suit_points(H);
        points += suit_points(C);
        points += suit_points(D);
        if(points >= 16 && stopped(S) && stopped(H) && stopped(C) && stopped(D)) {
                cout << "BID NO-TRUMP" << endl;
        } else {
            points += qtt_points_by_cards(S);
            points += qtt_points_by_cards(H);
            points += qtt_points_by_cards(C);
            points += qtt_points_by_cards(D);
            if(points >= 14){
                int s = qtt_cards(S);
                int h = qtt_cards(H);
                int c = qtt_cards(C);
                int d = qtt_cards(D);

                cout << "BID ";
                if(s>=h && s>=c && s>=d) cout << 'S';
                else if(h>=s && h>=c && h>=d) cout << 'H';
                else if(d>=h && d>=s && d>=c) cout << 'D';
                else if(c>=h && c>=s && c>=d) cout << 'C';
                cout << endl;
            } else {
                cout << "PASS" << endl;
            }

        }
        
    }

    return 0;
}