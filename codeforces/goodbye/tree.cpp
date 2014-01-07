#include <cstdio>
#include <algorithm>
using namespace std;

const int L=30;
const int N=1000010;
int p[N][L], dep[N];
int v1=2, v2=3, n=4, d=2;

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i=L-1;i>=0;i--) if(dep[a]-(1<<i) >= dep[b]) a = p[a][i];
	if(a == b) return a;
	for(int i=L-1;i>=0;i--) if(p[a][i] != p[b][i]) a=p[a][i], b=p[b][i];
	return p[a][0];
}

int dist(int a, int b) { return dep[a] + dep[b] - 2*dep[lca(a, b)]; }

void add(int v) {
	n++;
	p[n][0] = v;
	dep[n] = dep[v]+1;
	for(int i=1;i<L;i++) p[n][i] = p[p[n][i-1]][i-1];
	int d1 = dist(v1, n);
	int d2 = dist(v2, n);
	if(d1 >= d2 && d1 > d) {
		v2 = n;
		d = d1;
	}
	else if(d2 > d) {
		v1 = n;
		d = d2;
	}
}

int main() {
	for(int i=0;i<L;i++) p[1][i] = p[2][i] = p[3][i] = p[4][i] = 1;
	dep[1]=0;
	dep[2]=dep[3]=dep[4]=1;
	int q;
	scanf("%d", &q);
	while(q--) {
		int v;
		scanf("%d", &v);
		add(v);
		add(v);
		printf("%d\n", d);
	}
	return 0;
}
