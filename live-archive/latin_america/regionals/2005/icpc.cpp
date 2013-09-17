#include <stdio.h>
#include <vector>

using namespace std;

int trab[1000][1000], tardep[1000][1000], dep[1000];
int salario[1000], valor[1000];
vector<int> grafo[1000], ginv[1000], topsort;

int main()
{
    int T, E, i, j, k, a, b, c;
    int BS[1000], nd, ne;
    while(scanf("%d%d", &T, &E) != EOF && (T || E))
    {
        printf("*****\n");
        for(i=0;i<T;i++)
        {
            grafo[i].clear();
            ginv[i].clear();
            dep[i] = 0;
            for(j=0;j<T;j++) tardep[i][j] = 0;
        }
        for(i=0;i<E;i++) for(j=0;j<T;j++) trab[i][j] = 0;
        for(i=0;i<T;i++)
        {
            scanf("%d%d%d", &BS[i], &nd, &ne);
            for(j=0;j<nd;j++)
            {
                scanf("%d", &a); a--;
                grafo[i].push_back(a);
                ginv[a].push_back(i);
                dep[a]++;
                tardep[a][i] = 1;
            }
            for(j=0;j<ne;j++)
            {
                scanf("%d", &a); a--;
                trab[a][i] = 1;
            }
        }
        topsort.clear();
        for(i=0;i<T;i++) if(!dep[i]) topsort.push_back(i);
        for(i=0;i<T;i++)
        {
            a = topsort[i];
            for(j=0;j<grafo[a].size();j++)
            {
                b = grafo[a][j];
                dep[b]--;
                if(!dep[b]) topsort.push_back(b);
            }
        }
        for(i=0;i<T;i++)
        {
            a = topsort[i];
            for(j=0;j<ginv[a].size();j++)
            {
                b = ginv[a][j];
                for(k=0;k<ginv[b].size();k++)
                {
                    c = ginv[b][k];
                    if(!tardep[a][c])
                    {
                        tardep[a][c] = 1;
                        ginv[a].push_back(c);
                    }
                }
            }
        }
        for(i=0;i<T;i++) valor[i] = BS[i];
        for(i=T-1;i>=0;i--)
        {
            a = topsort[i];
            for(j=0;j<grafo[a].size();j++) valor[a] += valor[grafo[a][j]];
        }
        for(i=0;i<E;i++)
        {
            salario[i] = 0;
            for(j=0;j<T;j++) if(trab[i][j])
            {
                for(k=0;k<ginv[j].size();k++)
                {
                    c = ginv[j][k];
                    if(trab[i][c]) break;
                }
                if(k == ginv[j].size()) salario[i] += valor[j];
            }
            printf("%d %d\n", i+1, salario[i]);
        }
    }
    return 0;
}
