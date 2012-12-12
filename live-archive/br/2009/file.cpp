#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100005
using namespace std;

struct entry {
    int nr[2];
    int p;
};

int sz, line, P[20][MAX], cnt[MAX], v[MAX];
entry L[MAX], al[MAX];
string s;

void sort() {
    int i, j, a, sum, mm = max(200, sz+4);
    memset(cnt, 0, 4*mm);
    for(i=0;i<sz;i++) cnt[L[i].nr[1]+1]++;
    for(i=sum=0;i<mm;i++) a=cnt[i], cnt[i]=sum, sum += a;
    for(i=0;i<sz;i++) al[cnt[L[i].nr[1]+1]++] = L[i];
    for(i=0;i<sz;i++) L[i] = al[i];
    memset(cnt, 0, 4*mm);
    for(i=0;i<sz;i++) cnt[L[i].nr[0]+1]++;
    for(i=sum=0;i<mm;i++) a=cnt[i], cnt[i]=sum, sum += a;
    for(i=0;i<sz;i++) L[cnt[al[i].nr[0]+1]++] = al[i];
}

void makeSA() {
    int i, j, k;
    for(i=0;i<sz;i++) P[0][i] = s[i];
    for(i=j=1;j<sz; j*=2, i++) {
        for(k=0;k<sz;k++) {
            L[k].p = k;
            L[k].nr[0] = P[i-1][k];
            L[k].nr[1] = k+j < sz ? P[i-1][k+j] : -1;
        }
        sort();
        P[i][L[0].p] = 0;
        for(k=1;k<sz;k++) {
            if(L[k].nr[0] == L[k-1].nr[0] && L[k].nr[1] == L[k-1].nr[1]) P[i][L[k].p] = P[i][L[k-1].p];
            else P[i][L[k].p] = P[i][L[k-1].p] + 1;
        }
    }
    line = --i;
    for(k=0;k<sz;k++) v[P[i][k]] = k;
}

int lcp(int a, int b) {
    int i, ret=0;
    for(i=line; i >= 0 && a < sz && b < sz; i--) if(P[i][a] == P[i][b]) {
        ret += min(1<<i, min(sz-a, sz-b));
        a += 1<<i;
        b += 1<<i;
    }
    return ret;
}

int main()
{
    while(cin >> s && s[0] != '*') {
        sz = s.size();
        makeSA();
        int ret=0, last=0, t, i;
        for(i=1;i<sz;i++) {
            t = lcp(v[i-1], v[i]);
            ret += max(0, last-t);
            last = t;
        }
        ret += last;
        cout << ret << endl;
    }
}
