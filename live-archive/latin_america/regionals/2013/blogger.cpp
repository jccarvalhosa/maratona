#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF=1e9;
const int N=1e5+10;
char s[N], t[N], sl[N], tl[N];
int S, T;

int flip[N];
void add(int i) { for(;i;i-=i&-i) flip[i]^=1; }
int query(int i) { int ret=0; for(;i<=S;i+=i&-i) ret^=flip[i]; return ret;}

struct interval {
	int m, M, pend;
	interval(int m=INF, int M=-1) : m(m), M(M), pend(0) {}
};

interval M[5*N];

int val(int pos) {
	if(pos+T-1 >= S || strncmp(sl+pos, tl, T)) return -1;
	int ret=0;
	for(int i=0;i<T;i++) if(s[pos+i] != t[i]) ret++;
	return ret;
}

void init(int node, int b, int e) {
	M[node] = interval();
    if(b==e) {
		M[node].M = val(b);
		if(M[node].M != -1) M[node].m = M[node].M;
	}
    else {
        int m=(b+e)/2;
        init(2*node, b, m);
        init(2*node+1, m+1, e);
		M[node].m = min(M[2*node].m, M[2*node+1].m);
		M[node].M = max(M[2*node].M, M[2*node+1].M);
    }
}

inline void propagate(int node, int b, int e) {
	if(M[node].pend && M[node].M != -1) {
		int aux = M[node].m;
		M[node].m = T - M[node].M;
		M[node].M = T - aux;
		if(b!=e) {
			M[2*node].pend ^= 1;
			M[2*node+1].pend ^= 1;
		}
		M[node].pend=0;
	}
}

void update1(int node, int b, int e, int i, int j) {
    if(i>e || j<b) {
		propagate(node, b, e);
		return;
	}
    if(b>=i && e<=j) {
		M[node].pend^=1;
		propagate(node, b, e);
	}
    else {
        int m=(b+e)/2;
		propagate(node, b, e);
        update1(2*node, b, m, i, j);
        update1(2*node+1, m+1, e, i, j);
		M[node].m = min(M[2*node].m, M[2*node+1].m);
		M[node].M = max(M[2*node].M, M[2*node+1].M);
    }
}

void update2(int node, int b, int e, int pos, int v) {
	propagate(node, b, e);
    if(pos>e || pos<b) return;
    if(b==e) M[node].M = M[node].m = v;
    else {
        int m=(b+e)/2;
        update2(2*node, b, m, pos, v);
        update2(2*node+1, m+1, e, pos, v);
		M[node].m = min(M[2*node].m, M[2*node+1].m);
		M[node].M = max(M[2*node].M, M[2*node+1].M);
    }
}

int query(int node, int b, int e, int i, int j) {
    if(i>e || j<b) return -1;
	propagate(node, b, e);
    if(b>=i && e<=j) return M[node].M;
    else {
        int m=(b+e)/2;
        return max(query(2*node, b, m, i, j), query(2*node+1, m+1, e, i, j));
    }
}

int main() {
	int q;
	while(scanf("%d %s", &q, t) != EOF) {
		T = strlen(t);
		scanf("%s", s);
		S = strlen(s);
		strcpy(sl, s);
		for(int i=0;i<S;i++) sl[i] = tolower(s[i]);
		strcpy(tl, t);
		for(int i=0;i<T;i++) tl[i] = tolower(t[i]);
		init(1, 0, S-1);
		for(int i=0;i<=S;i++) flip[i]=0;
		for(int i=0;i<S;i++) if(s[i]!=sl[i]) { add(i+1); add(i); }
		while(q--) {
			int i, j;
			scanf("%d %d", &i, &j);
			i--;j--;
			printf("%d\n", i <=j-T+1 ? query(1, 0, S-1, i, j-T+1) : -1);
			if(i<=j-T+1) update1(1, 0, S-1, i, j-T+1);
			add(j+1);add(i);
			for(int k=max(0, i-T+1);k<=min(S-1, i+T-1);k++) {
				if(query(k+1)) s[k] = toupper(sl[k]);
				else s[k] = sl[k];
			}
			for(int k=max(0, j-T+1);k<=min(S-1, j+T-1);k++) {
				if(query(k+1)) s[k] = toupper(sl[k]);
				else s[k] = sl[k];
			}
			for(int k=max(0, i-T+1);k<=i;k++) if(val(k) != -1) update2(1, 0, S-1, k, val(k));
			for(int k=max(0, j-T+1);k<=j;k++) if(val(k) != -1) update2(1, 0, S-1, k, val(k));
		}
	}
	return 0;
}
