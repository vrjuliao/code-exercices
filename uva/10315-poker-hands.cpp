#include <bits/stdc++.h>

using namespace std;

int get_index_by_card(string s){
    int index=0;
    switch(s[0]){
        case 'A': index=12;
            break;
        case 'K': index=11;
            break;
        case 'Q': index=10;
            break;
        case 'J': index=9;
            break;
        case 'T': index=8;
            break;
        default: index=s[0] - '0' - 2;
            break;
    }

    switch(s[1]){
        case 'H': index+=13;
            break;
        case 'D': index+=26;
            break;
        case 'C': index+=39;
            break;
    }
    return index;
};

void renew(int v[]){
    for(int i=0; i < 55; i++){
        v[i] = 0;
    }
}

static const int HIGH_CARD = 0;
static const int PAIR = 1;
static const int TWO_PAIRS = 2;
static const int THREE_OF_A_KIND = 3;
static const int STRAIGHT = 4;
static const int FLUSH = 5;
static const int FULL_HOUSE = 6;
static const int FOUR_OF_A_KIND =7;
static const int STRAIGHT_FLUSH = 8;

void print_hand(int hand[]){
    for(int i=0; i<52; i++) cout << hand[i] << " ";
    cout << endl;
}

int str_flush(int hand[]){
    int suit = -1;
    int i;
    for(i = 0; i<13 && suit == -1; i++){
        if(hand[i]) suit = i;
        else if(hand[i+13]) suit = i+13;
        else if(hand[i+26]) suit = i+26;
        else if(hand[i+39]) suit = i+39;
    }
    if(suit%13>8) return -1;
    bool has_flush = true;
    for(int i=0; i<5; i++) {
        has_flush = has_flush && hand[suit+i];
    }
    if(has_flush) return (suit+4)%13;
    return -1; 
}

int four_kind(int hand[]){
    for(int i = 0; i<13; i++){
        if(hand[i]){
            if(hand[i+13] && hand[i+26] && hand[i+39]) return i;
            else return -1;
        }
    }
    return -1;
}

int three_kind(int hand[]){
    for(int i=0; i<13; i++){
        if(hand[i] && hand[i+13]){
            if(hand[i+26] || hand[i+39])
                return i;
        } else if(hand[i] && hand[i+39]){
            if(hand[i+26] || hand[i+13])
                return i;
        } else if(hand[i+13] && hand[i+26]){
            if(hand[i+39]){
                return i;
            }
        }
    }
    return -1;
}

int full_house(int hand[]){
    int three_index = three_kind(hand);
    int pair_index;

    if(three_index < 0) return -1;
    
    for(int i=0; i<13; i++){
        if(i==three_index) continue;
        if((hand[i] && hand[i+13]) || (hand[i] && hand[i+26]) || 
            (hand[i] && hand[i+39]) || (hand[i+13] && hand[i+26]) ||
            (hand[i+13] && hand[i+39]) || (hand[i+26] && hand[i+39])){
            pair_index = i;
            break;
        }
    }

    if(three_index >= 0 && pair_index >= 0) return three_index;
    return -1;
}

int flush(int hand[]){
    int i, count=0;
    for(i=0; i<13 && count!=5; i++) count+=hand[i];
    if(count>0 && count<5) return -1;
    else if(count==5) return i-1;
    
    for(i=13; i<26 && count!=5; i++) count+=hand[i];
    if(count>0 && count<5) return -1;
    else if(count==5) return i-1;
    
    for(i=26; i<39 && count!=5; i++) count+=hand[i];
    if(count>0 && count<5) return -1;
    else if(count==5) return i-1;
    
    for(i=39; i<52 && count!=5; i++) count+=hand[i];
    if(count>0 && count<5) return -1;
    else if(count==5) return i-1;

    return -1;
}

int straight(int hand[]){
    int index = -1;;
    for(int i=0; i<13; i++){
        if(hand[i] || hand[i+13] || hand[i+26] || hand[39]){
            index = i;
            break;
        }
    }
    if(index>8) return -1;
    bool has_straight = true;
    for(int i=1; i<5; i++){
        has_straight = has_straight && (hand[index+i] || hand[index+i+13] || hand[index+i+26] || hand[index+i+39]);
    }
    if(has_straight) return index+5;
    return -1;
}



// returns 1 if occurs a pair or 0 in other case
// p.first.first contains the highest pair index
// p.first.second contains the smaller pair index
// p.second contains the card not included in the pair
int two_pairs(int hand[], pair<pair<int, int>, int> &p){
    bool pair1, pair2;
    pair1=false;
    pair2=false;

    pair<pair<int,int>, int> returned_value;
    for(int i=0; i<13; i++){
        if((hand[i] && hand[i+13]) || (hand[i] && hand[i+26]) || 
            (hand[i] && hand[i+39]) || (hand[i+13] && hand[i+26]) ||
            (hand[i+13] && hand[i+39]) || (hand[i+26] && hand[i+39])){
                if(pair1) {
                    pair2=true;
                    p.first.second = i;
                }
                else {
                    pair1 = true;
                    p.first.first = i;
                }
        } else if(hand[i] || hand[i+13] || hand[i+26] || hand[i+39]){
            p.second = i;
        }
    }

    if(pair1 && pair2) return 1;
    return -1;
}

// returns 1 if occurs a pair or 0 in other case
// p.first.first contains the pair index
// p.first.second contains the highest card not included in the pair
int pair_(int hand[]){
    for(int i=0; i<13; i++){
        if((hand[i] && hand[i+13]) || (hand[i] && hand[i+26]) || 
            (hand[i] && hand[i+39]) || (hand[i+13] && hand[i+26]) ||
            (hand[i+13] && hand[i+39]) || (hand[i+26] && hand[i+39])){
            return i;
        }
    }
    return -1;
}

