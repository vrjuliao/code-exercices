#include <bits/stdc++.h>
using namespace std;

int main(){
	int months, rounds;
	int round_index, next_round_index, month_count;
	float part, total, loan, next_loan, loan_total;
	bool total_gt_loan;

	cin >> months >> part >> total >> rounds;
	while (months >= 0){
		cin >> round_index >> loan;
		loan_total = total * (1.0 - loan);
		round_index++;
		month_count=0;

		while (rounds >= 2){
			// cout << "here" << endl;
			cin >> next_round_index >> next_loan;
			for(;round_index<next_round_index && total > loan_total; round_index++){
				month_count++;
				total -= part;
				loan_total *= (1.0 - loan);
			cout << "Total: " << total << endl;
			cout << "Total loan: " << loan_total << endl;
			}
			if(total < loan_total){
			cout << "here" << endl;
				cout << "print ";
				cout << month_count-1 << " month";
				if(month_count > 1) cout << 's';
				cout << endl;
				break;
			}
			round_index = next_round_index;
			loan = next_loan;
			rounds--;
		}
		if(total > loan_total){
			while(month_count < months || total > loan_total){
				month_count++;
				total -= part;
				loan_total *= (1.0 - loan);
				cout << "--Total: " << total << endl;
				cout << "--Total loan: " << loan_total << endl;
			}
			cout << month_count-1 << " month";
			if(month_count > 1) cout << 's';
			cout << endl;
		}
		cin >> months >> part >> total >> rounds;
	}
	return 0;
}