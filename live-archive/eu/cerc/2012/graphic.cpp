#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
int N, k, n, m;

int encode(string s) {
	stringstream ss(s.substr(2));
	int v;
	ss >> v;
	if(s[0] == 'B') v += n+k;
	if(s[1] == 'P') v += k;
	return v;
}

string decode(int v) {
	string s;
	if(v <= k) s = "AS";
	else if(v <= n+k) {
		s = "AP";
		v -= k;
	}
	else if(v<=n+2*k) {
		s = "BS";
		v -= n+k;
	}
	else {
		s = "BP";
		v -= n+2*k;
	}
	stringstream ss;
	ss<<s<<v;
	return ss.str();
}

void read(int n, vvi &v) {
	for(int i=0;i<n;i++) {
		string a, b;
		cin>>a>>b;
		int na = encode(a);
		int nb = encode(b);
		v[na].push_back(nb);
		v[nb].push_back(na);
	}
}

int par[5555], dep[5555];
pii line[5555];

int dfs(vvi &g, int v, int p) {
	if(p==-1) dep[v]=1;
	else dep[v]=dep[p]+2;
	par[v]=p;
	if(p!=-1 && g[v].size()==1) return v;
	int x[2], t=0;
	for(int i=0;i<g[v].size();i++) {
		int u = g[v][i];
		if(u==p) continue;
		int k = dfs(g, u, v);
		if(k==-1) return -1;
		if(k==0) continue;
		if(t==2) return -1;
		x[t++] = k;
	}
	if(t==0) return -1;
	if(t==1) return x[0];
	line[x[0]] = pii(x[1], v);
	line[x[1]] = pii(x[0], v);
	return 0;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>k>>n>>m;
		N = n+m+2*k;
		vvi g(N+2), wire(N+2);
		read(N-2, g);
		read(k, wire);
		vi ans;
		if(dfs(g, k+1, -1) == 0 && dfs(g, n+2*k+1, -1) == 0) {
			vi path;
			int old=1, x=wire[old][0];
			path.push_back(x);
			while(x!=1) {
				if(wire[x][0] != old) {
					path.push_back(wire[x][0]);
					old = x;
					x = wire[x][0];
				}
				else {
					int y = line[x].first;
					int p = line[x].second;
					for(int i=par[x];;i=par[i]) {
						path.push_back(i);
						if(i==p) break;
					}
					vi v;
					for(int i=y;i!=p;i=par[i]) v.push_back(i);
					reverse(v.begin(), v.end());
					path.insert(path.end(), v.begin(), v.end());
					old = x;
					x = y;
				}
			}
			if(path.size() == N) {
				cout<<"YES";
				for(int i=0;i<N;i++) cout << " " << decode(path[i]);
				cout<<endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}
