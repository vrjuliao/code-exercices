#include <bits/stdc++.h>

using namespace std;

int main(){
	int rounds;
	int l, w, h;
	cin >> rounds;
	for(int i=1; i <= rounds; i++){
		cin >> l >> w >> h;
		cout << "Case " << i << ": ";
		if(l > 20 || w > 20 || h > 20) cout << "bad" << endl;
		else cout << "good" << endl;
	}

	return 0;
}