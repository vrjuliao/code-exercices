#include <bits/stdc++.h>
using namespace std;

int main(){

	int participants, budget, hotels, weeks;
	int max_weeks = 14;
	int hotel_price;
	int cur_hotel_price;
	int beds;
	bool has_beds;
	int cost;

	while(cin >> participants >> budget
			>> hotels >> weeks){
		hotel_price = 10001;
		for(int i=0; i<hotels; i++){
			cin>>cur_hotel_price;
			has_beds = false;
			for(int j=0; j<weeks; j++){
				cin >> beds;
				has_beds = has_beds || (beds >= participants) ;
			}
			if(cur_hotel_price < hotel_price && has_beds){
				hotel_price = cur_hotel_price;
			}
		}
		cost = participants * hotel_price;
		if(cost > budget)
			cout << "stay home";
		else
			cout << cost;
		cout << endl;
	}

	return 0;
}