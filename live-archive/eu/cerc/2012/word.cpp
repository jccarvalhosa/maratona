#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

map<string, int> id;
vector<int> adj[1111];
string v[1111];
int n, vis[1111];
int dp[1111][2222];
string dest;

void dfs(int x) {
	vis[x]=1;
	if(adj[x].size() == 0) {
		for(int pos=0;pos<dest.size();pos++) {
			int j=pos;
			for(int i=0;i<v[x].size();i++) {
				if(j != dest.size() && v[x][i] == dest[j]) j++;
			}
			dp[x][pos] = j;
		}
		return;
	}
	int l = adj[x][0];
	int r = adj[x][1];
	if(!vis[l]) dfs(l);
	if(!vis[r]) dfs(r);
	for(int pos=0;pos<dest.size();pos++) {
		int j=pos;
		j = dp[l][j];
		if(j != dest.size()) j = dp[r][j];
		dp[x][pos] = j;
	}
}

int get_id(string s) {
	if(id.count(s)) return id[s];
	else {
		adj[n].clear();
		id[s] = n;
		vis[n] = 0;
		return n++;
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		id.clear();
		n=0;
		int m;
		cin>>m;
		getchar();
		for(int i=0;i<m;i++) {
			string s;
			getline(cin, s);
			int p = s.find("=");
			string a = s.substr(0, p-1);
			int na = get_id(a);
			s = s.substr(p+2);
			if(s.find("+") != string::npos) {
				p = s.find("+");
				string b = s.substr(0, p-1);
				string c = s.substr(p+2);
				int nb = get_id(b);
				int nc = get_id(c);
				adj[na].push_back(nb);
				adj[na].push_back(nc);
			}
			else v[na] = s;
		}
		string orig;
		cin>>orig>>dest;
		dfs(id[orig]);
		int j=dp[id[orig]][0];
		if(j == dest.size()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
