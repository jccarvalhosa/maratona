#include <cstdio>
#include <iostream>
using namespace std;
#define M 1000003
typedef long long ll;

int n, c[1111][1111];
int v[1111], l[1111], r[1111], child[1111][2];

void insert(int pos, int curr) {
    if(v[pos] > v[curr]) {
        if(child[curr][1] == -1) child[curr][1] = pos;
        else insert(pos, child[curr][1]);
    }
    else {
        if(child[curr][0] == -1) child[curr][0] = pos;
        else insert(pos, child[curr][0]);
    }
}

void dfs(int pos) {
    if(child[pos][0] != -1) {
        int x = child[pos][0];
        dfs(x);
        l[pos] = 1 + l[x] + r[x];
    }
    else l[pos] = 0;
    if(child[pos][1] != -1) {
        int x = child[pos][1];
        dfs(x);
        r[pos] = 1 + l[x] + r[x];
    }
    else r[pos] = 0;
}

int main() {
    for(int i=0;i<=1000;i++) {
        c[0][i]=1;
        for(int j=1;j<=i;j++) c[j][i] = (c[j][i-1] + c[j-1][i-1]) % M;
    }
    int T, m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=1;i<=n;i++) child[i][0] = child[i][1] = -1;
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=2;i<=n;i++) insert(i, 1);
        dfs(1);
        ll ans = c[n][m] % M;
        for(int i=0;i<n;i++) ans = (ans * c[l[i]][l[i] + r[i]]) % M;
        cout<<ans<<endl;
    }
    return 0;
}
