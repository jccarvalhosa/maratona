#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

int e[201][10001];
vector<int> g[10001];

int main() {
	set<pp> s;
	int n;
	cin>>n;
	for(int i=0;i<n*(n-1)/2;i++) {
		int x, y, k;
		cin>>x>>y>>k;
		for(int j=0;j<k;j++) {
			int v;
			cin>>v;
			s.insert(pp(v, pii(x, y)));
			s.insert(pp(v, pii(y, x)));
			g[v].push_back(x);
			g[v].push_back(y);
			e[x][v]=1;
			e[y][v]=1;
		}
	}
	int valid=1;
	for(int i=1;i<10001;i++) {
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
		for(int j=0;j<g[i].size();j++) for(int k=j+1;k<g[i].size();k++) if(!s.count(pp(i, pii(g[i][j], g[i][k])))) valid=0;
	}
	if(!valid) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		for(int i=1;i<=n;i++) {
			int c=0;
			for(int j=1;j<10001;j++) if(e[i][j]) c++;
			cout<<c;
			for(int j=1;j<10001;j++) if(e[i][j]) cout << " " << j;
			cout << endl;
		}
	}
	return 0;
}
