#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iostream>
using namespace std;
#define NN 600000

char s[NN];
int C, H, L;
int B[NN], lcp[NN], sa[NN];

bool cmp(int x, int y) { return H ? B[x]==B[y] ? B[x+H] < B[y+H] : B[x] < B[y] : s[x] < s[y]; }
bool eq(int x, int y) { return !cmp(sa[x], sa[y]) && !cmp(sa[y], sa[x]); }

int ub() {
    int i, st=0, id=0;
    bool c=0;
    sort(sa, sa+L, cmp);
    for(i=0;i<L;i++) {
        if(i && !eq(i, i-1)) st=i, id++;
        c |= (i != st);
        lcp[sa[i]] = id;
    }
    memcpy(B, lcp, 4*L);
    return c;
}

void ss() {
    int i, j, l=0;
    char *a, *b;
    for(i=0;i<L;i++) sa[i] = i;
    for(H=0;ub();H=max(2*H, 1));
    for(i=0;i<L;i++) B[sa[i]] = i;
    for(i=0;i<L;i++) if(B[i]) {
        j = sa[B[i]-1];
        a = s + i + l;
        b = s + j + l;
        while(*a != '-' && *b != '-' && *a++ == *b++) l++;
        lcp[B[i]] = l;
        if(l) l--;
    }
}

set<long long> sub;
int F, orig[NN], fim[60];
int tam(int i) { return fim[orig[sa[i]]] - sa[i]; }
char aux[NN];

int main() {
    int i, j, n;
    while(scanf("%d", &F) && F) {
		sub.clear();
        L = 0;
		for(i=0;i<F;i++) {
			scanf("%s%n", aux, &n); n--;
			for(j=0;j<n;j++) {
				s[L+j] = aux[j];
				orig[L+j] = i;
			}
			s[L+n] = '-';
			orig[L+n] = -1;
			L += n + 1; 
			fim[i] = L-1;
		}
		orig[L] = -1;
		s[L++] = '\0';
        ss();
		lcp[L] = 0;

		for(i=2;i<L;i++) {
			long long vis = 0;
			int busca = tam(i);
			for(j=i; orig[sa[j]] != -1 && busca > lcp[i+1]; j--) {
				vis |= (1ll << orig[sa[j]]);
				if(lcp[j] < busca) {
					sub.insert(vis); 
					busca = lcp[j];
				}
			}
			if(vis) sub.insert(vis);
		}
		cout << sub.size() << endl;
        //for(int i=0;i<L;i++) printf("%d %d '%s' %d\n", sa[i], lcp[i], s + sa[i], orig[sa[i]]);
    }
    return 0;
}
