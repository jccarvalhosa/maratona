#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define INF 1ll<<60
using namespace std;
typedef long long ll;

map<string, int> id;
	
int m, n=1, v[22];
ll adj[22][22], dp[1<<22];

int add(string s) {
	id[s]=n;
	return n++;
}

int main() {
	id["Park"] = 0;
	for(int i=0;i<22;i++) for(int j=0;j<22;j++) adj[i][j] = INF;
	cin>>m;
	for(int i=0;i<m;i++) {
		string sa, sb;
		int a, b;
		ll d;
		cin>>sa>>sb>>d;
		if(!id.count(sa)) a = add(sa);
		else a = id[sa];
		if(!id.count(sb)) b = add(sb);
		else b = id[sb];
		adj[a][b] = adj[b][a] = min(d, adj[a][b]);
	}
	for(int k=1;k<=n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	n--;
	int cap;
	cin>>cap;
	for(int i=1;i<1<<n;i++) {
		dp[i] = INF;
		int t=0;
		for(int j=0;j<n;j++) if(i & (1<<j)) v[t++] = j;
		for(int j=0;j<t;j++) for(int k=0;k<t;k++) if(k != j) dp[i] = min(dp[i], adj[v[j]+1][v[k]+1] + dp[i - (1<<v[j])]);
		if(t > cap) continue;
		ll sum=0;
		for(int j=0;j<t;j++) {
			sum += adj[v[j]+1][0];
			if(sum > dp[i]) break;
		}
		dp[i] = min(dp[i], sum);
	}
	cout<<"Total miles driven: "<<dp[(1<<n) - 1]<<endl;
	return 0;
}
