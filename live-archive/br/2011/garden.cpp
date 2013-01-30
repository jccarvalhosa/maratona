#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Tree {
	int x, y, v, type;
};

inline bool above(const Tree &t) { return t.y != 0 ? t.y > 0 : t.x > 0; }
inline bool below(const Tree &t) { return !above(t); }

bool cmp(const Tree &a, const Tree &b) {
	ll cross = 1ll * a.x * b.y - 1ll * a.y * b.x;
	if(!above(a)) cross = -cross;
	if(!above(b)) cross = -cross;
	return cross > 0;
}

bool equal(const Tree &a, const Tree &b) { return 1ll * a.x * b.y - 1ll * a.y * b.x == 0; }

int N, M, sum;
Tree t[2000], m[2000];

int sweep(int sum) {
	sort(m, m+M, cmp);
	int i, j, ret, score=0, cup=0, cd=1;
	for(i=0;i<M;i++) {
		if(above(m[i])) { if(m[i].type != cup) score += m[i].v; }
		else if(m[i].type != cd) score += m[i].v;
	}
	ret = min(score, sum - score);
	for(i=0;i<M;i=j) {
		for(j=i;j < M && equal(m[i], m[j]); j++) {
			if(m[j].type == (above(m[j]) ? cup: cd)) score += m[j].v;
			else score -= m[j].v;
		}
		ret = min(ret, min(score, sum - score));
	}
	return ret;
}

int main() {
	int P, L, sum, i, j;
	while(scanf("%d%d", &P, &L) && P) {
		sum = 0;
		N = P+L;
		for(i=0;i<N;i++) {
			scanf("%d%d%d", &t[i].x, &t[i].y, &t[i].v);
			sum += t[i].v;
			t[i].type = 1;
		}
		for(i=0;i<P;i++) t[i].type = 0;
		int ans = sum;
		for(i=0;i<N;i++) {
			M = 0;
			for(j=0;j<N;j++) if(j != i) {
				m[M] = t[j];
				m[M].x = t[j].x - t[i].x;
				m[M].y = t[j].y - t[i].y;
				M++;
			}
			ans = min(ans, sweep(sum - t[i].v));
		}
		printf("%d\n", ans);
	}
	return 0;
}
