#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char v[111];
ll p9[111];
int vis[111];

string solve2(ll n, string s, vector<int> f) {
	string r;
	vector <int> pos;
	int free = f.size();
	for(int i=0;i<10;i++) if(i+'0' != s[0]) pos.push_back(i+'0');
	if(n >= p9[free]) return "-1";
	while(free) {
		ll x = n/p9[free-1];
		r += pos[x];
		n = n - x*p9[free-1];
		free--;
	}
	for(int i=0;i<f.size();i++) {
		int k = f[i];
		for(int j=(1<<k)-1;j<s.size();j+=(1<<(k+1))) s[j] = r[i];
	}
	return s;
}

string solve1(ll n, string s, vector<int> f, int k) {
	vector<int> pos;
	int free = f.size();
	for(int i=1;i<10;i++) {
		if(vis[i] == 0) pos.push_back(i+'0');
	}
	if(n >= (1ll)*pos.size()*p9[free]) return "-1";
	ll x = n/p9[free];
	char c = pos[x];
	for(int i=0;i<s.size();i+=2) s[i] = c;
	return solve2(n-x*p9[free],s,f);
}

int main() {
	ll n;
	string s;
	p9[0] = 1;
	for(int i=1;i<18;i++) p9[i] = p9[i-1]*9;
	while(scanf("%lld", &n) && n) {
		cin >> s;
		int k = 0;
		vector<int> free;
		n--;
		string ret="";
		memset(vis,0,sizeof(vis));
		while(((1<<k)-1) < s.size()) {
			v[k] = '?';
			for(int i=(1<<k)-1;i<s.size();i+=(1<<(k+1))) {
				if(s[i] != '?') {
					if(v[k] == '?' || v[k] == s[i]) {
						v[k] = s[i];
					} else ret = "-1";
				}
			}
			vis[v[k]-'0'] = 1;
			if(v[k] == '?' && k != 0) free.push_back(k);
			else for(int i=(1<<k)-1;i<s.size();i+=(1<<(k+1))) s[i] = v[k];
			k++;
		}
		if(__builtin_popcount(s.size()+1) != 1) ret = "-1";
		if(s[0] == '0') ret = "-1";
		if(ret != "-1") {
			if(v[0] == '?') ret = solve1(n,s,free,k);
			else ret = solve2(n,s,free);
		}
		cout << ret << endl;
	}
	return 0;
}
