#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;
typedef long long ll;

const int N=1e5+3;
pair<string, int> s[N];
map<int, int> id;
int dp[N][2], pre[N], vis[N], r[N], l[N], match[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s[i].first;
		s[i].second=i;
	}
	for(int i=0;i<n;i++) {
		r[i] = i+1;
		l[i] = i-1;
	}
	sort(s, s+n);
	priority_queue<pp> q;
	for(int i=0;i<n-1;i++) {
		int m = min(s[i].first.size(), s[i+1].first.size());
		pre[i] = -1;
		for(int j=0;j<m;j++) if(s[i].first[j] != s[i+1].first[j]) {
			pre[i] = j;
			break;
		}
		if(pre[i] == -1) pre[i]=m;
		q.push(pp(pre[i], pii(i, i+1)));
	}
	ll ans=0;
	while(!q.empty()) {
		pp p = q.top();
		int d = p.first;
		int a = p.second.first;
		int b = p.second.second;
		q.pop();
		if(vis[a] || vis[b]) continue;
		vis[a] = 1;
		vis[b] = 1;
		match[a]=b;
		ans += d;
		if(l[a] == -1 || r[b] == n) continue;
		int la = l[a];
		int rb = r[b];
		r[la] = rb;
		l[rb] = la;
		pre[la] = min(pre[la], min(pre[a], pre[b]));
		q.push(pp(pre[la], pii(la, rb)));
	}
	cout << ans << endl;
	for(int i=0;i<n;i++) if(match[i]) printf("%d %d\n", s[i].second+1, s[match[i]].second+1);
	return 0;
}
