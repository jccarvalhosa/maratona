#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

map<string, int> id;
string vs[11111], op[10];
int adj[11111][11], valid[11111], p10[10];

void process() {
	int k;
	cin>>k;
	for(int i=0;i<k;i++) cin>>op[i];
	id.clear();
	id["ORIG"]=0;
	vs[0] = "ORIG";
	id[""]=1;
	vs[1] = "";
	valid[0]=valid[1]=1;
	int n=2;
	for(int i=0;i<k;i++) for(int j=0;j<op[i].size();j++) {
		string pre = op[i].substr(0, j+1);
		if(!id.count(pre)) {
			vs[n] = pre;
			int t;
			for(t=0;t<k;t++) if(pre.find(op[t]) != string::npos) break;
			if(t==k) valid[n] = 1;
			else valid[n] = 0;
			id[pre] = n++;
		}
	}
	for(int i=1;i<n;i++) for(int j=0;j<=9;j++) {
		char c = '0'+j;
		string s = vs[i] + c;
		int k;
		for(k=0;k<s.size();k++) if(id.count(s.substr(k))) break;
		if(k==s.size()) adj[i][j]=1;
		else adj[i][j] = id[s.substr(k)];
	}
	adj[0][0] = 0;
	for(int i=1;i<=9;i++) adj[0][i] = adj[1][i];
	p10[0]=1;
	for(int i=1;i<10;i++) p10[i] = 10*p10[i-1];
}

int tam(int n) {
	int ret=0;
	for(; n; n /= 10, ret++);
	return ret;
}

map<pp, int> vis;

int go(int p, int t, int n) {
	pp state(p, pii(t, n));
	if(!valid[p]) return 0;
	if(t==0) return 1;
	if(vis.count(state)) return vis[state];
	int d = n/p10[t-1];
	int ans=0;
	for(int i=0;i<d;i++) ans += go(adj[p][i], t-1,  p10[t-1]-1);
	ans += go(adj[p][d], t-1, n - d*p10[t-1]);
	return vis[state] = ans;
}

int search(int k) {
	int i=0, f=INT_MAX;
	while(i<f-1) {
		int m = (f-i)/2 + i;
		int v = go(0, tam(m), m);
		if(v < k) i=m;
		else f=m;
	}
	return f;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		process();
		vis.clear();
		int n, k;
		cin>>k>>n;
		cout<<search(n+1);
		for(int i=1;i<k;i++) {
			cin>>n;
			cout<<" "<<search(n+1);
		}
		cout<<endl;
	}
	return 0;
}
