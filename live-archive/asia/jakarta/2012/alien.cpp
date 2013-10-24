#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

map<int, int> id;
set<pii> s[111111];
int N;

void add(int x, int y, int i) { 
	if(!id.count(x)) id[x] = N++;
	s[id[x]].insert(pii(y, i)); 
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cout << "Case #" << t << ":" << endl;
		int n, q;
		int w, h;
		scanf("%d %d %d %d", &n, &q, &w, &h);
		id.clear();
		for(int i=0;i<N;i++) s[i].clear();
		N=0;
		vector<pii> ans(n+1);
		for(int i=1;i<=n;i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			ans[i] = pii(x, y);
			add(x-y, x+y, i);
		}
		while(q--) {
			int E, a, b, c, d, e, f, x, y;
			scanf("%d %d %d %d %d %d %d %d %d", &x, &y, &E, &a, &b, &c, &d, &e, &f);
			int minx = x-y - E, maxx = x-y + E;
			int miny = x+y - E, maxy = x+y + E;
			map<int, int>::iterator it = id.lower_bound(minx);
			vector<pair<pii, int> > v;
			while(it != id.end() && it->first <= maxx) {
				int idx = it->second;
				set<pii>::iterator its = s[idx].lower_bound(pii(miny, 0));
				while(its != s[idx].end() && its->first <= maxy) {
					int x = it->first;
					int y = its->first;
					int pos = its->second;
					int nx = (1ll*(x+y)/2*a + 1ll*(y-x)/2*b + 1ll*pos*c) % w;
					int ny = (1ll*(x+y)/2*d + 1ll*(y-x)/2*e + 1ll*pos*f) % h;
					ans[pos] = pii(nx, ny);
					v.push_back(make_pair(pii(nx-ny, nx+ny), pos));
					s[idx].erase(its++);
				}
				if(s[idx].size() == 0) id.erase(it++);
				else it++;
			}
			for(int i=0;i<v.size();i++)	add(v[i].first.first, v[i].first.second, v[i].second);
		}
		for(int i=1;i<=n;i++) cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
