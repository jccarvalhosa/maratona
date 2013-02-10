#include <stdio.h>
#define MAX 100001

int N, v[MAX], p[MAX], tree[MAX], val[MAX];

void update(int p, int v) {
	int delta = v - val[p];
	for(val[p] = v; p <= N; p += p&-p) tree[p] += delta;
}

int query(int p) {
	int ret=0;
	for(; p ; p -= p&-p) ret += tree[p];
	return ret;
}

int binary_search(int key) {
	int m, i=1, f=N;
	while(i<f) {
		m = (i+f)/2;
		if(query(m) < key) i = m+1;
		else f = m;
	}
	return f;
}

int main() {
	int M, pos, i, trocas;
	while(scanf("%d%d", &N, &M) && N) {
		for(i=1;i<=N;i++) p[i] = v[i] = val[i] = tree[i] = 0;
		for(i=1;i<=N;i++) update(i, 1);
		for(i=1;i<=M;i++) {
			scanf("%d", &trocas);
			pos = binary_search(trocas+1);
			update(pos, 0);
			v[pos] = i;
		}
		for(i=1;i<=N;i++) if(!v[i]) v[i] = ++M;
		for(i=1;i<=N;i++) printf("%d ", v[i]);
		printf("\n");
	}
	return 0;
}
