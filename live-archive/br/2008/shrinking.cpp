#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define pb push_back
#define sz size()
#define INF 1000000000
using namespace std;

struct poly {
    int n, teta;
    poly(int n=0, int teta=0): n(n), teta(teta) {}
};

vector<poly> v;

bool place[10000000];

int main()
{
    int N, ini, MOD, i, j, k, x;
    int arg[10000];
    while(scanf("%d", &N) && N) {
        arg[0] = 0;
        for(i=1;i<=N;i++) {
            scanf("%d", &x);
            arg[i%N] = arg[i-1] + x;
        }
        MOD = arg[0];
        arg[0] = 0;
        memset(place, 0, MOD*sizeof(bool));
        for(i=0;i<N;i++) place[arg[i]] = 1;
        v.clear();
        for(i=3;i<=N;i++) if(MOD % i == 0) v.pb(poly(i, MOD/i));
        ini = 0;
        for(i=0;i<N;i++) {
            for(j=ini;j<v.sz;j++) {
                int pos = arg[i];
                for(k=0;k<v[j].n;k++) {
                    pos = (pos + v[j].teta) % MOD;
                    if(!place[pos]) break;
                }
                if(k == v[j].n) ini = j+1;
            }
        }
        if(ini == 0) printf("-1\n");
        else printf("%d\n", N-v[ini-1].n);
    }
    return 0;
}
