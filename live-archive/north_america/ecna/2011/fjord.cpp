#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double l[55], r[55], h[55], ang[55], ax, ay, bx, by, cx, cy;
double best[55][3333], dp[55][3333];
int used[55][3333], jmax[55];

void add(int i) {
	l[i] = hypot(ax-bx, ay-by);
	r[i] = hypot(cx-bx, cy-by);
	h[i] = hypot(ax-cx, ay-cy);
	if(l[i] > r[i]) swap(l[i], r[i]);
	ang[i] = acos((l[i]*l[i] + r[i]*r[i] - h[i]*h[i]) / (2*l[i]*r[i]));
}

int main() {
	int T=1;
	while(1) {
		int n, m;
		cin>>n>>m;
		if(n==0) return 0;
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		add(0);
		for(int i=1;i<n;i++) {
			ax=cx; ay=cy;
			cin>>bx>>by>>cx>>cy;
			add(i);
		}
		for(int i=0;i<n;i++) {
			double den = 2*sin(ang[i]/2);
			double c = cos(ang[i]);
			for(int j=1;j<=m;j++) {
				double x = j/den;
				if(x <= l[i]-1e-9) best[i][j] = 2*x - j;
				else {
					double k = l[i]*c;
					double d = k + sqrt(k*k + j*j - l[i]*l[i]);
					if(d >= r[i] + 1e-9) best[i][j]=0;
					else best[i][j] = d + l[i] - j;
					k = r[i]*c;
					d = k - sqrt(k*k + j*j - r[i]*r[i]);
					double v = d + r[i] - j;
					if(d <= l[i] + 1e-9 && best[i][j] < v) best[i][j] = v;
					if(best[i][j] >= 1e-9) jmax[i] = j;
				}
			}
		}
		for(int i=1;i<=m;i++) {
			dp[0][i] = best[0][i];
			used[0][i]=i;
			if(dp[0][i] <= dp[0][i-1] + 1e-9) {
				dp[0][i] = dp[0][i-1];
				used[0][i] = used[0][i-1];
			}
		}
		for(int i=1;i<n;i++) {
			for(int j=1;j<=m;j++) {
				dp[i][j] = best[i][j];
				used[i][j] = j;
				if(dp[i][j] <= dp[i][j-1] + 1e-9) {
					dp[i][j] = dp[i][j-1];
					used[i][j] = used[i][j-1];
				}
				int J = min(j, jmax[i]);
				for(int k=0;k<=J;k++) {
					double sum = best[i][k] + dp[i-1][j-k];
					if(dp[i][j] <= sum) {
						if(dp[i][j] >= sum) used[i][j] = min(used[i][j], k + used[i-1][j-k]); 
						else {
							dp[i][j] = sum;
							used[i][j] = k + used[i-1][j-k];
						}
					}
				}
			}
		}
		printf("Case %d: %d meters used saving %.2lf meters\n", T++, used[n-1][m], dp[n-1][m]);
	}
}
