#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, m, c;
vector<int> adj[3333];
int vis[3333];

void dfs(int v) {
    vis[v]=1;
    c++;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(!vis[u]) dfs(u);
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) adj[i].clear();
        for(int i=0;i<m;i++) {
            int a, b;
            cin>>a>>b; a--; b--;
            adj[a].push_back(b);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) vis[j]=0;
            c=0;
            dfs(i);
            ans += c-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
