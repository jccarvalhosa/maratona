#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
	
vector<string> in, out;

void go(string s, int pos, int st, string &a, string &b) {
	if(pos==a.size() || st==3) in.push_back(s);
	else for(char c='4';c<='7';c+=3) {
		if(((st&1)==0) && c < a[pos]) out.push_back(s+c);
		else if(((st&2)==0) && c > b[pos]) out.push_back(s+c);
		else go(s+c, pos+1, st | ((c > a[pos]) + 2*(c < b[pos])), a, b);
	}
}

int valid(int n, string a, string b) {
	string s(n, '*');
	for(int i=0;i<a.size();i++) s[i]=a[i];
	for(int i=0;i<b.size();i++) if(s[n-i-1] != '*' && s[n-i-1] != b[i]) return 0;
	return 1;
}

ll count(string a, string b) {
	in.clear(); out.clear();
	go("", 0, 0, a, b);
	ll ans=0;
	for(int i=0;i<in.size();i++) {
		ans += 1ll<<(a.size()-in[i].size());
		for(int j=0;j<out.size();j++) if(valid(a.size(), in[i], out[j])) {
			ans += 1ll<<max(0, (int)a.size() - (int)in[i].size() - (int)out[j].size());
		}
	}
	return ans;
}

int main() {
	int T;
	cin>>T; while(T--) {
		string a, b;
		cin>>a>>b;
		if(a.size() == b.size()) cout << count(a, b) << endl;
		else{
			ll ans = count(a, string(a.size(), '9')) + count("1" + string(b.size()-1, '0'), b);
			for(int i=a.size()+1;i<b.size();i++) ans += 1ll<<i;
			cout << ans << endl;
		}
	}
	return 0;
}
