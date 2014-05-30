#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1e5+10;
int x[N], y[N], t[N], sz;

int query(int p) { int ret=2e9; for(;p;p-=p&-p) ret=min(ret, t[p]); return ret; }
void update(int p, int v) { for(;p<=sz;p+=p&-p) t[p]=min(t[p], v); }

int main() {
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++) {
		cin>>x[i]>>y[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sz = v.size();
	for(int i=1;i<=sz;i++) t[i]=2e9;
	for(int i=0;i<n;i++) {
		int idx = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
		if(query(idx) <= y[i]) {
			cout << "Invisible paper detected" << endl;
			return 0;
		}
		update(idx, y[i]);
	}
	cout << "Well done" << endl;
	return 0;
}
