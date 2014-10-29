#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Doll {
	int in, cost;
	bool operator <(const Doll &d)const {
		if(cost > d.cost) return true;
		if(cost < d.cost) return false;
		return in > d.in;
	}
};

const int N=1e3+1;
Doll d[N];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		set<pii> s;
		int ans=0;
		for(int i=0;i<n;i++) {
			int out;
			scanf("%d%d%d", &out, &d[i].in, &d[i].cost);
			s.insert(pii(out, i));
			ans += d[i].in * d[i].cost;
		}
		sort(d, d+n);
		for(int i=0;i<n;i++) {
			set<pii>::iterator it = s.lower_bound(pii(d[i].in, 0));
			if(it == s.begin()) continue;
			it--;
			ans -= d[i].cost * (*it).first;
			s.erase(it);
		}
		cout << ans << endl;
	}
	return 0;
}
