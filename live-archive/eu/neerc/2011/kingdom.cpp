#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> g[111111];
vector<pii> ans;
queue<int> q;

void dfs(int v, int p) {
    if(g[v].size() == 1) {
        if(q.size() == 2) {
            ans.push_back(pii(v, q.front()));
            q.pop();
        }
        else q.push(v);
    }
    for(int i=0;i<g[v].size();i++) if(g[v][i] != p) dfs(g[v][i], v);
}

int main() {
    while(cin>>n && !cin.eof()) {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) {
            int a, b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int r=0;
        for(int i=1;i<=n;i++) if(g[i].size() != 1) { r=i; break; }
        ans.clear();
        dfs(r, 0);
        if(q.size() == 1) {
            ans.push_back(pii(r, q.front()));
            q.pop();
        }
        if(q.size() == 2) {
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            ans.push_back(pii(a, b));
        }
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
