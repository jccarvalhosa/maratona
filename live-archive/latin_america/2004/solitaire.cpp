#include <stdio.h>
#include <algorithm>

using namespace std;

int N, vis[500], adj[500][500];

int dfs(int v, int cor) {
    vis[v] = cor;
    for(int i=0;i<N;i++) if(adj[v][i]) {
        if(vis[i] == cor) return 0;
        if(!vis[i] && !dfs(i, 3-cor)) return 0;
    }
    return 1;
}

int main()
{
    int n0, n1, n2, n3, deck[500], ord[500], p1[500], p2[500];
    int i, j, k, a, test=1;
    while(scanf("%d", &N) && N) {
        printf("#%d\n", test++);
        for(i=0;i<N;i++) {
            scanf("%d", &a);
            deck[i] = ord[i] = a-1;
        }
        for(i=0;i<N;i++) for(j=0;j<N;j++) adj[i][j] = 0;
        for(i=0;i<N;i++) for(j=i+1;j<N;j++) for(k=j+1;k<N;k++) 
            if(deck[j] > deck[i] && deck[k] > deck[i] && deck[j] > deck[k]) adj[j][k] = adj[k][j] = 1;
        for(i=0;i<N;i++) vis[i] = 0;
        for(i=0;i<N;i++) if(!vis[i] && !dfs(i, 1)) break;
        if(i != N) printf("impossible\n");
        else {
            n0 = N-1;
            n1=n2=-1;
            n3 = 0;
            sort(ord, ord+N);
            while(n3 != N) {
                if(n1!=-1 && p1[n1] == ord[n3]) {
                    n1--; n3++;
                    printf("pop 1\n");
                }
                else if(n2!=-1 && p2[n2] == ord[n3]) {
                    n2--; n3++;
                    printf("pop 2\n");
                }
                else if(vis[n0] == 1) {
                    p1[++n1] = deck[n0--];
                    printf("push 1\n");
                }
                else if(vis[n0] == 2) {
                    p2[++n2] = deck[n0--];
                    printf("push 2\n");
                }
            }
        }
    }
    return 0;
}
