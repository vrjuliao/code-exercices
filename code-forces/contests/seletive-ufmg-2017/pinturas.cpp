#include <bits/stdc++.h>

using namespace std;

struct node {
    bool visited;
    vector<int> next;
};

void add_edge(node &from, int to){
    from.next.push_back(to);
}

bool visit(vector<node> &graph, int node){
    if(graph[node].visited) return false;
    for(int j=0; j<graph[node].next.size(); j++){
        if(visit(graph, graph[node].next[j])) return true;
    }
    return false;
}

bool has_cycle(vector<node> &graph){
    unsigned int size = static_cast<unsigned int>(graph.size());
    for(int i=0; i<size; i++){
        if(!graph[i].visited){
            for(int j=0; j<graph[i].next.size(); j++){
                if(visit(graph, graph[i].next[j])) return true;
            }
        }
    }
    return false;
}

int main(){
    int n,k;
    int a1, a2, a3;
    cin >> n >> k;
    vector<node> graph = vector<node>(n);
    for(int i=0; i<n; i++){
        graph[i] = node();
        graph[i].visited = false;
        graph[i].next = vector<int>();
    }

    while(k--){
        cin >> a1 >> a2 >> a3;
        add_edge(graph[a1-1], a2-1);
        add_edge(graph[a2-1], a3-1);
    }
    if(has_cycle(graph)) cout << "nao" << endl;
    else cout << "sim" << endl;

    return 0;
}