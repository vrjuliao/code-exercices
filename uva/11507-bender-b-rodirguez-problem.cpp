#include <bits/stdc++.h>

using namespace std;

int main(){
    string s[] = {"+x", "+y", "+z", "-x", "-y", "-z"};
    int rounds;
    int position;
    string bend;
    cin>>rounds;
    while(rounds>0){
        position = 0;
        while(--rounds){
            cin >> bend;
            if(bend == "+y"){
                switch(position){
                    case 0:
                        position = 1;
                        break;
                    case 1:
                        position = 3;
                        break;
                    case 3: 
                        position = 4;
                    break;
                    case 4: 
                        position = 0;
                    break;
                }
            } else if(bend == "-y"){
                switch(position){
                    case 0:
                        position = 4;
                        break;
                    case 1:
                        position = 0;
                        break;
                    case 3: 
                        position = 1;
                    break;
                    case 4: 
                        position = 3;
                    break;
                }
            } else if(bend == "+z"){
                switch(position){
                    case 0:
                        position = 2;
                        break;
                    case 2:
                        position = 3;
                        break;
                    case 3: 
                        position = 5;
                    break;
                    case 5: 
                        position = 0;
                    break;
                }
            } else if(bend == "-z"){
                switch(position){
                    case 0:
                        position = 5;
                        break;
                    case 2:
                        position = 0;
                        break;
                    case 3: 
                        position = 2;
                    break;
                    case 5: 
                        position = 3;
                    break;
                }
            }
        }
        cout << s[position] << endl;
        cin >> rounds;
    }
    
    return 0;
}