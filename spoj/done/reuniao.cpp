#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int d[100][100], maximo;

int main()
{
    int n, m, w, u, v, i, j, k, minimo;
    scanf("%d %d", &n, &m);
    minimo=1000000000;
    maximo=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=1000000000;
        }
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if(u!=v)
        {
            if(d[u][v]>w)
                d[u][v]=d[v][u]=w;
        }
    }
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    for(i=0; i<n; i++)
    {
        maximo=0;
        for(j=0; j<n; j++)
            maximo=max(maximo, d[i][j]);
        minimo=min(minimo, maximo);
	}
    printf("%d\n", minimo); 
    return 0;    
}

