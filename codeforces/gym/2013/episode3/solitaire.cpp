#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define mp make_pair

set<ull> s[3];

int p[2];
set< vector<pair<int, int> > > vis[3];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int flag, vector<pii> ini) {
	queue<pair<vector<pii>, int > > q;
	vis[flag].insert(ini);
	q.push(mp(ini, 0));
	while(!q.empty()) {
		ini = q.front().first;
		int d = q.front().second;
		q.pop();
		ull tab_ini = 0;
		for(int i=0;i<4;i++) tab_ini |= 1ull<<(8*ini[i].first + ini[i].second);
		s[flag].insert(tab_ini);
		for(int i=0;i<4;i++) {
			int x, y;
			for(int j=0;j<4;j++) {
				x = ini[i].first + dx[j];
				y = ini[i].second + dy[j];
				if(x < 0 || x >= 8 || y < 0 || y >= 8) continue;
				int k;
				for(k=0;k<4;k++) if(i != k && pii(x, y) == ini[k]) break;
				if(k != 4) {
					x += dx[j];
					y += dy[j];
					if(x < 0 || x >= 8 || y < 0 || y >= 8) continue;
					k=0;
					for(k=0;k<4;k++) if(i != k && pii(x, y) == ini[k]) break;
					if(k != 4) continue;
				}
				vector<pii> ini2 = ini;
				ini2[i] = pii(x, y);
				if(!vis[flag].count(ini2)) {
					vis[flag].insert(ini2);
					if(d < 4) q.push(mp(ini2, d+1));
				}
			}
		}
	}
}

int main() {
	vector<pii> v[2];
	for(int pos=0;pos<2;pos++) for(int i=0;i<4;i++) {
		int r;
		int c;
		cin>>r>>c; 
		r--; c--;
		v[pos].push_back(mp(r, c));
	}
	bfs(1, v[0]);
	bfs(2, v[1]);
	int valid=0;
	for(set<ull>::iterator it = s[1].begin(); it != s[1].end(); it++) if(s[2].count(*it)) {
		valid=1;
		break;
	}
	if(valid) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
