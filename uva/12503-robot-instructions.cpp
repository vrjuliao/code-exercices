#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v = vector<int>(110);
	int rounds, movements, total, same;
	string s;

	cin >> rounds;
	for(;rounds>0; rounds--){
		cin >> movements;
		total=0;
		for(int i=1;i <= movements; i++){
			cin >> s;
			if(s=="RIGHT"){
				v[i] = 1;
				total++;
			} else if (s=="LEFT"){
				v[i] = -1;
				total--;
			} else {
				cin >> s >> same;
				v[i] = v[same];
				total+= v[same];
			}
		}
		cout << total << endl;
	}

	return 0;
}