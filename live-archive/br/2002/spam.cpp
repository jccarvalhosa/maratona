#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, vis[100];
vector<int> adj[20];

void dfs(int v) {
    vis[v] = 1;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(!vis[u]) dfs(u);
    }
}

int main()
{
    string s[100][3], nome[100];
    int i, j, k, a[100], b[100], c[100];
    int val[100][20];
    while(scanf("%d", &N) && N) {
        for(i=0;i<N;i++) adj[i].clear();
        for(i=0;i<N;i++) while(scanf("%d", &k) && k) adj[i].push_back(k-1);
        M=0;
        while(scanf("%d", &a[M]) && a[M]) {
            a[M]--;
            scanf("%d%d", &b[M], &c[M]);
            cin >> s[M][0] >> s[M][1] >> s[M][2];
            M++;
        }
        for(i=0;i<N;i++) cin >> nome[i];
        for(i=0;i<M;i++) {
            for(j=0;j<N;j++) vis[j]=0;
            dfs(a[i]);
            for(j=0;j<N;j++) {
                if(vis[j]) val[i][j] = adj[j].size();
                else val[i][j] = 0;
            }
        }
        for(i=0;i<N;i++) {
            cout << nome[i] << ": ";
            for(j=0;j<M;j++) {
                if(val[j][i] < b[j]) cout << s[j][0];
                else if(val[j][i] < c[j]) cout << s[j][1];
                else cout << s[j][2];
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
