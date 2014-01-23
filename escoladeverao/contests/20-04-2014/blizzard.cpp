#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pp;

const int MAXN=3e5+10;
int n, N;
pii v[MAXN], A[5*MAXN], p[MAXN];
vector<int> adj[MAXN];

pii query(int n, int b, int e, int i, int j) {
	if(j < b || i>e) return pii(1e9, 1e9);
	if(b >= i && e <= j) return A[n];
	int m = (b+e)/2;
	return min(query(2*n, b, m, i, j), query(2*n+1, m+1, e, i, j));
}

void init(int n, int b, int e) {
	if(b==e) A[n] = pii(v[b].second - v[b].first, b);
	else {
		int m = (b+e)/2;
		init(2*n, b, m);
		init(2*n+1, m+1, e);
		A[n] = min(A[2*n], A[2*n+1]);
	}
}

int build(int i, int f, int l, int r) {
	int x = N;
	N++;
	p[x] = query(1, 1, n, i, f);
	int di = min(v[i].second, r) - max(v[i].first, l);
	int df = min(v[f].second, r) - max(v[f].first, l);
	p[x].first = min(v[p[x].second].second, r) - max(v[p[x].second].first, l);
	if(p[x].first > df) {
		p[x].first = df;
		p[x].second = f;
	}
	if(p[x].first >= di) {
		p[x].first = di;
		p[x].second = i;
	}
	if(p[x].second != f) adj[x].push_back(build(p[x].second+1, f, v[p[x].second].second, r));
	if(p[x].second != i) adj[x].push_back(build(i, p[x].second-1, l, v[p[x].second].first));
	return x;
}

int main() {
	int r;
	cin>>r>>n;
	for(int i=1;i<=n;i++) cin>>v[i].first>>v[i].second;
	init(1, 1, n);
	int root = build(1, n, 1, r);
	set<pp> s;
	s.insert(pp(p[root], root));
	while(!s.empty()) {
		cout << (*s.begin()).first.second << endl;
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for(int i=0;i<adj[v].size();i++) {
			int u = adj[v][i];
			s.insert(pp(p[u], u));
		}
	}
	return 0;
}
