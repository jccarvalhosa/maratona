#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

map<pii, int> m;
pii v[2222];
vector<int> dist[2222];
map<int, int> cnt[2222];

int id(pii p) {
	if(m.count(p)) return m[p];
	int pos = m.size();
	m[p]=pos;
	v[pos]=p;
	return pos;
}

int mod(int x) { return x > 0 ? x : -x; }

pii coef(int dx, int dy) {
	if(dx==0) return pii(0, 1);
	if(dy==0) return pii(1, 0);
	int g = __gcd(mod(dx), mod(dy));
	if(dy < 0) return pii(-dx/g, -dy/g);
	return pii(dx/g, dy/g);
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		pii ang = coef(x1-x2, y1-y2);
		dist[id(ang)].push_back(x1 * ang.second - y1 * ang.first);
	}
	for(int i=0;i<m.size();i++) sort(dist[i].begin(), dist[i].end());
	for(int i=0;i<m.size();i++) {
		for(int j=0;j<dist[i].size();j++) for(int k=j+1;k<dist[i].size();k++) cnt[i][dist[i][k]-dist[i][j]]++;
	}
	long long ans=0;
	for(int i=0;i<m.size();i++) {
		pii ort = coef(v[i].second, -v[i].first);
		if(!m.count(ort)) continue;
		int j = m[ort];
		for(map<int, int>::iterator it=cnt[i].begin(); it != cnt[i].end(); it++) {
			ans += (*it).second * cnt[j][(*it).first];
		}
	}
	cout << ans/2 << endl;
	return 0;
}
