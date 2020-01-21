#include <iostream>

using namespace std;

int main(){
	int i;
	float f=0.0;
	cin >> i;

	while(i){
		f += 1.0/i;
		i--;
	}
	cout << f;
	return 0;
}