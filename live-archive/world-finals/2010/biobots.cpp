#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

int good[4444][3333], vis[4444][3333];

const int M = 1e6+10;
int idx[M], idy[M];
int R, C, r, c;

pii q[30000000];

void bfs(int x, int y) {
	int i=0, f=1;
	q[0] = pii(x, y);
	vis[x][y]=1;
	while(i!=f) {
		int x = q[i].first;
		int y = q[i++].second;
		if(x && !vis[x-1][y] && good[x-1][y]) {
			vis[x-1][y] = 1;
			q[f++] = pii(x-1, y);
		}
		if(y && !vis[x][y-1] && good[x][y-1]) {
			vis[x][y-1] = 1;
			q[f++] = pii(x, y-1);
		}
	}
}

vector<int> vx, vy;

int main() {
	int T=1, w;
	while(cin>>C>>R>>w && C) {
		vx.clear();
		vy.clear();
		vector<pp> wall;
		vx.push_back(0);
		vx.push_back(R-1);
		vy.push_back(0);
		vy.push_back(C-1);
		for(int i=0;i<w;i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			wall.push_back(pp(y1, pii(x1, x2)));
			if(x1) vx.push_back(x1-1);
			vx.push_back(x1);
			vx.push_back(x2);
			if(x2 < R-1) vx.push_back(x2+1);
			if(y1) vy.push_back(y1-1);
			vy.push_back(y1);
			if(y1 < C-1) vy.push_back(y1+1);
		}
		sort(vx.begin(), vx.end()); 
		sort(vy.begin(), vy.end());
		vx.erase(unique(vx.begin(), vx.end()), vx.end());
		vy.erase(unique(vy.begin(), vy.end()), vy.end());
		r = vx.size();
		c = vy.size();
		vx.push_back(R);
		vy.push_back(C);
		for(int i=0;i<r;i++) idx[vx[i]]=i;
		for(int i=0;i<c;i++) idy[vy[i]]=i;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) good[i][j]=1;
		for(int i=0;i<w;i++) {
			for(int x=idx[wall[i].second.first];x<=idx[wall[i].second.second];x++) good[x][idy[wall[i].first]]=0;
		}
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) vis[i][j]=0;
		if(good[r-1][c-1]) bfs(r-1, c-1);
		ll ans=0;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(good[i][j] && !vis[i][j]) {
			ans += 1ll * (vx[i+1] - vx[i]) * (vy[j+1] - vy[j]);
		}
		cout << "Case " << T++ << ": " << ans << endl;
	}
	return 0;
}
