#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;
int mod(int a) { return a>0?a:-a;}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		int n;
		cin>>n;
		vector<vector<pci> > v(n);
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			v[i].push_back(pci(s[0], 1));
			for(int j=1;j<s.size();j++) {
				if(s[j] == s[j-1]) {
					v[i].back().second++;
				}
				else {
					v[i].push_back(pci(s[j], 1));
				}
			}
		}
		int sz = v[0].size();
		int valid=1;
		for(int i=1;i<n;i++) if(v[i].size() != sz) valid=0;
		for(int i=0;i<sz;i++) {
			char c = v[0][i].first;
			for(int j=1;j<n;j++) if(v[j][i].first != c) valid=0;
		}
		if(!valid) printf("Fegla won\n");
		else {
			int ans=0;
			for(int i=0;i<sz;i++) {
				vector<int> vals;
				for(int j=0;j<n;j++) vals.push_back(v[j][i].second);
				sort(vals.begin(), vals.end());
				int mid = vals[n/2];
				for(int j=0;j<n;j++) ans += mod(vals[j]-mid);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
