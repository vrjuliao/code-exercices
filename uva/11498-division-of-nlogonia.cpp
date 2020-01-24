#include <iostream>
#include <string>

using namespace std;

int main(){
	int queries, rounds, n, m, x, y;
	char horizontal, vertical;

	cin >> queries;
	while(queries > 0){
		cin >> n >> m;
		while(queries > 0){
			cin >> x >> y;
			if(y > m){
				horizontal = 'N';
			} else if(y < m){
				horizontal = 'S';
			} else {
				cout << "divisa" << endl;
				queries--;
				continue;
			}

			if(x > n){
				vertical = 'E';
			} else if(x < n){
				vertical = 'O';
			} else {
				cout << "divisa" << endl;
				queries--;
				continue;
			}
			cout << horizontal << vertical << endl;
			queries--;
		}
		cin >> queries;
	}
	return 0;
}