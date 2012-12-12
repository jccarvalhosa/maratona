#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define NN 100030

char s[NN];
int C, H, L;
int B[NN], lcp[NN], sa[NN];

bool cmp(int x, int y) { return H ? B[x]==B[y] ? B[x+H] < B[y+H] : B[x] < B[y] : s[x] < s[y]; }
bool eq(int x, int y) { return !cmp(sa[x], sa[y]) && !cmp(sa[y], sa[x]); }

int ub() {
    int i, st=0, id=0;
    bool c=0;
    sort(sa, sa+L, cmp);
    for(i=0;i<L;i++){
        if(i != 0 && !eq(i, i-1)) st=i, id++;
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
        while(*a++ == *b++) l++;
        lcp[B[i]] = l;
        if(l) l--;
    }
}

int main()
{
    int sol, i;
    while(scanf("%s", s) && *s != '*') {
        L = strlen(s)+1;
        sol=0;
        ss();
        for(i=L-1;i>0;i--) {
            int x = lcp[i] - lcp[i-1];
            if(x > 0) sol += x;
        }
        printf("%d\n", sol);
        //for(int i=0;i<L;i++) printf("%d %d '%s'\n", sa[i], lcp[i], s + sa[i]);
    }
    return 0;
}

