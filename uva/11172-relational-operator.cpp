#include <iostream>

using namespace std;

int main(){
	int rounds, a, b;
	char c;

	cin >> rounds;
	while(rounds > 0){
		cin >> a >> b;
		c = a > b ? '>' : (a < b ? '<' : '=');
		cout << c << endl;
		rounds--;
	}
	return 0;
}