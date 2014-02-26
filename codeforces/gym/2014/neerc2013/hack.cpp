#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N=1e5+10;
int v[N], ac[N];

vector<int> vx;
vector<int> px[N];

vector<int> z[31];
int pz[31];
pii ppz[31];

ll query(int a, int b, int x) {
	if(a>b) return 0;
	int pos = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
	if(pos < vx.size() && vx[pos] == x) {
		ll ret = upper_bound(px[pos].begin(), px[pos].end(), b)-lower_bound(px[pos].begin(), px[pos].end(), a);
		return ret;
	}
	return 0;
}

int main() {
	freopen("hack.in", "r", stdin);
	freopen("hack.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &v[i]);
	for(int i=1;i<=n;i++) ac[i] = ac[i-1]^v[i];
	for(int i=1;i<=n;i++) vx.push_back(ac[i]);
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	for(int i=1;i<=n;i++) px[ lower_bound(vx.begin(), vx.end(), ac[i]) - vx.begin() ].push_back(i);
	for(int i=1;i<=n;i++) for(int j=0;j<31;j++) if((v[i] & (1<<j))==0) z[j].push_back(i);
	ll ans=0;
	for(int ini=1;ini<=n;ini++) {
		for(int i=0;i<31;i++) while(pz[i] != z[i].size() && z[i][pz[i]] < ini) pz[i]++;
		for(int i=0;i<31;i++) {
			if(z[i].size() != pz[i]) ppz[i] = pii(z[i][pz[i]], i);
			else ppz[i] = pii(n+1, i);
		}
		sort(ppz, ppz+31);
		int av=INT_MAX;
		ans += query(ini, ppz[0].first-1, av^ac[ini-1]);
		for(int i=0;i<31;) {
			int j;
			for(j=i;j<31 && ppz[j].first==ppz[i].first;j++) av -= 1<<(ppz[j].second);
			int a = ppz[i].first;
			int b = j==31 ? n : ppz[j].first-1;
			int x = av^ac[ini-1];
			ans += query(a, b, x);
			i=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}
close
