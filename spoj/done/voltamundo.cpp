#include <stdio.h>
#include <algorithm>

using namespace std;

int N, T, smax, i, j, k, lini, l, delta, g, gini, x, p1, p2, start;
int vis[600][200], soma[600][200], s[200], entrada[500][2];
int lat[362][600], latcount[362];

int mod(int a) { return a > 0 ? a : -a; }
int max(int a, int b) { return a > b ? a : b;}

void go()
{
	for(i=0;i<=T;i++) for(j=0;j<=180;j++) soma[i][j] = vis[i][j] = 0;
	for(i=0;i<=360;i++) if(latcount[i]) sort(lat[i], lat[i] + latcount[i]);
	vis[0][lini] = 1;
	for(i=0;i<=360;i++) if(latcount[i])
	{
		for(j=T;j>=0;j--) 
		{
			for(x=0;x<=180;x++) s[x] = soma[j][x];
			for(k=0;k<=180;k++) if(vis[j][k])
			{
				for(p1=0; p1 < latcount[i]; p1++)
				{
					x = 1;
					start = mod(lat[i][p1] - k);
					for(p2=p1; p2 < latcount[i]; p2++)
					{
						delta =  start + mod(lat[i][p2] - lat[i][p1]);
						if(j + delta > T) break;
						if(!delta) soma[j][lat[i][p2]] = max(s[lat[i][p2]], s[k]+x);
						else soma[j+delta][lat[i][p2]] = max(soma[j+delta][lat[i][p2]], s[k]+x);
						vis[j+delta][lat[i][p2]] = 1;
						x++;
					}
				}
				for(p1 = latcount[i] - 1; p1 >= 0; p1--)
				{
					x = 1;
					start = mod(lat[i][p1] - k);
					for(p2=p1; p2 >=0; p2--)
					{
						delta =  start + mod(lat[i][p2] - lat[i][p1]);
						if(j + delta > T) break;
						if(!delta) soma[j][lat[i][p2]] = max(s[lat[i][p2]], s[k]+x);
						else soma[j+delta][lat[i][p2]] = max(soma[j+delta][lat[i][p2]], s[k]+x);
						vis[j+delta][lat[i][p2]] = 1;
						x++;
					}
				}
			}
		}
	}
	for(j=0;j<=T;j++) for(k=0;k<=180;k++) 
	{
		delta = mod(lini - k);
		if(vis[j][k] && (j + delta <= T)) smax = max(smax, soma[j][k]);
	}
}

int main()
{
	scanf("%d%d", &N, &T);
	smax = 0;

	scanf("%d%d", &lini, &gini);
	lini += 89;
	for(i=0;i<N-1;i++)
	{
		scanf("%d%d", &l, &g);
		l += 89;
		entrada[i][0] = l;
		entrada[i][1] = g;
	}
	for(i=0;i<N-1;i++)
	{
		l = entrada[i][0];
		g = entrada[i][1];
		if(g > gini) lat[g - gini][latcount[g-gini]++] = l;
		else if(g < gini) lat[360 + g - gini][latcount[360 + g - gini]++] = l;
		else if(l > lini) lat[360 + g - gini][latcount[360 + g - gini]++] = l;
		else lat[g - gini][latcount[g - gini]++] = l;
	}
	go();
	for(i=0;i<=360;i++) latcount[i] = 0;
	for(i=0;i<N-1;i++)
	{
		l = entrada[i][0];
		g = entrada[i][1];
		if(g > gini) lat[g - gini][latcount[g-gini]++] = l;
		else if(g < gini) lat[360 + g - gini][latcount[360 + g - gini]++] = l;
		else if(l < lini) lat[360 + g - gini][latcount[360 + g - gini]++] = l;
		else lat[g - gini][latcount[g - gini]++] = l;
	}
	go();
	printf("%d\n", smax);
	return 0;
}


