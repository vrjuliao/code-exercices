#include <bits/stdc++.h>

using namespace std;


int main(){
	int rounds;
	
	cin >> rounds;
	vector<int> employees = vector<int>(3);

	for(int i=1; i <= rounds; i++){
		cin >> employees[0] >> employees[1] >> employees[2];
		
		sort(employees.begin(), employees.end());
		cout << "Case "<< i << ": " << employees[1] << endl;
	}

	return 0;
}