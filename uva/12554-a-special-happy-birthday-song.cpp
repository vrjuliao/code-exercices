#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<string> song = {
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you"
	};

	vector<string> names = vector<string>(110);
	int qtt_names;
	cin >> qtt_names;
	for(int i=0; i<qtt_names; i++){
		cin >> names[i];
	}

	if(qtt_names <= 16){
		for(int i=0; i<16; i++){
			cout << names[i%qtt_names] << ": " << song[i] << endl;
		}
	} else {
		for(int i=0; i<qtt_names || (i%16 != 0); i++){
			cout << names[i%qtt_names] << ": " << song[i%16] << endl;
		}
	}
	return 0;
}