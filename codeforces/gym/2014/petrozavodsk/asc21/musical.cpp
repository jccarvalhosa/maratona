#include <bits/stdc++.h>
using namespace std;

int ans[11], pos[11], info[11][11][11];
double val=-1;
int fan[11], crazy[11], maniac[11], city[11][11], vis[11][11][11];
int fansum[11][11], crazysum[11][11], maniacsum[11][11], maxinfo[11][11];
double crazyprob[11][11], maniacprob[11][11], fanprob[11][11];
int myinfo[11];
vector<int> adj[11];

int main() {
	freopen("musical.in", "r", stdin);
	freopen("musical.out", "w", stdout);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>fan[i]>>crazy[i]>>maniac[i];
	while(m--) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=k;i++) for(int week=1;week<=n;week++) cin>>city[i][week];
	for(int week=1;week<=n;week++) {
		for(int c=1;c<=n;c++) {
			maxinfo[week][c]=0;
			for(int i=1;i<=k;i++) {
				info[week][c][i] = info[week-1][c][i];
				if(city[i][week] == c) {
					crazysum[c][week]++;
					maniacsum[c][week]++;
					maxinfo[week][c] = max(maxinfo[week][c], info[week-1][c][i]);
				}
				for(int j=0;j<adj[c].size();j++) {
					if(city[i][week] == adj[c][j]) maniacsum[c][week]++;
				}
			}
			for(int i=1;i<=k;i++) {
				if(city[i][week] == c && info[week-1][c][i] == maxinfo[week][c]) {
					fansum[c][week]++;
				}
			}
		}
		for(int i=1;i<=k;i++) {
			int c = city[i][week];
			for(int j=0;j<adj[c].size();j++) {
				int u = adj[c][j];
				if(vis[u][c][i]) continue;
				vis[u][c][i]=1;
				info[week][u][i]++;
			}
		}
	}
	for(int week=1;week<=n;week++) for(int c=1;c<=n;c++) {
		crazyprob[week][c] = crazy[c] * 7.0 / (1+crazysum[c][week]);
		maniacprob[week][c] = maniac[c] * 7.0 / (1+maniacsum[c][week]);
		for(int j=0;j<adj[c].size();j++) {
			maniacprob[week][c] += maniac[adj[c][j]] * 7.0 / (1+maniacsum[adj[c][j]][week]);
		}
		fanprob[week][c] = fan[c] * 1.0 / (1+fansum[c][week]);
	}
	for(int i=0;i<n;i++) pos[i]=i;
	do {
		double aux=0;
		for(int c=1;c<=n;c++) myinfo[c]=0;
		for(int week=1;week<=n;week++) {
			int c = pos[week-1]+1;
			aux += crazyprob[week][c];
			aux += maniacprob[week][c];
			if(myinfo[c] > maxinfo[week][c]) {
				aux += fan[c];
			}
			else if(myinfo[c] == maxinfo[week][c]) {
				aux += fanprob[week][c];
			}
			for(int j=0;j<adj[c].size();j++) myinfo[adj[c][j]]++;
		}
		if(aux > val) {
			val = aux;
			for(int i=0;i<n;i++) ans[i]=pos[i];
		}
	} while(next_permutation(pos, pos+n));
	printf("%.12lf\n", val);
	printf("%d", ans[0]+1);
	for(int i=1;i<n;i++) printf(" %d", ans[i]+1);
	printf("\n");
	return 0;
}
