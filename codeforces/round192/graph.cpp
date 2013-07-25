#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <set>
using namespace std;
typedef pair<int, int> pii;

vector<int> adj[111111];
int v[111111], good[111111];

int main() {
	int n, m, i, j, test;
	cin>>n>>m;
	for(i=0;i<m;i++) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(i=0;i<n;i++) v[i]=i+1;
	for(test=0;test<100;test++) {
		random_shuffle(v, v+n);
		int t=0;
		for(i=0;i<n;i++) {
			good[i]=1;
			for(int j=0;j<adj[v[i]].size();j++) if(adj[v[i]][j] == v[(i+1)%n]) good[i]=0;
			if(good[i]) t++;
			if(t==m) break;
		}
		if(t==m) break;
	}
	if(test==100) {
		cout<<-1<<endl;
	} else {
		int t=0;
		for(i=0;i<n;i++) if(good[i]) {
			t++;
			cout<<v[i]<<" "<<v[(i+1)%n]<<endl;
			if(t==m) break;
		}
	}
	return 0;
}
