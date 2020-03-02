#include <bits/stdc++.h>
using namespace std;

int main(){
	int months, rounds;
	int round_index, next_round_index, month_count;
	float part, total, loan, next_loan, loan_total;
	float montly_payment;
	bool printed;

	cin >> months >> part >> total >> rounds;
	while (months >= 0){
		montly_payment = total / months;
		cin >> round_index >> loan;
		loan_total = (total+part) * (1.0 - loan);
		round_index++;
		month_count=0;
		printed = false;

		while (rounds >= 2){
			cin >> next_round_index >> next_loan;
			for(;round_index<next_round_index && total > loan_total; round_index++){
				month_count++;
				total -= montly_payment;
				loan_total *= (1.0 - loan);
			}
			if(total < loan_total){
				cout << month_count << " month";
				if(month_count != 1) cout << 's';
				cout << endl;
				printed = true;
				break;
			}
			round_index = next_round_index;
			loan = next_loan;
			rounds--;
		}
		if(total > loan_total || !printed){
			while(month_count < months && total > loan_total){
				month_count++;
				total -= montly_payment;
				loan_total *= (1.0 - loan);
			}
			cout << month_count << " month";
			if(month_count != 1)
				cout << 's';
			cout << endl;
		}
		cin >> months >> part >> total >> rounds;
	}
	return 0;
}