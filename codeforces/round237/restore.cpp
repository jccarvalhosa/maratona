#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, k;
const int N=1e5+10;
vector<int> v[N];
vector<pii> ans;

int solve() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		int d;
		cin>>d;
		if(d < 0 || d >= n) return 0;
		v[d].push_back(i);
	}
	if(k==1) {
		if(n==2 && v[0].size()==1 && v[1].size()==1) {
			ans.push_back(pii(v[0][0], v[1][0]));
			return 1;
		}
		return 0;
	}
	if(v[0].size() != 1) return 0;
	for(int d=1;d<n;d++) {
		int pos=0, c=d!=1;
		for(int i=0;i<v[d].size();i++) {
			if(pos >= v[d-1].size()) return 0;
			ans.push_back(pii(v[d][i], v[d-1][pos]));
			c++;
			if(c==k) {
				c = d!=1;
				pos++;
			}
		}
	}
	return 1;
}

int main() {
	if(solve()) {
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	else cout<<-1<<endl;
	return 0;
}
