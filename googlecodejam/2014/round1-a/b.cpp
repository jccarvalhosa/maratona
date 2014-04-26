#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1111];

int solve(int u, int p) {
    int sz = adj[u].size();
    if(p != -1) sz -= 1;
    if(sz < 2) return 1;
    else {
        vector <int> val;
        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];
            if(v == p) continue;
            val.push_back(solve(v,u));
        }
        sort(val.begin(),val.end(),greater<int>());
        return val[0]+val[1]+1;
    }
}

int main() {
    int T;
    cin >> T;
    int t = 1;
    while(T--) {
        int n;
        cin >>n;
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int r = 0;
        for(int i=0;i<n;i++) {
            r = max(r, solve(i,-1));
        }
        printf("Case #%d: %d\n", t++, n-r);
    }
    return 0;
}
