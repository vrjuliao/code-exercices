#include <bits/stdc++.h>

using namespace std;

int main(){
	int rounds;
	int positive, zero, in;
	cin >> rounds;
	for(int case_number =1; rounds > 0; case_number++){
		positive = 0; 
		zero = 0;
		for(int i=0; i < rounds; i++){
			cin >> in;
			if(in > 0) positive++;
			else zero++;
		}
		cout << "Case " << case_number << ": ";
		cout << positive-zero << endl;
		cin >> rounds;
	}

	return 0;
}