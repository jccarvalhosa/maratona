#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const int N=111;
ll d, c[N], p[N];
int grau;

int valid(int x) { 
	p[0]=1;
	for(int i=1;i<=grau;i++) p[i]=p[i-1]*x%d;
	ll sum=0;
	for(int i=0;i<=grau;i++) sum += c[i]*p[i]%d;
	return sum%d==0;
}

int solve() {
	for(int i=0;i<=grau;i++) if(!valid(i)) return 0;
	return 1;
}

int main() {
	string s;
	int t=1;
	while(cin>>s && s != ".") {
		memset(c, 0, sizeof(c));
		int pos = s.find("/");
		stringstream ss; ss<<s.substr(pos+1); ss>>d;
		s = s.substr(1, pos-2);
		pos=0;
		grau=0;
		while(pos<s.size()) {
			int pn = s.find("n", pos);
			if(pn == string::npos) {
				stringstream ss; ss<<s.substr(pos); ss>>c[0];
				break;
			}
			ll x;
			if(pn == pos) x=1;
			else if(pn == pos+1 && s[pos]=='+') x=1;
			else if(pn == pos+1 && s[pos]=='-') x=-1;
			else { stringstream ss; ss<<s.substr(pos, pn-pos); ss>>x; }
			int e;
			if(pn==s.size()-1 || s[pn+1] != '^') {
				e=1;
				pos=pn+1;
			}
			else { 
				int j=pn+2;
				while(j<s.size() && s[j]!='+' && s[j] != '-') j++;
				stringstream ss; ss<<s.substr(pn+2, j-pn-2); ss>>e;
				pos=j;
			}
			grau = max(grau, e);
			c[e]=x;
		}
		cout<<"Case "<<t++<<": ";
		if(solve()) cout<<"Always an integer\n";
		else cout<<"Not always an integer\n";
	}
	return 0;
}
