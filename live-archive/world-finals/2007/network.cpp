#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int inf = (int)1e9;
int sz[6], msg[1111], ini[1111], fin[1111];

int main() {
	int n, m, tc=1;
	while(scanf("%d%d", &n, &m) && n) {
		int order[] = {0,1,2,3,4};
		for(int i=0;i<n;i++) scanf("%d", &sz[i]);
		for(int i=0;i<m;i++) {
			scanf("%d %d %d", &msg[i], &ini[i], &fin[i]);
			msg[i]--;
		}
		int ans = inf;
		set<pair<int,int> > inter[6];
		do {
			int k = 0;
			int buf = 0;
			int i=0;
			int mbuf = 0;
			while(k < n) {
				int curmsg = order[k];
				int size = 0;
				while(1) {
					set <pair<int,int> >::iterator it = inter[curmsg].begin();
					while((*it).first == size+1) {
						buf -= ((*it).second-(*it).first+1);
						size = (*it).second;
						inter[curmsg].erase(it);
						it = inter[curmsg].begin();
					}
					if(size == sz[curmsg]) break;
					if(msg[i] == curmsg) {
						if(ini[i] == size+1) {
							size = fin[i];
							it = inter[curmsg].begin();
							while((*it).first == size+1) {
								buf -= ((*it).second-(*it).first+1);
								size = (*it).second;
								inter[curmsg].erase(it);
								it = inter[curmsg].begin();
							}
						} else {
							buf += fin[i]-ini[i]+1;
							mbuf = max(mbuf,buf);
							inter[msg[i]].insert(make_pair(ini[i],fin[i]));
						}
					} else {
						buf += fin[i]-ini[i]+1;
						mbuf = max(mbuf,buf);
						inter[msg[i]].insert(make_pair(ini[i],fin[i]));
					}
					i++;
					if(size == sz[curmsg]) break;
				}
				k++;
			}
			ans = min(ans,mbuf);
		}while(next_permutation(order,order+n));
		printf("Case %d: %d\n\n", tc++, ans);
	}
	return 0;
}
