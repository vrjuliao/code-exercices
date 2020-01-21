/*
URI- 2665
Hipercampo
*/

#include<iostream>
using namespace std;

struct ponto
{
	int x;
	int y;
	int count;
	float aA;
	float aB;
	bool visited;
};

int isPontoDentoAB(ponto p, int A, int B){
	return p.x > A && p.x < B;
}

int max(int i, int j){
	return i < j ? j : i;
}

int matrix[100][100];
int n;
ponto pontos[100];
int dp[110];

int solve(int k) {
	if (dp[k] != -1) return dp[k];
	// if (dp[k] != 0) return dp[k];

	pontos[k].visited = true;
	dp[k] = 0;
	for (int i = 0; i < n; i++) {
		if (matrix[k][i] == 1 && i!=k){
            int solved = solve(i);
            dp[k] = max(dp[k], solved);
        }
	}
	dp[k]++;
		//dp[k] = max(dp[k], solve(i));
	return dp[k];
	// return dp[k]+1;
}

int main(){

	int A, B, N;

	cin >> N >> A >> B;

	ponto pA, pB;
	pA.x = A;
	pA.y = 0;
	pB.x = B;
	pA.y = 0;

	n = N;
	for(int i=0; i<N; i++){
		ponto p;
		cin >> p.x >> p.y;
		p.aA = static_cast<float>(pA.y - p.y)/(pA.x - p.x);
		p.aB = static_cast<float>(pB.y - p.y)/(pB.x - p.x);
		p.visited = false;
		matrix[i][i] = 1;
		pontos[i] = p;
	}

	for(int i=0; i<N; i++){
		ponto pi = pontos[i];
		bool dentroAB = isPontoDentoAB(pi, A, B);
		for(int j=0; j<N; j++){
			ponto pj = pontos[j];

			if(pj.y<pi.y){

				if(dentroAB){
					if(pj.aA <= pi.aA && pj.aB >= pi.aB){
						pi.count += 1;
						matrix[i][j] = 1;
					}
				}else{
					float pV = static_cast<float>(pi.y - pj.y)/(pi.x - pj.x);
					if(pi.aA < pV && pi.aB > pV){
						pi.count += 1;
						matrix[i][j] = 1;
					}
				}
			}
		}

	}

    // for(int i=0; i<N; i++){
    //     for(int j = 0; j<N; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

	for(int i; i < 110; i++){
        dp[i] = -1;
    }

	int max_num = 0;
    int index_max = -1;
	for(int i = 0; i < N; i++){
		if(!pontos[i].visited){
			int current_max = solve(i);
			// max_num = max(max_num, current_max);
			max_num = max(max_num, current_max);
            // cout << "Current point: " << pontos[i].x << " " << pontos[i].y << endl;
		}
	}
	cout << max_num << endl;

	return 0;
}