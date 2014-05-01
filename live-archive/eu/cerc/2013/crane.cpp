#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int v[11111], pos[11111];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++) {
			scanf("%d", &v[i]); v[i]--;
			pos[v[i]]=i;
		}
		vector<pii> ans;
		for(int i=0;i<n;i++) {
			while(pos[i] != i) {
				int d = (pos[i]-i+1)>>1;
				int p = pos[i];
				ans.push_back(pii(p-2*d+1, p));
				for(int j=0;j<d;j++) {
					swap(v[p-j], v[p-j-d]);
					pos[v[p-j]] = p-j;
					pos[v[p-j-d]] = p-j-d;
				}
			}
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) printf("%d %d\n", ans[i].first+1, ans[i].second+1);
	}
	return 0;
}
