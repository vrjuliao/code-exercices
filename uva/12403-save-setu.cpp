#include <bits/stdc++.h>

using namespace std;

int main(){
	int rounds, money, in;
	string s;

	cin >> rounds;
	money = 0;
	while(rounds > 0){
		cin >> s;
		if(s == "donate"){
			cin >> in;
			money+=in;
		} else if(s == "report"){
			cout << money << endl;
		}
		rounds--;
	}

	return 0;

}