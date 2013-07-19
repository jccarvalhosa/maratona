#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 333
#define INF 1000000000

int abs(int a) { return a>0?a:-a;}

int n, m, dis[N][N], a[N], b[N];
vector<int> vs, vd, vt;

inline void save(int v, int u, int t) {
	vs.push_back(v+1);
	vd.push_back(u+1);
	vt.push_back(t);
}

void transfer(int v, int u, int t) {
	if(dis[v][u]==1) {
		save(v, u, t);
		return;
	}
	for(int i=0;i<n;i++) if(dis[v][i]==1 && dis[i][u]<dis[v][u]) {
		int tmp=t;
		if(a[i]<t) {
			save(v, i, t-a[i]);
			tmp -= t-a[i];
		}
		transfer(i, u, t);
		if(tmp!=0) save(v, i, tmp);
		break;
	}
}


int main() {
	int i, j, k, e;
	cin>>n>>m>>e;
	for(i=0;i<n;i++) for(j=0;j<n;j++) dis[i][j]=INF;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) cin>>b[i];
	for(i=0;i<e;i++) {
		int x, y;
		cin>>x>>y;
		dis[x-1][y-1] = dis[y-1][x-1] = 1;
	}
	for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(i=0;i<n;i++) if(a[i]!=b[i]) {
		int si = (a[i]-b[i])/abs(a[i]-b[i]);
		for(j=0;j<n;j++) if(dis[i][j]!=INF && a[j]!=b[j]) {
			int sj = (a[j]-b[j])/abs(a[j]-b[j]);
			if(si != sj) {
				int t = min(abs(a[i]-b[i]), abs(a[j]-b[j]));
				if(si==1) {
					transfer(i, j, t);
					a[i]-=t;
					a[j]+=t;
				}
				else {
					transfer(j, i, t);
					a[i]+=t;
					a[j]-=t;
				}
			}
			if(a[i]==b[i]) break;
		}
		if(a[i]!=b[i]) break;
	}
	if(i!=n) cout<<"NO"<<endl;
	else {
		cout<<vs.size()<<endl;
		for(i=0;i<vs.size();i++) cout<<vs[i]<<" "<<vd[i]<<" "<<vt[i]<<endl;
	}
	return 0;
}
