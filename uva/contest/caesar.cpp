#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int F[100000];
void build_failure_function(const string & pattern) {
	int i, n = pattern.size(); 
	F[0] = -1; 
	for(i=0;i<n;i++) {
		F[i+1] = F[i] + 1;
		while(F[i+1] > 0 && pattern[i] != pattern[F[i+1]-1]) F[i+1] = F[F[i+1]-1] + 1;
	}
}

// retorna a posicao inicial de cada ocorrencia de pattern em text
vector<int> KMP(const string & text, const string & pattern) {
	build_failure_function(pattern); 
	vector<int> start_positions;
	int i, j=0, m=pattern.size(), n=text.size(); 
	for(i=0;i<n;i++) while(1) {
		if(text[i] == pattern[j]) {
			if(++j == m) { 
				int pos = i-m+1;
				start_positions.push_back(pos); 
				j = F[j]; 
			} 
			break;
		}
		if(j == 0) break; 
		j = F[j];
	}
	return start_positions;
}

int pos[256];

int main() {
	string A, W, S;
	vector<int> solutions, occur;
	int T, n, m, i, j;
	scanf("%d", &T);
	while(T--) {
		cin >> A;
		cin >> W;
		cin >> S;
		n = A.size();
		m = S.size();
		for(i=0;i<n;i++) pos[A[i]] = i;
		solutions.clear();
		for(i=0;i<n;i++) {
			occur = KMP(S, W);
			if(occur.size() == 1) solutions.push_back((n-i)%n);
			for(j=0;j<m;j++) S[j] = A[(pos[S[j]]+1)%n];
		}
		sort(solutions.begin(), solutions.end());
		if(solutions.empty()) printf("no solution\n");
		else if(solutions.size() == 1) printf("unique: %d\n", solutions[0]);
		else {
			printf("ambiguous:");
			for(i=0;i<solutions.size();i++) printf(" %d", solutions[i]);
			printf("\n");
		}
	}
	return 0;
}
