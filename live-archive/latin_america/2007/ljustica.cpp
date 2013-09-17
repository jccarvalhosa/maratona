#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;
    
int main()
{
    int H, R, g, liga[50000];
    int a, b, i, j, total, cont;
    vector<int> grafo[50000];
    vector<pair<int, int> > rel;
    while(scanf("%d%d", &H, &R) && H)
    {
        for(i=0;i<H;i++) liga[i] = 0, grafo[i].clear();
        rel.clear();
        for(i=0;i<R;i++)
        {
            scanf("%d%d", &a, &b);
            a--; b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            rel.push_back(make_pair(a, b));
        }
        g = 1 << 20;
        for(i=0;i<R;i++) g = min(g, max((int)grafo[rel[i].first].size(), (int)grafo[rel[i].second].size()));
        total = 0;
        for(i=0;i<H;i++) if(grafo[i].size() >= g)
        {
            liga[i] = 1;
            total++;
            cont = 0;
            for(j=0;j<grafo[i].size();j++) if(liga[grafo[i][j]]) cont++;
            if(cont != total-1) break;
        }
        if(i == H) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
