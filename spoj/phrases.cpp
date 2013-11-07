#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int n;
string s[11];
const ll C = (ll)1e9 + 7;
const int M = 10001;

ll pot[M];

int valid(int m) {
	vector<vector<ll> > ans(n);
	for(int i=0;i<n;i++) {
		if(s[i].size() < m) return 0;
		vector<ll> hash(s[i].size(), 0);
		for(int j=0;j<m;j++) hash[0] += s[i][j] * pot[m-j-1];
		for(int j=1;;j++) {
			if(j+m-1 >= s[i].size()) break;
			hash[j] = (hash[j-1] - s[i][j-1]*pot[m-1])*C + s[i][j+m-1];
		}
		set<ll> vis;
		for(int j=s[i].size()-1;j>=0;j--) {
			int k = j+m;
			if(j+2*m-1 >= s[i].size()) continue;
			vis.insert(hash[k]);
			if(vis.count(hash[j])) ans[i].push_back(hash[j]);
		}
	}
	for(int i=0;i<n;i++) {
		sort(ans[i].begin(), ans[i].end());
		ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end());
	}
	for(int i=0;i<ans[0].size();i++) {
		int j;
		for(j=1;j<n;j++) if(!binary_search(ans[j].begin(), ans[j].end(), ans[0][i])) break;
		if(j==n) return 1;
	}
	return 0;
}

int search() {
	int i=0, f=10001;
	while(i<f-1) {
		int m=(i+f)/2;
		if(valid(m)) i=m;
		else f=m;
	}
	return i;
}

int main() {
	pot[0]=1;
	for(int i=1;i<M;i++) pot[i] = C*pot[i-1];
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>s[i];
		cout << search() << endl;
	}
	return 0;
}
