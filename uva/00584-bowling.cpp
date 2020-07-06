#include <bits/stdc++.h>

using namespace std;

void make_points(string line, vector<int> &points){
    for(int i=0; i<=(line.size()/2); i++){
        switch (line[i+i]){
            case 'X': points[i] = 10;
                break;
            case '/': points[i] = 10-points[i-1];
                break;
            default: points[i] = line[i+i] - '0';
                break; 
        }
    }
}


int main(){
    string line;
    int frame, roll, points;
    vector<int> vpoints = vector<int>(25);
    getline(cin, line);
    while(line[0] != 'G'){
        make_points(line, vpoints);
        roll = 0;
        points = 0;
        for(frame = 0; frame < 10; frame++){
            points+=vpoints[roll];
            if(line[roll+roll] == 'X'){
                points+=vpoints[roll+1];
                points+=vpoints[roll+2];
            } else {
                roll++;
                points+=vpoints[roll];
                if(line[roll+roll] == '/'){
                    points+=vpoints[roll+1];
                }
            }
            roll++;
        }
        cout << points << endl;
        getline(cin, line);
    }
    return 0;
}