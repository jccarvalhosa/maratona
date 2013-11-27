#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int M = 222222;
vector<pll> v[M];
ll a[M], b[M];

int main() {
	int n, m, p;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<n;i++) v[i%p].push_back(pll(a[i], i+1));
	vector<ll> bb(b, b+m);
	sort(bb.begin(), bb.end());
	map<ll, ll> id;
	bb.erase(unique(bb.begin(), bb.end()), bb.end());
	for(int i=0;i<bb.size();i++) id[bb[i]]=i;
	vector<int> H(bb.size(), 0);
	vector<int> h(bb.size(), 0);
	for(int i=0;i<m;i++) H[id[b[i]]]++;
	vector<ll> ans;
	int d=0;
	for(int i=0;i<H.size();i++) if(H[i] != h[i]) d++;
	for(int i=0;i<p;i++) {
		int jj=0;
		for(int j=0;jj<v[i].size();j++) {
			if(j<v[i].size() && id.count(v[i][j].first)) {
				int idj = id[v[i][j].first];
				if(h[idj]==H[idj]) d++;
				h[idj]++;
				if(h[idj]==H[idj]) d--;
			}
			if(j>=v[i].size() || j-jj+1 > m) {
				if(id.count(v[i][jj].first)) {
					int idj = id[v[i][jj].first];
					if(h[idj]==H[idj]) d++;
					h[idj]--;
					if(h[idj]==H[idj]) d--;
				}
				jj++;
			}
			if(d==0) ans.push_back(v[i][jj].second);
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
