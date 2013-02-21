#include <cstdio>
#include <cstring>

int N, tree[2][100001], val[100001];

void _update(int p, int v, int type) {
	for(; p <= N; p += p&-p) tree[type][p] += v;
}

void update(int p, int v) {
	if(val[p] == 0) _update(p, -1, 0);
	if(val[p] == -1) _update(p, -1, 1);
	val[p]=v;
	if(v == 0) _update(p, 1, 0);
	if(v == -1) _update(p, 1, 1);
}

int _query(int p, int type) {
	int ans=0;
	for(; p ; p -= p&-p) ans += tree[type][p];
	return ans;
}

int query(int i, int f, int type) {
	return _query(f, type) - _query(i-1, type);
}


int main() {
	int i, a, b, K;
	char c;
	while(scanf("%d%d", &N, &K) != EOF) {
		memset(tree, 0, sizeof(tree));
		for(i=1;i<=N;i++) {
			val[i]=1;
			scanf("%d", &a);
			if(a < 0) update(i, -1);
			else if(!a) update(i, 0);
		}
		while(K--) {
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'P') {
				if(query(a, b, 0) != 0) printf("0");
				else if(query(a, b, 1) % 2 != 0) printf("-");
				else printf("+");
			}
			else update(a, b > 0 ? 1 : !b ? 0 : -1);
		}
		printf("\n");
	}
	return 0;
}
