#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct pt {
    ll x, y;
    pt() {}
};

ll dist(pt a, pt b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }

pt p[1000];
ll d[1000][1000];

int main()
{
    int N, sol, i, j, k;
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) scanf("%lld%lld", &p[i].x, &p[i].y);
        for(i=0;i<N;i++) for(j=i;j<N;j++) d[i][j] = d[j][i] = dist(p[i], p[j]);
        sol = k = 0;
        for(i=0;i<N;i++) {
            sort(d[i], d[i]+N);
            k = 1;
            for(j=1;j<N;j++) {
                if(d[i][j] == d[i][j-1]) k++;
                else {
                    sol += k*(k-1)/2;
                    k = 1;
                }
            }
            sol += k*(k-1)/2;
        }
        printf("%d\n", sol);
    }
    return 0;
}
