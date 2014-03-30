#include <bits/stdc++.h>

using namespace std;

int test[55], vis[55], val[55];
string typ[55];
vector <int> adj[55], adjt[55], ord;
map <pair<int,int>, int > bugs;
int n, u, g;

int input(int i) { return i; }
int gate(int i) { return n+i; }
int output(int i) { return n+g+i; }

void solve(int el, int def) {
	for(int i=0;i<ord.size();i++) {
		int v = ord[i];
		if(v <= n) continue;
		if(v >= output(1)) {
			val[v] = val[adjt[v][0]];
		}
		else {
			if(typ[v] == "n") {
				val[v] = 1 - val[adjt[v][0]];
			}
			if(typ[v] == "a") {
				val[v] = val[adjt[v][0]] & val[adjt[v][1]];
			}
			if(typ[v] == "o") {
				val[v] = val[adjt[v][0]] | val[adjt[v][1]];
			}
			if(typ[v] == "x") {
				val[v] = val[adjt[v][0]] ^ val[adjt[v][1]];
			}
		}
		if(v == el) {
			if(def == 0) {
				val[v] = 0;
			}
			if(def == 1) {
				val[v] = 1;
			}
			if(def == 2) {
				val[v] = 1 - val[v];
			}
		}
	}
}


void dfs(int u)
{
	int i, v;
	vis[u]=1;
	for(i=0; i<adj[u].size(); i++)
	{
		v=adj[u][i];
		if(!vis[v]) dfs(v);
	}
	ord.push_back(u);
}

int main() {
	int T=1;
	while(scanf("%d%d%d", &n,&g,&u) && n) {
		for(int i=0;i<55;i++) {
			adj[i].clear();
			adjt[i].clear();
		}
		bugs.clear();
		ord.clear();
		for(int i=1;i<=g;i++) {
			string a, b, c;
			cin >> c;
			typ[gate(i)] = c;
			if(c == "n") {
				cin >> a;
				if(a[0] == 'i') adj[input(a[1]-'0')].push_back(gate(i)); 
				else {
					if(a.size() == 2) adj[gate(a[1]-'0')].push_back(gate(i));
					else adj[gate((a[1]-'0')*10+a[2]-'0')].push_back(gate(i));
				}
			}
			else {
				cin >> a >> b;
				if(a[0] == 'i') adj[input(a[1]-'0')].push_back(gate(i)); 
				else {
					if(a.size() == 2) adj[gate(a[1]-'0')].push_back(gate(i));
					else adj[gate((a[1]-'0')*10+a[2]-'0')].push_back(gate(i));
				}
				if(b[0] == 'i') adj[input(b[1]-'0')].push_back(gate(i)); 
				else {
					if(b.size() == 2) adj[gate(b[1]-'0')].push_back(gate(i));
					else adj[gate((b[1]-'0')*10+b[2]-'0')].push_back(gate(i));
				}
			}
		}
		for(int i=1;i<=u;i++) {
			int out;
			cin >> out;
			adj[gate(out)].push_back(output(i));
		}
		for(int i=1;i<=n+g+u;i++) {
			for(int j=0;j<adj[i].size();j++) {
				adjt[adj[i][j]].push_back(i);
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n+g+u;i++) if(!vis[i]) dfs(i);
		reverse(ord.begin(),ord.end());
		int t;
		cin >> t;
		int aux=t;
		while(aux--) {
			for(int j=1;j<=u+n;j++) cin >> test[j]; 
			for(int j=1;j<=n;j++) val[j] = test[j];
			solve(-1, -1);
			int good=1;
			for(int i=1;i<=u;i++) if(val[output(i)] != test[i+n]) good=0;
			if(good) bugs[make_pair(-1, -1)]++;
			for(int i=1;i<=g;i++) for(int def=0;def<3;def++) {
				solve(gate(i), def);
				int good=1;
				for(int j=1;j<=u;j++) if(val[output(j)] != test[j+n]) good=0;
				if(good) bugs[make_pair(i, def)]++;
			}
		}
		int qnt=0;
		int pos, err;
		printf("Case %d: ", T++);
		for(map<pair<int, int>, int >::iterator it = bugs.begin(); it != bugs.end(); it++) {
			if(it->second == t) {
				qnt++;
				pos = it->first.first;
				err = it->first.second;
			}
		}
		if(bugs[make_pair(-1, -1)] == t) {
			qnt=1;
			pos=-1;
		}
		if(qnt != 1) printf("Unable to totally classify the failure\n");
		else if(pos==-1) printf("No faults detected\n");
		else {
			printf("Gate %d is failing; output ", pos);
			if(err==0) printf("stuck at 0\n");
			else if(err==1) printf("stuck at 1\n");
			else printf("inverted\n");
		}
	}
	return 0;
}
