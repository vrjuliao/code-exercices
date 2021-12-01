#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

bool get_king(vector<pair<bool, vector<int>>> &graph, int id){
	if(graph[id].f){
		cout << id << endl;
		return true;
	} else {
		for(auto it: graph[id].s) {
			if(get_king(graph, it)) return true;
		}
		return false;
	}
}

int main (void) {_
	int rounds, action, id;
	cin >> rounds;
	vector<pair<bool, vector<int>>> graph(1);
	int next = 1;
	graph.push_back(make_pair(true, vector<int>()));
	++next;
	while(rounds--){
		cin >> action >> id;
		if(action == 1){
			// add new son
			graph[id].s.push_back(next);
			graph.push_back(make_pair(true, vector<int>()));
			++next;
		} else {
			graph[id].f = false;
			get_king(graph, 1);
		}
	}
	
	return 0;
}
