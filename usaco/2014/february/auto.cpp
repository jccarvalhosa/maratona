#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef pair<string, int> psi;

const int N=1e6;
psi s[N];

int main() {
	freopen("auto.in", "r", stdin);
	freopen("auto.out", "w", stdout);
	int n, w, k;
	cin>>w>>n;
	for(int i=0;i<w;i++) {
		cin>>s[i].first;
		s[i].second = i+1;
	}
	sort(s, s+w);
	while(n--) {
		string p;
		cin>>k>>p;
		int pos = lower_bound(s, s+w, psi(p, 0))-s+k-1;
		if(pos >= w) cout<<-1<<endl;
		else if(s[pos].first.size() >= p.size() && s[pos].first.substr(0, p.size()) == p) cout<<s[pos].second<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
