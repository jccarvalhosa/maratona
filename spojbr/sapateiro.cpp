#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000

using namespace std;

int N, C, t;
vector<int> cidade[100], cor[500];
int ponte[100][100], adj[100][100];
int grau[100], vis[100], men[100];

void dfs(int v,int p)
{
    int w;
    if(!vis[v])
    {
        vis[v] = ++t;
        men[v] = vis[v];
        for(w=0;w<C;w++) if(adj[v][w])
        {
            if(w != p)
            {
                if(vis[w] && men[v] > vis[w]) men[v] = vis[w];
                else
                {
                    dfs(w,v);
                    if(men[v] > men[w]) men[v] = men[w];
                }
            }
        }
        if((p >= 0) && (men[v] >= vis[v]) && (adj[v][p] == 1)) ponte[p][v] = ponte[v][p] = 1;
    }
}

void bridge()
{
    int i, j;
    t = 0;
    for(i=0;i<C;i++) for(j=0;j<C;j++) ponte[i][j] = 0;    
    for(i=0;i<C;i++) vis[i] = 0;
    for(i=0;i<C;i++) if(!vis[i]) dfs(i,-1);    
}

void go(int v)
{
    vis[v] = 1;
    for(int i=0;i<C;i++) if(adj[v][i] && !vis[i]) go(i);
}

int conexo()
{
    int i, v;
    v = -1;
    for(i=0;i<C;i++)
    {
        if(!grau[i] && !adj[i][i]) vis[i] = 1;
        else vis[i] = 0;
        if(v == -1 && !vis[i]) v = i;
    }
    go(v);
    for(i=0;i<C;i++) if(!vis[i]) return 0;
    return 1;
}

int main()
{
    int K, c, i, j, conf1, conf2, flag, cid, mincid;
    vector<int> impar;
    while(scanf("%d%d", &N, &C) && N)
    {
        impar.clear();
        for(i=0;i<N;i++) cor[i].clear();
        for(i=0;i<C;i++)
        {
            grau[i] = 0;
            cidade[i].clear();
			for(j=0;j<C;j++) adj[i][j] = 0;
        }
        for(i=0;i<C;i++)
        {
            scanf("%d", &K);
            while(K--)
            {
                scanf("%d", &c);
                cor[c].push_back(i);
            }
        }
        for(i=0;i<N;i++)
        {
            if(cor[i].size() == 1)
            {
                conf1 = cor[i][0];
				cor[i].push_back(conf1);
				adj[conf1][conf1]++;
                cidade[conf1].push_back(i);
            }
            else
            {
                conf1 = cor[i][0];
                conf2 = cor[i][1];
				adj[conf1][conf2]++;
				adj[conf2][conf1]++;
                grau[conf1]++; grau[conf2]++;
                cidade[conf1].push_back(i);
                cidade[conf2].push_back(i);
            }
        }
        flag = 1;
        for(i=0;i<C;i++) if(grau[i] % 2 == 1)
        {
            if(impar.size() == 2) 
            {
                printf("-1\n");
                flag = 0;
                break;
            }
            impar.push_back(i);
        }
        if(!flag) continue;
        if(!conexo())
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<C;i++) sort(cidade[i].begin(), cidade[i].end());
        bridge();
        mincid = INF;
        if(impar.size() == 2)
        {
            conf1 = impar[0];
            conf2 = impar[1];
            if(grau[conf1] == 1 && !adj[conf1][conf1]) mincid = cidade[conf1][0];
            for(i=0;i<cidade[conf1].size();i++)
            {
                cid = cidade[conf1][i];
				if(ponte[cor[cid][0]][cor[cid][1]]) continue;
                if(cid < mincid) mincid = cid;
				break;
            }
            if(grau[conf2] == 1 && !adj[conf2][conf2]) mincid = min(mincid, cidade[conf2][0]);
            for(i=0;i<cidade[conf2].size();i++)
            {
                cid = cidade[conf2][i];
				if(ponte[cor[cid][0]][cor[cid][1]]) continue;
                mincid = min(mincid, cid);
				break;
            }
        	printf("%d\n", mincid);
        }
        else for(i=0;i<N;i++) if(!ponte[cor[cid][0]][cor[cid][1]])
		{
			printf("%d\n", i);
			break;
		}
    }
    return 0;
}
