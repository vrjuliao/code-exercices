#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int count;
    char c;
    cin >> s;

    unsigned int size = static_cast<int>(s.length());
    c = s[0];
    count = 1;
    for(int i=1; i<size; i++){
        if(s[i]!=c){
            cout << c << count;
            c=s[i];
            count=0;
        }
        count++;
    }
    cout << c << count << endl;
    
    return 0;
}