#include <cstdio>
#include <iostream>
using namespace std;

int l[7][6], ini[7], c, pos[6];

int vl(int n) { return l[pos[n]][(ini[pos[n]] + n + 2) % 6]; }
int vr(int n) { return l[pos[n]][(ini[pos[n]] + n + 4) % 6]; }

int valid(int n) {
    if(l[pos[n]][(ini[pos[n]] + n + 3)%6] != l[c][(ini[c] + n)%6]) return 0;
    if(n != 0 && (vr(n) != vl(n-1))) return 0;
    if(n == 5 && (vl(5) != vr(0))) return 0;
    return 1;
}

int go(int n, int mask) {
    if(n == 6) return 1;
    for(int i=0;i<7;i++) if((mask & (1<<i)) == 0) {
        for(int j=0;j<6;j++) {
            pos[n] = i;
            ini[i] = j;
            if(valid(n) && go(n+1, mask | (1<<i))) return 1;
        }
    }
    return 0;
}

int main() {
    while(1) {
        if(scanf("%d", &l[0][0]) == EOF) return 0;
        for(int i=1;i<6;i++) cin>>l[0][i];
        for(int i=1;i<7;i++) for(int j=0;j<6;j++) cin>>l[i][j];
        for(c=0;c<7;c++) {
            int j;
            for(j=0;j<6;j++) {
                ini[c] = j;
                if(go(0, 1<<c)) break;
            }
            if(j != 6) break;
        }
        if(c != 7) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
