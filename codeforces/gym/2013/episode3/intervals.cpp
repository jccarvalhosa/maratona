#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define M 50000

int n, val[55555], t[55555], a[55555], b[55555], c[55555];
vector<pii> v;

int update(int v) {
	if(val[v]==1) return 0;
	val[v]=1;
	for(;v<=M;v+=v&-v) t[v]++;
	return 1;
}

int query(int v) {
	int ret=0;
	for(;v;v-=v&-v) ret += t[v];
	return ret;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i]>>b[i]>>c[i];
		v.push_back(pii(b[i], i));
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++) {
		int p = v[i].second;
		c[p] -= query(b[p]) - query(a[p]-1);
		for(int j=0;c[p]>0;j++) if(update(b[p]-j)) c[p]--;
	}
	cout<<query(M)<<endl;
	return 0;
}
