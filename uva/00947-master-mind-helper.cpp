#include <bits/stdc++.h>

using namespace std;

void generate_codes(int n, int depth, int max_depth, vector<int> &codes){
    if(depth == max_depth){
        codes.push_back(n);
        return;
    }

    for(int i=1; i<10; i++){
        generate_codes(n*10+i, depth+1, max_depth, codes);
    }
}

pair<int, int> compare(int n, int code){
    vector<int> n_c = vector<int>(10);
    vector<int> code_c = vector<int>(10);

    pair<int, int> result = pair<int, int>();
    result.first = 0;
    result.second = 0;

    for(int i=0; i<10; i++){
        n_c[i] = 0;
        code_c[i] = 0;
    }

    int tmp = code;
    while(tmp != 0){
        code_c[tmp%10]++;
        tmp /= 10;
    }

    while(n!=0){
        if(n%10 == code%10){
            result.first++;
            code_c[code%10]--;
        } else {
            n_c[n%10]++;
        }
        n /= 10;
        code /= 10;
    }
    for(int i=0; i<10; i++){
        result.second += min(code_c[i], n_c[i]);
    }
    return result;
}

int main(){
    int n, strong, weak, rounds, count;
    cin >> rounds;
    
    vector<int> codes;
    
    while(rounds--){
        cin >> n >> strong >> weak;
        codes = vector<int>();
        generate_codes(0, 0, log10(n)+1, codes);
        count = 0;
        for(int i=0; i<codes.size(); i++){
            pair<int, int> result = compare(n,codes[i]);
            if(result.first == strong && result.second == weak) count++;    
        }
        cout << count << endl;
    }
    
    return 0;
}