#include <cstdio>
#define MOD 1000000007

int v[300], dep[300], ord[300], vis[300], p[300], num[100001];

int main() {
	int n, q, t, a, b, i, j, Q;
	scanf("%d%d%d", &n, &q, &t);
	for(i=0;i<n;i++) {
		scanf("%d", v+i);
		dep[i] = vis[i] = 0;
	}
	for(i=0;i<q;i++) {
		scanf("%d%d", &a, &b); 
		a--; b--;
		p[a] = b;
		vis[a]=1;
		dep[b]++;
	}
	Q=0;
	for(i=0;i<n;i++) if(vis[i] && !dep[i]) ord[Q++] = i;
	for(i=0;i<Q;i++) {
		a = ord[i];
		if(vis[p[a]] && --dep[p[a]] == 0) ord[Q++] = p[a];
	}
	if(Q != q) printf("0\n");
	else {
		for(i=0;i<q;i++) {
			a = ord[i];
			b = p[a];
			v[b] += v[a];
			t -= v[a];
			if(t < 0) break;
		}
		if(i != q) printf("0\n");
		else {
			num[0]=1;
			for(j=1;j<=t;j++) num[j]=0;
			for(i=0;i<n;i++) for(j=v[i];j<=t;j++) num[j] = (num[j] + num[j-v[i]]) % MOD;
			printf("%d\n", num[t]);
		}
	}
	return 0;
}
