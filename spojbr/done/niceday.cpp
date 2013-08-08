#include <cstdio>
#include <algorithm>
#include <set>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
typedef pair<int , pii> pip;

pip c[100000];
set<pii> s;
set<pii>::iterator it;

int main() {
	int N, t, i, x, y, z, ans;
	scanf("%d", &t);
	while(t--) {
		s.clear();
		scanf("%d", &N);
		for(i=0;i<N;i++){
			scanf("%d%d%d", &x, &y, &z); 
			c[i] = pip(x, pii(y, z));
		}
		sort(c, c+N);
		ans = 1;
		s.insert(c[0].second);
		for(i=1;i!=N;i++) {
			pii p = c[i].second;
			it = s.lower_bound(p);
			if(it == s.begin() || p.second < (--it)->second) {
				ans++;
				s.insert(p);
				it = s.upper_bound(p);
				while(it != s.end()) {
					if(it->second > p.second) s.erase(it++);
					else break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
