#include <bits/stdc++.h>
using namespace std;

int dx[]={1, 1, -1, -1};
int dy[]={1, -1, -1, 1};
int ans, a[22][22];

int in(int x, int y) { return x>=0 && x<10 && y>=0 && y<10; }

void go(int u, int v, int p)
{
	int du, dv, i;
	if(p>ans) ans=p;
	for(i=0; i<4; i++)
	{
		du=u+dx[i];
		dv=v+dy[i];
		if(in(du, dv) && a[du][dv]==2 && in(du+dx[i], dv+dy[i]) && !a[du+dx[i]][dv+dy[i]])
		{
			a[du][dv]=0;
			go(du+dx[i], dv+dy[i], p+1);
			a[du][dv]=2;
		}
	}
}

int main()
{
	int t, i, j;
	char s[22];
	scanf("%d", &t);
	while(t--)
	{
		for(i=0; i<10; i++)
		{
			scanf("%s", s);
			for(j=0; j<10; j++)
			{
				if(s[j]=='.' || s[j]=='#') a[i][j]=0;
				else if(s[j]=='W') a[i][j]=1;
				else a[i][j]=2;
			}
		}
		ans=0;
		for(i=0; i<10; i++) for(j=0; j<10; j++) if(a[i][j]==1)
		{
			a[i][j]=0;
			go(i, j, 0);
			a[i][j]=1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
