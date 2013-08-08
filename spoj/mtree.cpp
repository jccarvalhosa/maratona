#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define M 1000000007

vector<pair<int, int> > grafo[100001];
ll dp[100001], sum[111111];
int n, pai[111111];

ll exp(ll x, int e) {
    if(e==0) return 1;
    if(e%2==0) return exp((x*x)%M, e/2);
    return (x*exp(x, e-1))%M;
}
int inv(int x) { return exp(x, M-2); }

void dfs(int v, int p) {
    int i, u, w;
    pai[v] = p;
    sum[v] = 0;
    for(int i=0;i<grafo[v].size();i++) {
        u = grafo[v][i].first;
        w = grafo[v][i].second;
        if(u==p) continue;
        dfs(u, v);
        sum[v] += sum[u]*w + w;
        sum[v] %= M;
    }
}

void go(int v, int w) {
    if(pai[v] == v) dp[v] = sum[v];
    else {
        ll x = (dp[pai[v]] - w - (sum[v]*w)%M+M)%M;
        dp[v] = (sum[v] + w + x*w)%M;
    }
    for(int i=0;i<grafo[v].size();i++) {
        int u = grafo[v][i].first;
        int p = grafo[v][i].second;
        if(u==pai[v]) continue;
        go(u, p);
    }
}

int main() {
    int i, a, b, w;
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        scanf("%d %d %d", &a, &b, &w);
        a--, b--;
        grafo[a].push_back(make_pair(b, w));
        grafo[b].push_back(make_pair(a, w));
    }
    dfs(0, 0);
    go(0, 0);
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans += dp[i];
        ans %= M;
    }
    ans *= inv(2);
    ans %= M;
    cout<<ans<<endl;
    return 0;
}


