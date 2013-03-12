#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 20001
#define INF 1000000000

char pn[27], nm[MAX];
int pos[27], pasum[MAX], sum[MAX];
int pd[MAX][501];

inline int val(int i) { return pos[nm[i]-'a']; }

inline int tax(int i, int j) {
	if(i==0) return pasum[j];
	return (pasum[j] - pasum[i-1]) - i*(sum[j] - sum[i-1]);
}

int main() {
	int T, t, n, K, i, j, k, ans;
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		printf("Case %d: ", t);
		scanf(" %s %d", pn, &K);
		scanf(" %s", nm);
		n = strlen(nm);
		for(i=0;i<26;i++) pos[pn[i]-'a'] = i;
		ans=0;
		for(i=0;i<n;i++) ans -= val(i) * val(i);
		pasum[0] = 0;
		sum[0] = val(0);
		for(i=1;i<n;i++) {
			sum[i] = sum[i-1] + val(i);
			pasum[i] = pasum[i-1] + i*val(i);
		}
		for(i=0;i<n;i++) pd[i][1] = tax(0, i);
		for(k=2;k<=K;k++) {
			pd[0][k] = INF;
			for(i=1;i<n;i++) {
				pd[i][k] = pd[i-1][k-1];
				for(j=i-1;j>=k-2;j--) {
					if(tax(j, i) >= pd[i][k]) break;
					pd[i][k] = min(pd[i][k], pd[j-1][k-1] + tax(j, i));
				}
			}
		}
		printf("%d\n", ans + pd[n-1][K]);
	}
	return 0;
}
