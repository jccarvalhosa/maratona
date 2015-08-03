#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N=1e6+1;
int n, m, ans[N];
vector<int> child[N][2];
int qmin[N][2], qmax[N][2];
int tmax[N], tmin[N];

void setmax(int p, int v) {
	for(;p<=n;p+=p&-p) tmax[p] = max(tmax[p], v);
}
int getmax(int p) {
	int ans=0;
	for(;p;p-=p&-p) ans = max(tmax[p], ans);
	return ans;
}
void setmin(int p, int v) {
	p = n - p + 1;
	for(;p<=n;p+=p&-p) tmin[p] = min(tmin[p], v);
}
int getmin(int p) {
	p = n - p + 1;
	int ans=n+1;
	for(;p;p-=p&-p) ans = min(tmin[p], ans);
	return ans;
}

bool dfs(int p, int v, int q) {
	if(q == 0) return true;
	if(qmax[v][0] >= qmin[v][1]) return false;
	bool noleft = qmax[v][0] == 0;
	int qleft = noleft ? 0 : qmax[v][0]-v;
	ans[p+qleft]=v;
	return dfs(p, v+1, qleft) && dfs(p+qleft+1, v+qleft+1, q-qleft-1);
}

bool solve() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		qmin[i][0] = qmin[i][1] = n+1;
		qmax[i][0] = qmax[i][1] = 0;
		tmin[i] = n+1;
	}
	char c[10];
	while(m--) {
		int a, b;
		scanf("%d %d %s", &a, &b, c);
		if(c[0]=='L') child[a][0].push_back(b);
		if(c[0]=='R') child[a][1].push_back(b);
	}
	for(int v=n;v>=1;v--) {
		for(int i=0;i<2;i++) {
			for(int j=0;j<child[v][i].size();j++) {
				int u = child[v][i][j];
				if(u <= v) return 0;
				qmax[v][i] = max(qmax[v][i], u);
				qmin[v][i] = min(qmin[v][i], u);
			}
			qmax[v][i] = max(qmax[v][i], getmax(qmax[v][i]));
			qmin[v][i] = min(qmin[v][i], getmin(qmin[v][i]));
		}
		for(int i=0;i<2;i++) {
			setmin(v, qmin[v][i]);
			setmax(v, qmax[v][i]);
		}
	}
	return dfs(1, 1, n);
}

int main() {
	if(solve()) {
		for(int i=1;i<=n;i++) {
			if(i>1) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
