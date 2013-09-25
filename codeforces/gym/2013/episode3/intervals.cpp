#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define M 50000

int n, t[55555], a[55555], b[55555], c[55555];
vector<pii> v;
set<int> s;

void update(int v) { 
	for(;v<=M;v+=v&-v) t[v]++; 
}
int query(int v) {
	int ret=0;
	for(;v;v-=v&-v) ret += t[v];
	return ret;
}

int main() {
	cin>>n;
	for(int i=1;i<=M;i++) s.insert(i);
	for(int i=0;i<n;i++) {
		cin>>a[i]>>b[i]>>c[i];
		v.push_back(pii(b[i], i));
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++) {
		int p = v[i].second;
		int used = query(b[p]) - query(a[p]-1);
		c[p] -= used;
		if(c[p] <= 0) continue;
		set<int>::iterator it=s.upper_bound(b[p]); it--;
		for(int j=0;j<c[p];j++) {
			update(*it);
			if(it == s.begin()) s.erase(it);
			else s.erase(it--);
		}
	}
	cout<<query(M)<<endl;
	return 0;
}
