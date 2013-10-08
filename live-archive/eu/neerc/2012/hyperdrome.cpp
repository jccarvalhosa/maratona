#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define M 333049

vector<ll> e[M];
vector<int> v[M];

void add(ll x) {
	ll b = x%M;
	if(e[b].size() == 1 && e[b][0] == x) {
		v[b][0]++;
		return;
	}
	if(v[b].size() > 1) {
		int pos;
		for(pos=0;pos<e[b].size();pos++) if(e[b][pos]==x) break;
		if(pos != e[b].size()) {
			v[b][pos]++;
			return;
		}
	}
	e[b].push_back(x);
	v[b].push_back(1);
}

int sum(ll x) {
	int b = x%M;
	if(e[b].size() == 1 && e[b][0] == x) return v[b][0];
	if(e[b].size() == 0) return 0;
	int pos;
	for(pos=0;pos<e[b].size();pos++) if(e[b][pos]==x) break;
	if(pos == e[b].size()) return 0;
	return v[b][pos];
}

int main() {
	int n;
	while(scanf("%d", &n)!=EOF) {
		string s;
		cin>>s;
		for(int i=0;i<M;i++) {
			e[i].clear();
			v[i].clear();
		}
		ll x=0, ans=0;
		for(int i=0;i<n;i++) {
			add(x);
			if(islower(s[i])) x ^= 1ll<<(s[i]-'a');
			else if(isupper(s[i])) x ^= 1ll<<(s[i]-'A'+26);
			ans += sum(x);
			for(int j=0;j<52;j++) ans += sum(x ^ (1ll<<j));
		}
		cout << ans << endl;
	}
	return 0;
}
