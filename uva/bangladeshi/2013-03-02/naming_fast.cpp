#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 20001
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

ll query(int x) {
    while(pos + 1 < nh && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}

char pn[27], nm[MAX];
int p[27], pasum[MAX], sum[MAX];
int dp[501][MAX], a[MAX], b[MAX], c[MAX], d[MAX];

inline int val(int i) { return p[nm[i]-'a']; }

int main() {
	int T, t, n, K, i, j, k, ans;
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		printf("Case %d: ", t);
		scanf(" %s %d", pn, &K);
		scanf(" %s", nm);
		n = strlen(nm);
		for(i=0;i<26;i++) p[pn[i]-'a'] = i;
		ans=0;
		for(i=0;i<n;i++) ans -= val(i) * val(i);
		pasum[0] = 0;
		sum[0] = val(0);
		for(i=1;i<n;i++) {
			sum[i] = sum[i-1] + val(i);
			pasum[i] = pasum[i-1] + i*val(i);
		}
		for(i=0;i<n;i++) {
			dp[1][i] = pasum[i]; 
			a[i] = pasum[i] - sum[i]; 
			b[i] = (i+1)*sum[i] - pasum[i];
			c[i] = sum[i];
			d[i] = -i;
		}
		for(k=2;k<=K;k++) {
			nh = pos = 0;
			for(i=1;i<n;i++) {
				update(line(dp[k-1][i-1] + b[i-1], d[i-1]));
				dp[k][i] = a[i] + query(c[i]);
			}
		}
		printf("%d\n", ans + dp[K][n-1]);
	}
	return 0;
}
