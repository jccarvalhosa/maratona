#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N=1e5+10;
ll x[N], y[N];
const int L=20;
int p[N][L], dep[N];
	
int n;

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i=L-1;i>=0;i--) if(dep[a]-(1<<i) >= dep[b]) a = p[a][i];
	if(a == b) return a;
	for(int i=L-1;i>=0;i--) if(p[a][i] != p[b][i]) a=p[a][i], b=p[b][i];
	return p[a][0];
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	p[n-1][0] = n-1;
	for(int i=n-2;i>=0;i--) {
		int b = i+1;
		for(int j=p[i+1][0];;j=p[j][0]) {
			if((y[j]-y[i])*(x[b]-x[i]) > (y[b]-y[i])*(x[j]-x[i])) {
				b=j;
			}
			else break;
			if(p[j][0] == j) break;
		}
		p[i][0] = b;
	}
	for(int i=1;i<L;i++) for(int j=0;j<n;j++) p[j][i] = p[p[j][i-1]][i-1];
	dep[n-1] = 0;
	for(int j=n-2;j>=0;j--) dep[j] = dep[p[j][0]]+1;
	int q;
	scanf("%d", &q);
	for(int i=0;i<q;i++) {
		int a, b;
		scanf("%d%d", &a, &b); a--;b--;
		if(i) printf(" ");
		printf("%d", lca(a, b)+1);
	}
	printf("\n");
	return 0;
}
