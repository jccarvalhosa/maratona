#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define INF 1000000000
#define MID 400000

int sum[2*MID+1][2][2], ne, ol;
pii disc[2*MID+1][2];

int val(pii a) { return a.first + a.second; }

void change(int i, pii p) {
    int d = val(disc[i][ne]) - val(p);
    if(d>0 || (d==0 && disc[i][ne] > p)) disc[i][ne] = p;
}

int main()
{
    int N, i, j, a, b, total, s, delta[2], smax;
    pii v[400];
    while(scanf("%d", &N) && N) {
        for(total=smax=i=0;i<N;i++) {
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            total += b+a;
            smax += b-a;
            v[i] = mp(a, b);
        }
        ne=0;
        sum[MID][0][ne] = 1;
        delta[ne]=0;
        for(s=i=0;i<N;i++) {
            ol=ne; ne=1-ol;
            a = v[i].second-v[i].first;
            s+=a;
            delta[ne] = min(s, smax-s);
            for(j=MID-delta[ne];j<=MID+delta[ne];j++) {
                sum[j][0][ne] = sum[j][1][ne] = 0;
                disc[j][ne] = mp(INF, INF);
            }
            for(j=MID-delta[ol];j<=MID+delta[ol];j++) {
                if(sum[j][0][ol]) {
                    sum[j+a][0][ne] = sum[j-a][0][ne] = sum[j][1][ne] = 1;
                    change(j, v[i]); 
                }
                if(sum[j][1][ol]) {
                    sum[j+a][1][ne] = sum[j-a][1][ne] = 1;
                    change(j+a, disc[j][ol]);
                    change(j-a, disc[j][ol]);
                }
            }
        }
        if(sum[MID][0][ne]) printf("%d discard none\n", total/2);
        else if(sum[MID][1][ne]) printf("%d discard %d %d\n", (total-val(disc[MID][ne]))/2, disc[MID][ne].first, disc[MID][ne].second);
        else printf("impossible\n");
    }
    return 0;
}
