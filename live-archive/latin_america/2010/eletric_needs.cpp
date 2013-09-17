#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

struct vert {
	int n, x;
	bool operator<(const vert v) const {
		return x < v.x;
	}
} v[40];

struct horz {
	int n, y; bool out;
	bool operator<(const horz h) const {
		return y < h.y || (y == h.y && out < h.out);
	}
} h[40];

int M, N, P;
int gc[20], gr[20];
long long key;

int do_rectangles(int p, int MINR, int MAXR, int MAXC, int &GC) {
	int i, b, k = 0, l, r, t;
	for(i=0;i<P;i++) {
		b = max(MINR, gr[i] - p);
		l = max(0, gc[i] - p - 1);
		r = min(MAXC, gc[i] + p);
		t = min(MAXR, gr[i] + p);
		if(gc[i] <= MAXC && gr[i] >= MINR && gr[i] <= MAXR) ++GC;
		if(t < MINR || b > MAXR || l >= MAXC) continue;
		v[k].n = i; v[k].x = l;
		h[k].n = i; h[k].y = b; h[k].out = 0;
		k++;
		v[k].n = i; v[k].x = r;
		h[k].n = i; h[k].y = t; h[k].out = 1;
		k++;
	}
	sort(v, v + k);
	sort(h, h + k);
	return k;
}

long long area(int p, int MINR, int MAXR, int MAXC) {
	int i, j, GC = 0, length, start, xact = 0, yact = 0;
	int K = do_rectangles(p, MINR, MAXR, MAXC, GC);
	long long ret = 0, diff;
	for(i=0;i<K;i++) {
		if(i && v[i].x != v[i-1].x) {
			length = 0;
			for(j=0;j<K;j++) {
				if(!(xact & (1 << h[j].n))) continue;
				if(!yact) start = h[j].y;
				yact ^= 1 << h[j].n;
				if(!yact) length += h[j].y - start + 1;
			}
			diff = v[i].x - v[i-1].x;
			ret += diff * length;
		}
		xact ^= 1 << v[i].n;
	}
	return ret - GC;
}

int bin_search(int LIM, int type, int p=0, int l=0) {
	int m, i=1, f=LIM;
	long long A;
	while(i < f) {
		m = (i+f)/2;
		if(type == 1) A = area(m, 1, N, M);
		else if(type == 2) A = area(p, 1, m, M) - area(p-1, 1, m, M);
		else if(type == 3) A = area(p, l, l, m) - area(p-1, l, l, m);
		A < key ? i = m+1 : f = m;
	}
	return i;
}

int main() {
	int i, c, l, p, Q;
	while(scanf("%d %d %d", &N, &M, &P) && N) {
		for(i=0;i<P;i++) scanf("%d %d", &gr[i], &gc[i]);
		scanf("%d", &Q);
		while(Q--) {
			scanf("%lld", &key);
			p = bin_search(max(N, M), 1);
			key -= area(p-1, 1, N, M);
			l = bin_search(N, 2, p);
			key -= area(p, 1, l-1, M) - area(p-1, 1, l-1, M);
			c = bin_search(M, 3, p, l);
			printf("%d %d\n", l, c);
		}
		printf("-\n");
	}
	return 0;
}
