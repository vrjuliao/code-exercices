#include <bits/stdc++.h> 

using namespace std;

int main(){
    int height, length;
    int count, laser_crr, laser_bfr;

    cin >> height >> length;
    while(height || length){
        count = 0;
        laser_bfr = height;
        while(length--){
            cin >> laser_crr;
            if(laser_crr < laser_bfr){
                count+= laser_bfr - laser_crr;
            }
            laser_bfr = laser_crr;
        }
        cout << count << endl;
        cin >> height >> length;
    }

    return 0;
}