#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> atk, def, my;
int vis[101];
int A, D, M, best[2];

int main() {
	int n, m, i, j, v;
	cin>>n>>m;
	string s;
	for(i=0;i<n;i++) {
		cin>>s>>v;
		if(s=="ATK") atk.push_back(v);
		else def.push_back(v);
	}
	for(i=0;i<m;i++) {
		cin>>v;
		my.push_back(v);
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(my.begin(), my.end());
	A = atk.size();
	D = def.size();
	M = my.size();
	for(i=0;i<min(M, A);i++) {
		if(my[M-1-i] < atk[i]) break;
		best[0] += my[M-1-i] - atk[i];
	}
	for(i=0;i<D;i++) {
		for(j=0;j<M;j++) if(vis[j]==0 && my[j]>def[i]) {
			vis[j]=1;
			break;
		}
		if(j==M) break;
	}
	if(i==D) {
		for(i=0;i<A;i++) {
			for(j=0;j<M;j++) if(vis[j]==0 && my[j]>=atk[i]) {
				vis[j]=1;
				best[1] += my[j]-atk[i];
				break;
			}
			if(j==M) break;
		}
		if(i==A) {
			for(i=0;i<M;i++) if(!vis[i]) best[1] += my[i];
		}
	}
	cout << max(best[0], best[1]) << endl;
	return 0;
}
