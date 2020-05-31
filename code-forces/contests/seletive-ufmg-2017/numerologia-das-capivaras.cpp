#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, m, t;
    cin >> h >> m >> t;

    int hr, min;
    hr = (t/60)%24;
    min = t%60;

    h = (h+hr+((m+min)/60))%24;
    m = (m+min)%60;
    cout << h << ':' << m << endl;
    return 0;
}