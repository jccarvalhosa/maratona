#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

map<int, int> vis;
pii dp[1111111];

int main() {
    int m, q, a, b, e;
    while(scanf("%d %d", &m, &q) && (m || q)) {
        vis.clear();
        for(int i=0; i<m; i++) {
            scanf("%d", &a);
            if(i) {
                dp[i]=dp[i-1];
                if(vis.count(a)) {
                    int p=vis[a];
                    if(p>dp[i].second) dp[i]=pii(a, p);
                }
            }
            else dp[0]=pii(a, -1);
            vis[a]=i;
        }
        for(int i=0; i<q; i++) {
            scanf("%d %d", &b, &e);
            b--, e--;
            if(dp[e].second>=b) printf("%d\n", dp[e].first);
            else printf("OK\n");
        }
        printf("\n");
    }
    return 0;
}
