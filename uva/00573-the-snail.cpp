#include <bits/stdc++.h>

using namespace std;

int main(){
	int H, U, D, F;
	cin >> H >> U >> D >> F;
	double climbed, cumulative_fatigator, u, d, h, f;
	int day;

	while(H!=0){
		u = static_cast<double>(U);
		d = static_cast<double>(D);
		h = static_cast<double>(H);
		f = static_cast<double>(F);
		cumulative_fatigator = u*f/100.0;
		climbed = 0.0;
		day=1;
		for(; true; day++){
			climbed += u;
			if(u>0.0) u-=cumulative_fatigator;
			if(climbed > h) break;
			climbed -= d;
			if(climbed<0.0) break;
		}
		if(climbed < 0.0){
			cout << "failure";
		} else {
			cout << "success";
		}
		cout << " on day " << day << endl;

		cin >> H >> U >> D >> F;
	}


	return 0;
}