#include <bits/stdc++.h>

using namespace std;

int main (){
	int rounds, max_vel, cur_vel;
	string line;
	cin >> rounds;
	cin.ignore();
	for(int i=1; i<=rounds; i++){
		getline(cin, line);
		istringstream iss(line);
		max_vel = 0;
		while(iss >> cur_vel){
			if(max_vel < cur_vel) max_vel = cur_vel;
		}
		cout << "Case " << i << ": " << max_vel << endl;
	}
	return 0;
}
