#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int transf[100001], vis[100001];

int main() {
	int i, n, s, t, ans;
	cin>>n>>s>>t;
	for(i=1;i<=n;i++) cin >> transf[i];
	memset(vis, 0, sizeof(vis));
	ans=0;
	while(s!=t && !vis[s]) {
		vis[s]=1;
		s=transf[s];
		ans++;
	}
	if(s!=t) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
