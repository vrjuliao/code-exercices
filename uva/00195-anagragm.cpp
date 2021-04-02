// start 2020/09/10 11:42pm
// end 2020/09/11 00:20am
#include <bits/stdc++.h>

using namespace std;

bool compare(const char &a, const char &b){
    // return a<b
    if(toupper(a) == toupper(b)){
        return a < b;
    } else {
        return tolower(a) < tolower(b);
    }

}
int main(){
    int rounds;
    string input;

    cin >> rounds;

    while(rounds--){
        cin >> input;
        sort(input.begin(), input.end(), compare);

        do {
            cout << input << endl;
        } while(next_permutation(input.begin(), input.end(), compare));

    }
    
    return 0;
}