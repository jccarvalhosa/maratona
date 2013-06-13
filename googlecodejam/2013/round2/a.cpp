#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MOD 1000002013ull
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int N, M;
pii ent[1000], sai[1000];

ull pasum(int i, int f) {
	if(i==f) return 0;
	return (1ull*(2*N-f+i-1)*(f-i)/2) % MOD;
}

int main() {
	ull sol, val;
	int T, i, j, o, e, p, t;
	cin>>T;
	for(t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		cin>>N>>M;
		val=0;
		for(i=0;i<M;i++) {
			cin>>o>>e>>p; o--; e--;
			val = (val + 1ull * p * pasum(o, e)) % MOD;
			ent[i] = pii(o, p);
			sai[i] = pii(e, p);
		}
		sort(ent, ent+M);
		sort(sai, sai+M);
		sol=0;
		for(i=0;i<M;i++) {
			for(j=M-1;j>=0;j--) {
				if(sai[i].first < ent[j].first) continue;
				if(ent[j].second == 0) continue;
				if(sai[i].second > ent[j].second) {
					sol = (sol + ent[j].second * pasum(ent[j].first, sai[i].first)) % MOD;
					sai[i].second -= ent[j].second;
					ent[j].second = 0;
				}
				else {
					sol = (sol + sai[i].second * pasum(ent[j].first, sai[i].first)) % MOD;
					ent[j].second -= sai[i].second;
					sai[i].second = 0;
					break;
				}
			}
		}
		cout << (val - sol + MOD) % MOD << endl;
	}
	return 0;
}
