#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pp;

const int N=5e5+10;
int t[N];
vector<int> vx;
pii v[N], o[N], c[N];
map<pii, int> m;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		scanf("%d%d", &v[i].first, &v[i].second);
		o[i] = pii(v[i].first, i);
		c[i] = pii(v[i].second, i);
		vx.push_back(v[i].first);
		vx.push_back(v[i].second);
	}
	sort(o, o+n);
	sort(c, c+n);
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	set<pp> s;
	int po=0, pc=0;
	for(int i=0;i<vx.size();i++) {
		int x = vx[i];
		if(s.size() == 1) t[(*s.begin()).second] += vx[i]-vx[i-1];
		if(s.size() == 2) {
			int a = (*s.begin()).second;
			int b = (*++s.begin()).second;
			if(a>b) swap(a, b);
			m[pii(a, b)] += vx[i]-vx[i-1];
		}
		while(pc != n && c[pc].first == vx[i]) {
			int pos = c[pc++].second;
			s.erase(pp(v[pos], pos));
		}
		while(po != n && o[po].first == vx[i]) {
			int pos = o[po++].second;
			s.insert(pp(v[pos], pos));
		}
	}
	priority_queue<int> q;
	for(int i=0;i<n;i++) q.push(t[i]);
	int ans=q.top();
	q.pop();
	ans+=q.top();
	for(map<pii, int>::iterator it=m.begin();it!=m.end();it++) ans = max(ans, it->second + t[it->first.first] + t[it->first.second]);
	cout<<ans<<endl;
	return 0;
}