int high_card(int hand[]){
    for(int i=12; i>=0; i--){
        if(hand[i] || hand[i+13] || hand[i+26] || hand[i+39]){
            return i;
        }
    }
    return -1;
}

void get_rank(int hand[], int &rank, int &solve_card, pair<pair<int, int>, int> &p){
    int rk = -1;

    if((rk = str_flush(hand)) >= 0) rank = STRAIGHT_FLUSH;
    else if((rk = four_kind(hand)) >= 0) rank = FOUR_OF_A_KIND;
    else if((rk = full_house(hand)) >= 0) rank = FULL_HOUSE;
    else if((rk = flush(hand)) >= 0) rank = FLUSH;
    else if((rk = straight(hand)) >= 0) rank = STRAIGHT;
    else if((rk = three_kind(hand)) >= 0) rank = THREE_OF_A_KIND;
    else if((rk = two_pairs(hand, p)) >= 0) rank = TWO_PAIRS;
    else if((rk = pair_(hand)) >= 0) rank = PAIR;
    else {
        rk = high_card(hand);
        rank = HIGH_CARD;
    }
    solve_card = rk;
}

// if black wins returned value > 0
// if white wins returned value < 0
int cmp_flush(int white[], int black[], int ws, int bs){
    int returned_value = 0;
    if(ws%13 > bs%13) return -1;
    else if (bs%13 > ws%13) return 1;
    else {
        for(int i=1; i<ws%13; i++){
            if(white[ws-i]){
                if(black[bs-i]){
                    continue;
                } else{
                    return -1;
                }
            } else if(black[bs-i]){
                return 1;
            }
        }
        return 0;
    }
    return returned_value;
}

int cmp_high_card(int white[], int black[], int ws, int bs){
    int returned_value = 0;
    if(ws > bs) return -1;
    else if (bs > ws) return 1;
    else {
        for(int i=1; i<ws; i++){
            if(white[ws-i] || white[ws-i+13] || white[ws-i+26] || white[ws-i+39]){
                if(black[bs-i] || black[bs-i+13] || black[bs-i+26] || black[bs-i+39]){
                    continue;
                } else{
                    return -1;
                }
            } else if(black[bs-i] || black[bs-i+13] || black[bs-i+26] || black[bs-i+39]){
                return 1;
            }
        }
        return 0;
    }
    return returned_value;
}

int cmp_two_pairs(int white[], int black[], pair<pair<int, int>, int> ws, pair<pair<int, int>, int> bs){
    if(ws.first.second == bs.first.second){
        if(ws.first.first == bs.first.first){
            if(ws.second == bs.second){
                return 0;
            } else if(ws.second < bs.second){
                return 1;
            } else{
                return -1;
            }
        } else if(ws.first.first < bs.first.first){
            return 1;
        } else {
            return -1;
        }
    } if(ws.first.second < bs.first.second){
        return 1;
    } else {
        return -1;
    }
    return 0;


}

int cmp_pairs(int white[], int black[], int ws, int bs){
    if(ws == bs){
        for(int i=12; i>=0; i--){
            if(i==ws) continue;
            if(white[i] || white[i+13] || white[i+26] || white[i+39]){
                if(black[i] || black[i+13] || black[i+26] || black[i+39]){
                    continue;
                } else {
                    return -1;
                }
            } else if(black[i] || black[i+13] || black[i+26] || black[i+39]){
                // cout << " high card " << i << endl;
                return 1;
            }
        }
        return 0;
    } else if(ws < bs){
        return 1;
    } else {
        return -1;
    }
    return 0;
}

void print_answer(int ans){
    if(ans > 0)
        cout << "Black wins." << endl;        
    else if(ans < 0)
        cout << "White wins." << endl;
    else cout << "Tie." << endl;
}

int main(){
    // indexing (0 - 13)%13: card 2 until ace
    // S begin in 0, H begin in 13, D begin in 26, C begin in 39
    int black[55];
    int white[55];
    int bsolve_card, wsolve_card, brank, wrank;
    string s;
    int index;
    while(cin >> s){
        renew(black);
        renew(white);
        index = get_index_by_card(s);
        black[index] = true;
        for(int i=0; i <4; i++){
            cin >> s;
            index = get_index_by_card(s);
            black[index] = true;
        }

        for(int i=0; i <5; i++){
            cin >> s;
            index = get_index_by_card(s);
            white[index] = true;
        }
        pair<pair<int, int>, int> pw;
        pair<pair<int, int>, int> pb;
        get_rank(black, brank, bsolve_card, pb);
        get_rank(white, wrank, wsolve_card, pw);
        // cout << "b: " << brank << " - w: " << wrank << endl;
        // cout << "bs: " << bsolve_card << " - ws: " << wsolve_card << endl;
        if(wrank == brank){
            int ccmp;
            switch(wrank){
                default:
                    if(bsolve_card > wsolve_card) ccmp = 1;
                    else if(bsolve_card < wsolve_card) ccmp = -1;
                    else ccmp = 0;
                break;
                case PAIR:
                    ccmp = cmp_pairs(white, black, wsolve_card, bsolve_card);
                break;
                case TWO_PAIRS:
                    ccmp = cmp_two_pairs(white, black, pw, pb);
                break;
                case FLUSH:
                    ccmp = cmp_flush(white, black, wsolve_card, bsolve_card);
                break;
                case HIGH_CARD:
                    ccmp = cmp_high_card(white, black, wsolve_card, bsolve_card);
                break;
            }
            print_answer(ccmp);
        } else {
            if(brank > wrank)
                cout << "Black wins." << endl;
            else
                cout << "White wins." << endl;
        }
    }

    return 0;
}