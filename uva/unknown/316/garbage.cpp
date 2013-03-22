#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii p[1000];

int main() {
	int T, i, W, N, w, ans, pos;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &W, &N);
		for(i=0;i<N;i++) scanf("%d %d", &p[i].first, &p[i].second);
		ans = w = pos = 0;
		for(i=0;i<N;i++) {
			ans += (p[i].first - pos);
			pos = p[i].first;
			if(w+p[i].second > W) {
				ans += 2*pos;
				w = p[i].second;
			}
			else w += p[i].second;
			if(w == W) {
				ans += pos;
				pos = w = 0;
			}
		}
		printf("%d\n", ans + pos);
	}
	return 0;
}
