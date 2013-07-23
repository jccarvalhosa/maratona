#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

map<ll, int> m;

int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		m.clear();
		if(s[0]!='[') {
			cout<<0<<endl;
			continue;
		}
		int n=0, d=0, best=0;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='[') d++;
			if(s[i]==']') d--;
			if(s[i]<='9' && s[i]>='0') {
				n++;
				int j;
				for(j=i;s[j]<='9' && s[j]>='0';j++);
				int x;
				istringstream(s.substr(i, j-i+1)) >> x;
				ll v = (1ll<<d) * x;
				if(m.count(v)) m[v]++;
				else m[v]=1;
				best = max(best, m[v]);
				i=j-1;
			}
		}
		cout<<n-best<<endl;
	}
	return 0;
}
