#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
double p[N+1], h[N+1], w[N+1], t[N+1], we[N+1];
int dp[12][12][12][12][12];
set <double> s[5];
map <double,int> id[5];
double pq[2], hq[2], wq[2], tq[2], weq[2];
int pp[2], hp[2], wp[2], tp[2], wep[2];

int val(int k) {
	return dp[pp[((1<<4)&k)==0]][hp[((1<<3)&k)==0]][wp[((1<<2)&k)==0]][tp[((1<<1)&k)==0]][wep[((1<<0)&k)==0]];
}

void find() {
	set<double>::iterator it;
	int i;
	for(it=s[0].begin(), i=0;it!=s[0].end();it++, i++) if((*it) > pq[1]) break;
	pp[1] = i-1;
	for(it=s[1].begin(), i=0;it!=s[1].end();it++, i++) if((*it) > hq[1]) break;
	hp[1] = i-1;
	for(it=s[2].begin(), i=0;it!=s[2].end();it++, i++) if((*it) > wq[1]) break;
	wp[1] = i-1;
	for(it=s[3].begin(), i=0;it!=s[3].end();it++, i++) if((*it) > tq[1]) break;
	tp[1] = i-1;
	for(it=s[4].begin(), i=0;it!=s[4].end();it++, i++) if((*it) > weq[1]) break;
	wep[1] = i-1;
	for(it=s[0].begin(), i=0;it!=s[0].end();it++, i++) if((*it) >= pq[0]) break;
	pp[0] = i-1;
	for(it=s[1].begin(), i=0;it!=s[1].end();it++, i++) if((*it) >= hq[0]) break;
	hp[0] = i-1;
	for(it=s[2].begin(), i=0;it!=s[2].end();it++, i++) if((*it) >= wq[0]) break;
	wp[0] = i-1;
	for(it=s[3].begin(), i=0;it!=s[3].end();it++, i++) if((*it) >= tq[0]) break;
	tp[0] = i-1;
	for(it=s[4].begin(), i=0;it!=s[4].end();it++, i++) if((*it) >= weq[0]) break;
	wep[0] = i-1;
}

int go(int o, int i, int j, int k, int l, int m) {
	i = i-(((1<<4)&o) > 0);
	j = j-(((1<<3)&o) > 0);
	k = k-(((1<<2)&o) > 0);
	l = l-(((1<<1)&o) > 0);
	m = m-(((1<<0)&o) > 0);
	if(i < 0 || j < 0 || k < 0 || l < 0 || m < 0) return 0;
	return dp[i][j][k][l][m];
}

int main()
{
	int te=1, T, n, q;
	freopen("gift.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &q);
		for(int i=0;i<5;i++) {
			s[i].clear();
			id[i].clear();
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<5;i++) s[i].insert(-1);
		for(int i=0;i<n;i++) {
			scanf("%lf %lf %lf %lf %lf", &p[i], &h[i], &w[i], &t[i], &we[i]);
			s[0].insert(p[i]);
			s[1].insert(h[i]);
			s[2].insert(w[i]);
			s[3].insert(t[i]);
			s[4].insert(we[i]);
		}
		for(int i=0;i<5;i++) {
			int j = 0;
			for(set<double>::iterator it=s[i].begin();it!=s[i].end();it++) {
				id[i][(*it)] = j++;
			}
		}
		for(int i=0;i<n;i++) dp[id[0][p[i]]][id[1][h[i]]][id[2][w[i]]][id[3][t[i]]][id[4][we[i]]]++;

		for(int i=0;i<s[0].size();i++) {
			for(int j=0;j<s[1].size();j++) {
				for(int k=0;k<s[2].size();k++) {
					for(int l=0;l<s[3].size();l++) {
						for(int m=0;m<s[4].size();m++) {
							for(int o=1;o<(1<<5);o++) {
								int z = __builtin_popcount(o);
								if(z&1) dp[i][j][k][l][m] += go(o, i, j, k, l, m);
								else dp[i][j][k][l][m] -= go(o, i, j, k, l, m);
							}
						}
					}
				}
			}
		}

		printf("Case %d:\n", te++);
		for(int i=0;i<q;i++) {
			for(int j=0;j<2;j++) scanf("%lf%lf%lf%lf%lf", &pq[j], &hq[j], &wq[j], &tq[j], &weq[j]);
			int r = 0;
			find();
			for(int j=0;j<(1<<5);j++) {
				int z = __builtin_popcount(j);
				if(z&1) r -= (val(j));
				else r += (val(j));
			}
			printf("%d\n", r);
		}
	}
	return 0;
}
