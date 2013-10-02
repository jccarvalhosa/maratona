#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int M = 444444;

int N, n, ans;
vector<pii> layer[M];
set<int> s[M];
int x[M], y[M], c[M], t[M];

void add(int x, int v) { for(int i=x;i<=N;i+=i&-i) t[i] += v; }
int sum(int a) { 
	int ans=0;
	for(int i=a;i;i-=i&-i) ans += t[i];
	return ans; 
}
int sum(int a, int b) { 
	if(a>b) return 0;
	return sum(b) - sum(a-1); 
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int k;
		cin>>n>>k;
		vector<int> v;
		for(int i=0;i<n;i++) {
			cin>>x[i]>>y[i]>>c[i];
			v.push_back(x[i]);
			v.push_back(y[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		N = v.size();
		map<int, int> id;
		for(int i=0;i<N;i++) id[v[i]]=i+1;
		for(int i=1;i<=N;i++) layer[i].clear();
		for(int i=0;i<n;i++) layer[id[y[i]]].push_back(pii(id[x[i]], c[i]));
		ans=0;
		for(int i=1;i<=k;i++) {
			s[i].clear();
			s[i].insert(0);
			s[i].insert(N+1);
		}
		for(int i=1;i<=N;i++) t[i]=0;
		for(int i=1;i<=N;i++) {
			for(int j=0;j<layer[i].size();j++) {
				int x = layer[i][j].first;
				int c = layer[i][j].second;
				if(s[c].count(x) == 0) {
					set<int>::iterator it = s[c].upper_bound(x);
					int b = *it;
					it--;
					int a = *it;
					ans = max(ans, sum(a+1, b-1));
				}
			}
			for(int j=0;j<layer[i].size();j++) {
				int x = layer[i][j].first;
				int c = layer[i][j].second;
				add(x, 1);
				s[c].insert(x);
			}
		}
		for(int i=1;i<=k;i++) {
			set<int>::iterator it = s[i].begin();
			int old=*it;
			it++;
			while(it != s[i].end()) {
				ans = max(ans, sum(old+1, *it-1));
				old=*it;
				it++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
