#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int N, nmin, M, match[100][100], best[100], owner[100], ouro[100], worse[6], child[6], needed[6];
int contain[36][36][1000];
vector<string> vm, va, vsub[36];
set<string> subs[36];

void gerasubs(int ind, string s)
{
    string sub;
    for(int tam=1;tam<=s.size();tam++) for(int i=0;i+tam<=s.size();i++)
    {
        sub = s.substr(i, tam);
        vsub[ind].push_back(sub);
        subs[ind].insert(sub);
    }
}

int verify(int n)
{
    int i, j, k, ret=0;
    int used[6];
    for(i=0;i<M;i++)
    {
        if(n & (1 << i)) used[i] = 1;
        else used[i] = 0;
        if(needed[i] && !used[i]) return 1 << 20;
    }
    for(i=0;i<M;i++) worse[i] = 0;
    for(i=0;i<N+M;i++) best[i] = 1 << 20;
    for(i=0;i<N+M;i++)  
    {
        if(i >= N && !used[i-N]) continue;
        for(k=0;k<vsub[i].size();k++)
        {
            for(j=0;j<N+M;j++)
            {
                if(j >= N && !used[j-N]) continue;
                if(j != i && contain[j][i][k]) break;
            }
            if(j == N+M)
            {
                best[i] = vsub[i][k].size();
                break;
            }
        }
        if(i < N) worse[owner[i]] = max(worse[owner[i]], best[i]);
        if(best[i] == 1 << 20 && !used[owner[i]]) return 1 << 20;
        if(n == nmin && best[i] == 1 << 20)
        {
            needed[owner[i]] = 1;
            nmin = 1 << owner[i];
        }
    }
    for(i=0;i<N+M;i++)
    {
        if(i >= N && !used[i-N]) continue;
        ret += best[i];
    }
    for(i=0;i<M;i++) if(n & (1 << i)) ret -= worse[i];
    return ret;
}

int main()
{
    int i, j, k, p, q, sol, nmin;
    string m, a;
    while(scanf("%d", &N) && N)
    {
        vm.clear(); va.clear();
        for(i=0;i<N;i++)
        {
            cin >> m >> a;
            vm.push_back(m);
            vsub[i].clear();
            subs[i].clear();
            gerasubs(i, m);
            for(j=0;j != va.size();j++) if(va[j] == a) break;
            if(j == va.size()) va.push_back(a);
            owner[i] = j;
        }
        M = va.size();
        for(i=0;i<M;i++)
        {
            vm.push_back(va[i]);
            needed[i] = 0;
            vsub[N+i].clear();
            subs[N+i].clear();
            gerasubs(N+i, va[i]);
        }
        for(i=0;i<N+M;i++) for(j=0;j<N+M;j++) for(k=0;k<vsub[i].size();k++) contain[j][i][k] = subs[j].count(vsub[i][k]);
        sol = 1 << 20;
        nmin=0;
        for(i=0; i < 1 << M;i++) sol = min(sol, verify(i));
        printf("%d\n", sol);
    }
    return 0;
}
