#include <bits/stdc++.h>

using namespace std;

int main() {
	int rounds, calls, seconds;
	int mile, juice;
	cin >> rounds;
	for(int i=1; i<=rounds; i++){
		cin >> calls;
		mile =0;
		juice = 0;
		for(int j=0; j<calls; j++){
			cin >> seconds;
			mile += ((seconds/30)+1)*10;
			juice += ((seconds/60)+1)*15;
		}
		cout << "Case " << i << ": ";
		if(mile < juice){
			cout << "Mile " << mile << endl;
		} else if(mile > juice){
			cout << "Juice " << juice << endl;
		} else {
			cout << "Mile Juice " << juice << endl;
		}
	}
	return 0;
}