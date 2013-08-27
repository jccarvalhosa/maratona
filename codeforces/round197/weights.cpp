#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int m, vis[1111][11][11];
string s;
vector<int> v;

int go(int p, int d, int last) {
	if(p == m) return 1;
	vis[p][d][last] = 1;
	for(int i=d+1;i<=10;i++) if(i != last && s[i-1]=='1') {
		if(!vis[p+1][i-d][i] && go(p+1, i-d, i)) {
			v.push_back(i);
			return 1;
		}
	}
	return 0;
}

int main() {
	cin>>s;
	memset(vis, 0, sizeof(vis));
	cin>>m;
	if(go(0, 0, -1)) {
		printf("YES\n");
		reverse(v.begin(), v.end());
		printf("%d", v[0]);
		for(int i=1;i<v.size();i++) printf(" %d", v[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}
