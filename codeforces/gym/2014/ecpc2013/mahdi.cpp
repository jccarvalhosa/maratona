#include <bits/stdc++.h>
using namespace std;

vector <int> pos[26];

int main()
{
	int t=1, T, a, l, m, q;
	char ch;
	freopen("mahdi.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		long long c;
		for(int i=0;i<26;i++) pos[i].clear();
		scanf(" %c %d %d %d", &ch, &l, &m, &a);
		c = ch-'a';
		pos[c].push_back(0);
		for(int i=1;i<l;i++) {
			c = (c*m + (1ll)*i*a)%26;
			pos[c].push_back(i);
		}
		scanf("%d", &q);
		printf("Case %d:\n", t++);
		for(int i=0;i<q;i++) {
			scanf(" %c %d %d %d", &ch, &l, &m, &a);
			c = ch-'a';
			int ok = 1;
			int cur;
			if(!pos[c].size()) ok = 0;
			else cur = pos[c][0];
			if(ok) {
				for(int j=1;j<l;j++) {
					c = (c*m + (1ll)*j*a)%26;
					int pp = (upper_bound(pos[c].begin(), pos[c].end(), cur)-pos[c].begin());
					if(pp >= pos[c].size()) ok = 0;
					else cur = pos[c][pp];
				}
			}
			printf("%s\n", (ok ? "BRAVO" : "REPEAT"));
		}
	}
	return 0;
}

