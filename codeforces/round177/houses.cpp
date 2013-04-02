#include <cstdio>
#include <iostream>
#include <queue>
#define M 1000000007
using namespace std;
typedef long long ll;

int k, v[8], vis[8];
int sol[8] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};

int valid() {
	queue<int> q;
	int i, n;
	for(i=0;i<k;i++) vis[i]=0;
	for(i=0;i<k;i++) if(v[i] == 0) q.push(i);
	while(!q.empty()) {
		n = q.front();
		q.pop();
		if(vis[n]) continue;
		vis[n]=1;
		for(i=0;i<k;i++) if(v[i] == n) q.push(i);
	}
	for(i=0;i<k;i++) if(!vis[i]) break;
	return i==k;
}

int dfs(int p) {
	int i, ret=0;
	if(p==k) return valid();
	for(i=0;i<k;i++) {
		v[p] = i;
		ret = (ret + dfs(p+1)) % M;
	}
	return ret;
}

int exp(int n, int e) {
	if(e==0) return 1;
	if(e==1) return n;
	if(e%2==0) return exp((1ll*n*n)%M, e/2);
	return (1ll*n*exp(n, e-1))%M;
}

/*
int main() {
	cin>>k;
	cout<<dfs(0)<<endl;
	return 0;
}
*/

int main() {
	int i, n;
	cin>>n>>k;
	if(n==k) cout<<sol[k-1]<<endl;
	else cout << ((1ll * sol[k-1] * exp(n-k, n-k)) % M) << endl;
	return 0;
}
