#include <bits/stdc++.h>

using namespace std;

int main(){
	int cur_channel, wshd_channel;
	int up_click, down_click;
	cin >> cur_channel >> wshd_channel;
	while(cur_channel >= 0){
		if(cur_channel > wshd_channel){
			up_click = 100-cur_channel+wshd_channel;
			down_click = cur_channel-wshd_channel;
		} else {
			up_click = 100-wshd_channel+cur_channel;
			down_click = wshd_channel-cur_channel;
		}
		if(up_click > down_click)
			cout << down_click;
		else
			cout << up_click;

		cout << endl;
		cin >> cur_channel >> wshd_channel;
	}

	return 0;
}