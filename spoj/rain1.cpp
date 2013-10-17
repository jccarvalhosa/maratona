#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct pt { 
	int x, y;
	pt(int x=0, int y=0): x(x), y(y) {}
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	ll operator %(pt p) { return 1ll*x*p.y - 1ll*y*p.x; }
};

ll cross(pt a, pt b, pt c) { return (a-b)%(c-b); }

struct seg { 
	pt a, b; 
	int i;
	bool operator <(const seg &s)const {
		if(a.x > s.a.x) return cross(s.a, a, s.b) < 0;
		else return cross(a, s.a, b) > 0;
	}
};

int main() {
	int T;
	while(cin>>T && !cin.eof())	while(T--) {
		int n;
		cin>>n;
		vector<seg> v(n);
		vector<int> vx, ans(n, 0);
		for(int i=0;i<n;i++) {
			cin>>v[i].a.x>>v[i].a.y>>v[i].b.x>>v[i].b.y;
			v[i].i = i;
			vx.push_back(v[i].a.x);
			vx.push_back(v[i].b.x);
			if(v[i].a.x > v[i].b.x) swap(v[i].a, v[i].b);
		}
		sort(vx.begin(), vx.end());
		vx.erase(unique(vx.begin(), vx.end()), vx.end());
		map<int, int> id;
		for(int i=0;i<vx.size();i++) id[vx[i]] = i;
		vector<vector<pii> > layer(vx.size());
		for(int i=0;i<n;i++) {
			layer[id[v[i].a.x]].push_back(pii(1, i));
			layer[id[v[i].b.x]].push_back(pii(-1, i));
		}
		vector<int> adj(n);
		set<seg> s;
		for(int i=0;i<vx.size();i++) {
			if(i && !s.empty()) ans[s.rbegin()->i] += vx[i] - vx[i-1]; 
			for(int j=0;j<layer[i].size();j++) if(layer[i][j].first == 1) s.insert(v[layer[i][j].second]);
			for(int j=0;j<layer[i].size();j++) {
				int d = layer[i][j].first;
				int k = layer[i][j].second;
				if((d==1 && v[k].a.y < v[k].b.y) || (d==-1 && v[k].b.y < v[k].a.y)) {
					set<seg>::iterator it = s.lower_bound(v[k]);
					if(it != s.begin()) adj[k] = (--it)->i;
					else adj[k]=-1;
				}
			}
			for(int j=0;j<layer[i].size();j++) if(layer[i][j].first == -1) s.erase(v[layer[i][j].second]);
		}
		vector<int> vs, sum(n, 0);
		for(int i=0;i<n;i++) if(adj[i] != -1) sum[adj[i]]++;
		for(int i=0;i<n;i++) if(!sum[i]) vs.push_back(i);
		for(int i=0;i<n;i++) {
			int j = vs[i];
			if(adj[j]==-1) continue;
			ans[adj[j]] += ans[j];
			sum[adj[j]]--;
			if(!sum[adj[j]]) vs.push_back(adj[j]);
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	}
	return 0;
}
