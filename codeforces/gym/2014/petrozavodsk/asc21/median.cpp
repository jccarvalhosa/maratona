#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, string> pls;

int n;
char var[6];
ll t[6];
map<char, int> pos;
map<ll, string> m;
vector<pls> v;

int get(char c, int mask) {
	if(c=='0') return 0;
	if(c=='1') return 1;
	return ( mask & (1 << pos[c]) ) > 0;
}

int eval(string s, int mask) {
	while(1) {
		int has=0, pos;
		for(int i=0;i<s.size();i++) if(s[i]=='!') {
			has=1;
			pos=i;
			break;
		}
		if(!has) break;
		s.replace(pos, 2, string(1, '1' - get(s[pos+1], mask)));
	}
	while(1) {
		int has=0, pos;
		for(int i=0;i<s.size();i++) if(s[i]=='&') {
			has=1;
			pos=i;
			break;
		}
		if(!has) break;
		s.replace(pos-1, 3, string(1, '0' + (get(s[pos-1], mask) & get(s[pos+1], mask))));
	}
	while(1) {
		int has=0, pos;
		for(int i=0;i<s.size();i++) if(s[i]=='|') {
			has=1;
			pos=i;
			break;
		}
		if(!has) break;
		s.replace(pos-1, 3, string(1, '0' + (get(s[pos-1], mask) | get(s[pos+1], mask))));
	}
	return get(s[0], mask);
}

int solve(string s, int mask) {
	while(1) {
		int ini, fim, has = 0;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='(') {
				ini=i;
				has=1;
			}
			if(s[i]==')') {
				fim=i;
				break;
			}
		}
		if(!has) break;
		int v = eval(s.substr(ini+1, fim-ini-1), mask);
		s.replace(ini, fim-ini+1, string(1, '0' + v));
	}
	return eval(s, mask);
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) if(islower(s[i]) && !pos.count(s[i])) {
		pos[s[i]]=n;
		var[n++]=s[i];
	}

	for(int i=0;i<1<<n;i++) for(int j=0;j<n;j++) if(i & (1<<j)) t[j] += 1ll<<i;
	for(int j=0;j<n;j++) {
		m[t[j]] = string(1, 'a'+j);
		v.push_back(pls(t[j], m[t[j]]));
	}

	while(1) {
		map<ll, string> extra;
		for(int a=0;a<v.size();a++) for(int b=a+1;b<v.size();b++) for(int c=b+1;c<v.size();c++) {
			ll table=0;
			for(int i=0;i<1<<n;i++) {
				ll v1 = v[a].first & (1ll<<i);
				ll v2 = v[b].first & (1ll<<i);
				ll v3 = v[c].first & (1ll<<i);
				if((v1 && v2) || (v1 && v3) || (v2 && v3)) table += 1ll<<i;
			}
			if(!m.count(table)) extra[table] = "<" + v[a].second + v[b].second + v[c].second + ">";
		}
		if(extra.size() == 0) break;
		for(map<ll, string>::iterator it = extra.begin(); it != extra.end(); it++) {
			m[(*it).first] = (*it).second;
			v.push_back(pls((*it).first, (*it).second));
		}
	}

	ll table=0;
	for(int i=(1<<n)-1;i>=0;i--) table = table*2 + solve(s, i);
	string ans = m[table];
	for(int i=0;i<n;i++) replace(ans.begin(), ans.end(), (char)('a'+i), var[i]);
	cout << ans << endl;
	return 0;
}
