#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1300;
int n;
double dp[N][N][2], w[N], c[N];

double go(int i, int m, int k) {
    if(i==n) return k==0;
    double &ret = dp[i][m][k];
    if(ret > -1) return ret;
    ret = max(
        w[i] * go(i+1, m, 1-k) + (1-w[i]) * (1-go(i+1, m, 1-k)),
        w[i] * (1-go(i+1, m, k)) + (1-w[i]) * go(i+1, m, k)
    );

    if(m > 0) ret = max(ret, max(
        c[i] * go(i+1, m-1, k) + (1-c[i]) * (1-go(i+1, m-1, k)),
        c[i] * (1-go(i+1, m-1, 1-k)) + (1-c[i]) * go(i+1, m-1, 1-k)
    ));
    return ret;
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int m;
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>c[i];
            c[i] /= 100;
        }
        for(int i=0;i<n;i++) {
            cin>>w[i];
            w[i] /= 100;
        }
        for(int i=0;i<n;i++) for(int j=0;j<=m;j++) for(int k=0;k<2;k++) dp[i][j][k] = -2;
        printf("Case #%d: %.3lf\n", t, 15000 * (1 - 2*go(0, m, 1)));
    }
    return 0;
}
