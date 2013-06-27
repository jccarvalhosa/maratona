#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define M 1000000007
#define INF 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;

int k;
ll c[100][100];
map<pii, int> vis;
map<piii, int> val;

ll prod(ll a, ll b) { return (a*b)%M; }

int dfs(int a, int b, int ma, int mb, int t) {
	int i, j, ret=INF;
	if(t==-1) {
		if(ma) ret = min(ret, 1+dfs(a+1, b, ma-1, mb, 1));
		if(mb) ret = min(ret, 1+dfs(a, b+1, ma, mb-1, 1));
		return ret;
	}
	pii obj = pii(a, b);
	if(vis.count(obj)) return vis[obj];
	vis[obj]=INF;
	if((50*a+100*b) <=k) return vis[obj]=1;
	else {
		for(i=0;i<=a;i++) for(j=0;j<=b;j++) if((i+j) && (50*i+100*j <= k)) {
			ret = min(ret, 1+dfs(a-i, b-j, ma+i, mb+j, -1));
		}
	}
	return vis[obj]=ret;
}

int cont(int a, int b, int ma, int mb, int t, int n) {
	int i, j, ret=0;
	if(n==0) return 0;
	if(t==-1) {
		for(i=0;i<=ma;i++) for(j=0;j<=mb;j++) if((i+j) && (50*i+100*j <= k)) {
			ret = (ret + prod(prod(c[i][ma], c[j][mb]), cont(a+i, b+j, ma-i, mb-j, 1, n-1)))%M;
		}
		return ret;
	}
	piii obj = piii(pii(a, b), n);
	if(50*a+100*b <= k) return 1;
	else {
		if(val.count(obj)) return val[obj];
		for(i=0;i<=a;i++) for(j=0;j<=b;j++) if((i+j) && (50*i+100*j <= k)) {
			ret = (ret + prod(prod(c[i][a], c[j][b]), cont(a-i, b-j, ma+i, mb+j, -1, n-1)))%M;
		}
		return val[obj]=ret;
	}
}

int main() {
	int n, a, b, i, p;
	cin>>n>>k;
	for(b=0;b<=n;b++) {
		c[0][b]=1;
		for(a=1;a<=b;a++) c[a][b] = (c[a][b-1] + c[a-1][b-1])%M;
	}
	a=b=0;
	for(i=0;i<n;i++) {
		cin>>p;
		if(p==50) a++;
		if(p==100) b++;
	}
	n = dfs(a, b, 0, 0, 1);
	if(n==INF) cout<<-1<<endl<<0<<endl;
	else {
		cout << n << endl;
		cout<<cont(a, b, 0, 0, 1, n)<<endl;
	}
	return 0;
}
