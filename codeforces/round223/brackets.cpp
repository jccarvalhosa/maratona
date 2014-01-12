#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=(int)1e6;
char A[N];

typedef struct {
	int op, cl, s;
} interval;

interval M[5*N];

interval join(interval i1, interval i2) {
	interval i;
	i.op=i1.op+i2.op;
	i.cl=i1.cl+i2.cl;
	i.s=i1.s+i2.s+2*min(i1.op-i1.s/2, i2.cl-i2.s/2);
	return i;
}

void initialize(int node, int b, int e) {
	if(b==e) {
		M[node].s=M[node].op=M[node].cl=0;
		if(A[b]=='(') M[node].op=1;
		else M[node].cl=1;
	}
	else {
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		M[node]=join(M[2*node], M[2*node+1]);
	}
}

interval query(int node, int b, int e, int i, int j) {
	interval p1, p2;
	if(i>e || j<b) {
		p1.s=-1;
		return p1;
	}
	if(b>=i && e<=j) return M[node];
	p1=query(2*node, b, (b + e)/2, i, j);
	p2=query(2*node+1, (b+e)/2+1, e, i, j);
	if(p1.s==-1) return p2;
	if(p2.s==-1) return p1;
	return join(p1, p2);
}

int main() {
	int i, n, l, r, q;
	scanf("%s %d", A, &q);
	n=strlen(A);
	initialize(1, 0, n-1);
	for(i=0; i<q; i++) {
		scanf("%d %d", &l, &r);
		l--, r--;
		printf("%d\n", query(1, 0, n-1, l, r).s);
	}
	return 0;
}
