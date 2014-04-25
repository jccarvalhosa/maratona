#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const ll N=210;
const ll M=1e9+7;

ll dp[N][N][N];
ll cont[N][N];
ll n, m;

ll sum(ll li, ll lj, ll ri, ll rj) { 
    li = max(1ll, li);
    lj = max(1ll, lj);
    ri = min(ri, n+m);
    rj = min(rj, n+m);
    return (((cont[ri][rj] - cont[li-1][rj] - cont[ri][lj-1] + cont[li-1][lj-1])%M)+M)%M; 
}

int main() {
    ll t=1, T, s, pi, pj;
    freopen("treasures.in", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> n >> m >> s >> pi >> pj;
        cout << "Case " << t++ << ": ";
        for(ll i=2;i<=n+m;i++) for(ll j=2;j<=n+m;j++) dp[i][j][1]=0;
        for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin >> dp[i-j+m+1][i+j][1];
        for(ll tt=2;tt<=s;tt++) {
            for(ll i=2;i<=n+m;i++) {
                ll ss = 0;
                for(ll j=2;j<=n+m;j++) {
                    ss = (ss + dp[i][j][tt-1])%M;
                    cont[i][j] = (cont[i-1][j] + ss)%M;
                }
            }
            for(ll i=2;i<=n+m;i++) for(ll j=2;j<=n+m;j++) {
				int x = i+j-m-1;
				int y = j-i+m+1;
				if(x&1 || y&1) dp[i][j][tt]=0;
				else {
					x>>=1; y>>=1;
					if(x < 1 || x > n || y < 1 || y > m) dp[i][j][tt]=0;
					else dp[i][j][tt] = sum(i-tt+1, j-tt+1, i+tt-1, j+tt-1);
				}
            }
        }
        cout << dp[pi-pj+m+1][pi+pj][s] << endl;
    }
    return 0;
}
