#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin >> s;
	for(int i=1; s != "*"; i++){
		cout << "Case "<< i << ": Hajj-e-";
		if(s=="Hajj"){
			cout << "Akbar";
		} else if(s=="Umrah"){
			cout << "Asghar";
		}
		cout << endl;
		cin >> s;
	}
	return 0;
}