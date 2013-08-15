#include <stdio.h>
#include <algorithm>
using namespace std;

struct interval {
	int h, e, r;
	int pending;
	interval(int h=1, int e=0, int r=0, int pending=0): h(h), e(e), r(r), pending(pending) {}
};

struct interval M[1000000];

void get_children_values(int node) {
	M[node].h = M[2*node].h + M[2*node+1].h;
	M[node].e = M[2*node].e + M[2*node+1].e;
	M[node].r = M[2*node].r + M[2*node+1].r;
}

void shift_values(int node) {
	for(int i=0;i<M[node].pending;i++) {
		swap(M[node].h, M[node].r);
		swap(M[node].r, M[node].e);
	}
}

void propagate_pending(int node, int b, int e) {
	M[2*node].pending += M[node].pending;
	M[2*node+1].pending += M[node].pending;
}

void fix_pending(int node, int b, int e) {
	M[node].pending %= 3;
	shift_values(node);
	if(b != e) propagate_pending(node, b, e);
	M[node].pending = 0;
}

interval join(interval i1, interval i2) {
	return interval(i1.h+i2.h, i1.e+i2.e, i1.r+i2.r);
}

interval query(int node, int b, int e, int i, int j) {
	interval p1, p2;
	fix_pending(node, b, e);
	if(j<b || i>e) {
		p1.h = -1;
		return p1;
	}
	if(i<=b && j>=e) return M[node];
	p1=query(2*node, b, (b+e)/2, i, j);
	p2=query(2*node+1, (b+e)/2+1, e, i, j);
	if(p1.h==-1) return p2;
	if(p2.h==-1) return p1;
	return join(p1, p2);
}

void update(int node, int b, int e, int i, int j) {
	if(i<=b && j>=e) {
		M[node].pending++;
		fix_pending(node, b, e);
	}
	else if(j<b || i>e) fix_pending(node, b, e);
	else {
		propagate_pending(node, b, e);
		M[node].pending = 0;
		update(2*node, b, (b+e)/2, i, j);
		update(2*node+1, (b+e)/2+1, e, i, j);
		get_children_values(node);
	}
}

void initialize(int node, int b, int e) {
	M[node].pending = 0;
	if(b == e) M[node] = interval();
	else {
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		get_children_values(node);
	}
}

int main() {
	int N, M, a, b;
	char c;
	interval resp;
	while(scanf("%d %d", &N, &M) != EOF) {
		initialize(1, 1, N);
		while(M--) {
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'M') update(1, 1, N, a, b);
			else {
				resp=query(1, 1, N, a, b);
				printf("%d %d %d\n", resp.h, resp.e, resp.r);
			}
		}
		printf("\n");
	}
	return 0;
}
