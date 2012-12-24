#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
set<pii> s[2];

int V[2], ne, ol, n;
pii v[2][100000];
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, -1, 0, 1, -1, 0,  1, -1};

void check(pii m) {
	int n=0, i, x, y;
	for(i=0;i<8;i++) {
		x=m.first+dx[i];
		y=m.second+dy[i];
		pii aux = mp(x, y);
		if(s[ol].count(aux)) n++;
	}
	if(n == 3 && !s[ne].count(m)) {
		s[ne].insert(m);
		v[ne][V[ne]++] = m;
	}
}

int main() {
	int K, i, j, x, y;
	while(scanf("%d", &V[0]) && V[0]) {
		s[0].clear();
		for(i=0;i<V[0];i++) {
			scanf("%d%d", &x, &y);
			pii p = mp(x, y);
			s[0].insert(p);
			v[0][i] = p;
		}
		scanf("%d", &K);
		ne=0;
		while(K--) {
			ol=ne;
			ne=1-ol;
			s[ne].clear();
			V[ne]=0;
			for(i=0;i<V[ol];i++) {
				n=0;
				pii p = v[ol][i];
				for(j=0;j<8;j++) {
					x=p.first+dx[j];
					y=p.second+dy[j];
					pii aux = mp(x, y);
					if(s[ol].count(aux)) n++;
					else check(aux);
				}
				if((n == 2 || n == 3) && !s[ne].count(p)) {
					s[ne].insert(p);
					v[ne][V[ne]++] = p;
				}
			}
		}
		sort(v[ne], v[ne] + V[ne]);
		printf("%d\n", V[ne]);
		for(i=0;i<V[ne];i++) printf("%d %d\n", v[ne][i].first, v[ne][i].second);
	}
	return 0;
}
