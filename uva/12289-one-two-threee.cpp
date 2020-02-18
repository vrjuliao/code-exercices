#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int rounds;

	cin >> rounds;
	string one = "one";
	string two = "two";
	string three = "three";
	for( ;rounds>0; rounds--){
		cin >> s;

		if(s.size()==3){
			//verify one
			if((s[0]==one[0] && s[1]==one[1])
			|| (s[1]==one[1] && s[2]==one[2])
			|| (s[0]==one[0] && s[2]==one[2])){
				cout << 1 << endl;
				continue;
			} else if((s[0]==two[0] && s[1]==two[1])
			|| (s[1]==two[1] && s[2]==two[2])
			|| (s[0]==two[0] && s[2]==two[2])){
				cout << 2 << endl;
				continue;
			}
		} else if(s.size()==5){
			if((s[0]==three[0] && s[1]==three[1] && s[2]==three[2] && s[3]==three[3])
			|| (s[0]==three[0] && s[1]==three[1] && s[2]==three[2] && s[4]==three[4])
			|| (s[0]==three[0] && s[1]==three[1] && s[3]==three[3] && s[4]==three[4])
			|| (s[0]==three[0] && s[2]==three[2] && s[3]==three[3] && s[4]==three[4])
			|| (s[1]==three[1] && s[2]==three[2] && s[3]==three[3] && s[4]==three[4])){
				cout << 3 << endl;
				continue;	
			}

		}
	}
	return 0;
}