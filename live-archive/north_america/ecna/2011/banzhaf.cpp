#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

ll sss[111];
int vis[111];
vector <int> v;

int main()
{
	int n, q, m, w, t=1;;
	while(scanf("%d%d", &n, &q) && q)
	{
		for(int i=0;i<n;i++)
		{
			cin >> w >> m;
			for(int i=0;i<m;i++) v.push_back(w);
		}
		memset(vis,0,sizeof(vis));
		printf("Case %d:",t++);
		for(int i=0;i<v.size();i++)
		{
			int a = q-v[i], b=q;
			ll r = 0;
			memset(sss,0,sizeof(sss));
			sss[0] = 1;
			if(!vis[v[i]])
			{
				for(int j=0;j<v.size();j++) if(j != i) for(int k=60;k>=0;k--) if(sss[k] > 0) sss[k+v[j]] += sss[k];
				for(int j=a;j<b;j++) r += sss[j];
				vis[v[i]] = 1;
				printf(" %lld", r);
			}
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
