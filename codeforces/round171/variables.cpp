#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000
using namespace std;
	
int a[24], s[24][24], n, val[1<<23];

int dfs(int vis, int tam, int pos) {
	if(pos == n) return tam;
	if(val[vis]) return val[vis];
	int i, ans=INF;
	for(i=0;i<pos;i++) if((vis & (1<<i)) && (vis & (1<<s[i][pos]))) break;
	if(i==pos) return val[vis] = INF;
	for(i=0;i<pos;i++) if(vis & (1<<i)) {
		vis -= 1<<i;
		vis += 1<<pos;
		ans = min(ans, dfs(vis, tam, pos+1));
		vis += 1<<i;
		vis -= 1<<pos;
	}
	vis += 1<<pos;
	ans = min(ans, dfs(vis, tam+1, pos+1));
	vis -= 1<<pos;
	return val[vis] = ans;
}

int main() {
	int i, j, k, ans;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	for(i=0;i<n;i++) for(j=0;j<n;j++) s[j][i] = i;
	for(i=1;i<n;i++) for(j=i-1;j>=0;j--) for(k=i-1;k>=0;k--) if(a[j]+a[k] == a[i]) {
		s[j][i] = k;
		s[k][i] = j;
	}
	for(i=0;i<(1<<n);i++) val[i] = 0;
	ans = dfs(1, 1, 1);
	printf("%d\n", ans==INF ? -1 : ans);
	return 0;
}
