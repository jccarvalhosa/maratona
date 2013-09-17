#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz size()
#define INF 1000000000
using namespace std;
int mod(int a) { return a > 0 ? a : -a; }

vector<int> v[10000];
int d[1001][10000];

int main()
{
    int N, i, j, k, best, sum;
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) {
            v[i].clear();
            scanf("%d", &j);
            while(j--) {
                scanf("%d", &k);
                v[i].pb(k);
            }
            sort(v[i].begin(), v[i].end());
            k = 0;
            for(j=0;j<=1000;j++) {
                while(k != v[i].sz && v[i][k] < j) k++;
                d[j][i] = mod(v[i].sz - 2*k);
            }
        }
        best = INF;
        for(i=0;i<=1000;i++) {
            sum = 0;
            for(j=0;j<N;j++) sum += d[i][j];
            best = min(best, sum);
        }
        printf("%d\n", best);
    }
    return 0;
}
