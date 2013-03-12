#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1001
typedef long long ll;

struct line {
    ll m, y0;
    line(ll y0=0, ll m=0): y0(y0), m(m) {}
};

bool check(line a, line b, line c){
    return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
}

int nh, pos;
line H[MAX];

void update(line l) {
    while(nh >= 2 && !check(H[nh-2], H[nh-1], l)) if(pos == --nh) --pos;
    H[nh++] = l;
}

ll eval(int id, int x) {
    return H[id].y0 + H[id].m*x;
}

ll query(int x){
    while(pos + 1 < nh && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}

int N, K; 
ll x[MAX], w[MAX], f[MAX], g[MAX], dp[MAX][MAX], a[MAX], b[MAX], c[MAX], d[MAX];

int main() {
	int i, k;
    while(scanf("%d%d", &N, &K) != EOF) {
		for(i=0;i<N;i++) scanf("%lld%lld", &x[i], &w[i]);
		f[0] = w[0];
		g[0] = x[0]*w[0];
		for(i=1;i<N;i++) {
			f[i] = f[i-1] + w[i];
			g[i] = g[i-1] + x[i]*w[i];
		}
		for(i=0;i<N;i++) {
			dp[1][i] = x[i]*f[i] - g[i];  
			a[i] = f[i]*x[i] - g[i];
			b[i] = g[i];
			c[i] = x[i];
			d[i] = -f[i];
		}
		for(k=2;k<=K;k++) {
			nh = pos = 0;
			for(i=1;i<N;i++) {
				update(line(dp[k-1][i-1] + b[i-1], d[i-1]));
				dp[k][i] = a[i] + query(c[i]);
			}
		}
		printf("%lld\n", dp[K][N-1]);
	}
    return 0;
}
