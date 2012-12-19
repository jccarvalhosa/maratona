#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, char*> v[10000];
int dp[10000];
char c[10000][1005];

bool find(char *a, int na, char *b, int nb) {
    int i, j;
    for(i=0;i<na-nb+1;i++) {
        for(j=0;j<nb;j++) if(a[i+j] != b[j]) break;
        if(j == nb) return 1;
    }
    return 0;
}

int main() {
    int n, i, j;
    while(scanf("%d",  &n) && n) {
        for(i=0;i<n;i++) {
            scanf("%s", c[i]);
			v[i] = make_pair(strlen(c[i]), c[i]);
            dp[i] = 1;
        }
        sort(v, v+n);
        int ret = 1;
        for(i=n-1;i>=0;i--) for(j=i+1;j<n;j++) {
            if(v[i].first == v[j].first || dp[i] >= dp[j]+1) continue;
            if(find(v[j].second, v[j].first, v[i].second, v[i].first)) {
                dp[i] = max(dp[i], dp[j]+1);
                ret = max(ret, dp[i]);
            }
        }
        printf("%d\n", ret);
    }
}
