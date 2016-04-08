#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

int main() {
	int n, m;
	cin>>n>>m;
	vector<pp> roads;
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		roads.push_back(pp(-c, pii(a, b)));
		roads.push_back(pp(-c, pii(b, a)));
	}
	sort(roads.begin(), roads.end());
	vector<int> dp(n+1, 0);
	queue<pii> q;
	int j=-1;
	int ans=0;
	for(int i=0;i<roads.size();i++) {
		int a = roads[i].second.first;
		int b = roads[i].second.second;
		if(roads[i].first != roads[j+1].first) {
			while(!q.empty()) {
				int v = q.front().first;
				int x = q.front().second;
				dp[v] = max(dp[v], x);
				q.pop();
			}
			j = i;
		}
		q.push(pii(a, 1+dp[b]));
		ans = max(ans, 1+dp[b]);
	}
	cout << ans << endl;
	return 0;
}
