#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int vis[1111];
set<pii> s; 
int cmp(int a) { return vis[a]==1; }

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	if(k == n) {
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		vis[a]=1;
	}
	vector<int> a(n);
	for(int i=0;i<n;i++) a[i]=i+1;
	int d = partition(a.begin(), a.end(), cmp) - a.begin();
	vector<int> b(a.begin()+d, a.end());
	a.resize(d);
	vector<pii> ans;
	ans.push_back(pii(a[0], b[0]));
	for(int i=0;i<b.size()-1;i++) ans.push_back(pii(b[i], b[i+1]));
	ans.push_back(pii(b[b.size()-1], a[1]));
	for(int i=1;i<a.size()-1;i++) ans.push_back(pii(a[i], a[i+1]));
	for(int i=0;i<ans.size();i++) s.insert(ans[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
		if(s.count(pii(i, j))) continue;
		if(s.count(pii(j, i))) continue;
		if(i != a[0] && j != a[0] && ans.size() < m) ans.push_back(pii(i, j));
	}
	for(int i=1;i<b.size();i++) if(ans.size() < m) ans.push_back(pii(a[0], b[i]));
	if(ans.size() < m) cout<<-1<<endl;
	else for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}
