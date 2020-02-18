#include <iostream>
#include <string>

using namespace std;

int main(){
	char c;
	bool open_quote = false;
	string s = "";

	while(cin >> noskipws >> c){
		if(c=='"'){
			if(open_quote){
				cout << "``" << s << "''";
				s = "";
				open_quote = false;
			} else {
				open_quote = true;
			}
		} else {
			if(open_quote){
				s+=c;
			} else {
				cout << c;
			}
		}
	}
	if(!s.empty()) cout << '"' << s;
	return 0;
}