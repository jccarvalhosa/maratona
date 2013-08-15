#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int N, c, a, nota, b, notb;
int inv[5000], comp[5000], vis[5000], ord[5000];
vector<int> grafo[5000], ginv[5000];
map<string, int> id;

void indices(string s)
{
    string nots;
    if(s[0] == '!') nots = s.substr(1, s.size()-1);
    else nots = "!" + s;
    if(!id.count(s))
    {
        b = id[s] = c++;
        notb = id[nots] = c++;
        inv[b] = notb; inv[notb] = b;
    }
    else
    {
        b = id[s];
        notb = id[nots];
    }
}

void dfs(int v)
{
    vis[v] = 1;
    int i, u;
    for(i=0;i<grafo[v].size();i++)
    {
        u = grafo[v][i];
        if(!vis[u]) dfs(u);
    }
    ord[a++] = v;
}

void dfsinv(int v)
{
    vis[v] = 1;
    comp[v] = a;
    int i, u;
    for(i=0;i<ginv[v].size();i++)
    {
        u = ginv[v][i];
        if(!vis[u]) dfsinv(u);
    }
}

void cfconexas()
{
    int i;
    a = 0;
    for(i=0;i<c;i++) vis[i] = 0;
    for(i=0;i<c;i++) if(!vis[i]) dfs(i);
    a = 0;
    for(i=0;i<c;i++) vis[i] = 0;
    for(i=c-1;i>=0;i--) if(!vis[ord[i]]) dfsinv(ord[i]), a++;
}

int main()
{
    int i, teste=1;
    string s1, s2;
    while(scanf("%d", &N) != EOF)
    {
        printf("Instancia %d\n", teste++);
        for(i=0;i<c;i++) { grafo[i].clear(); ginv[i].clear(); }
        id.clear();
        c = 0;
        for(i=0;i<N;i++)
        {
            cin >> s1 >> s2;
            indices(s1);
            a = b; nota = notb;
            indices(s2);
            grafo[nota].push_back(b);
            grafo[notb].push_back(a);
            ginv[b].push_back(nota);
            ginv[a].push_back(notb);
        }
        cfconexas();
        for(i=0;i<c;i++) if(comp[i] == comp[inv[i]]) break;
        if(i == c) printf("sim\n");
        else printf("nao\n");
        printf("\n");
    }
    return 0;
}
