#include <cstdio>
#include <cstring>
typedef double ld;
const int N=3333;
ld dp[N][N];
int vis[N][N];

int a, b, n;

ld go(int t, int la, int lb) {
	if(la > a) return 0;
	if(lb > b) return 0;
	if(la+lb >= n) return 0;
	if(vis[la][lb]) return dp[la][lb];
	ld na = 2*(a-la);
	ld nb = b-lb;
	ld num = 2.0;
	if(t==1) num = 1.0;
	ld den = num+na+nb;
	vis[la][lb]=1;
	return dp[la][lb] = num/den + (na/den)*go(t, la+1, lb) + (nb/den)*go(t, la, lb+1);
}

int main() {
	freopen("bonus.in", "r", stdin);
	freopen("bonus.out", "w", stdout);
	scanf("%d %d %d", &n, &a, &b);
	memset(vis, 0, sizeof(vis));
	printf("%.18Lf\n", go(0, 0, 0));
	memset(vis, 0, sizeof(vis));
	printf("%.18Lf\n", go(1, 0, 0));
	return 0;
}
