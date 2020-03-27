#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, n, round = 0;
    string s, offer;
    double price;
    int products;
    cin >> n >> p;
    while(n || p){
        // set<string> myset;
        cin.ignore();
        for(int i=0; i <n; i++){
            getline(cin, s);
            // myset.insert(s);
        }
        int count_pdct, j;
        string cur_offer;
        double cur_price;
        products = 0;
        price = 2000000000;
        
        for(int i=0; i<p; i++){
            getline(cin, cur_offer);
            cin >> cur_price >> j;
            cin.ignore();
            count_pdct = j;
            int k;
            for(k=0; k<j; k++){
                getline(cin, s);
                // cin >> s;
                /*if(myset.find(s) != myset.end()){
                    count_pdct++;
                }*/
            }
            // if(k>0) cin.ignore();
            if(count_pdct > products){
                products = count_pdct;
                offer = cur_offer;
                price = cur_price;
            } else if(count_pdct == products && price > cur_price){
                products = count_pdct;
                offer = cur_offer;
                price = cur_price;
            }
        }
        if(round > 0) cout << endl;
        round++;
        cout << "RFP #" << round << endl << offer << endl;
        cin >> n >> p;
    }

    return 0;
}