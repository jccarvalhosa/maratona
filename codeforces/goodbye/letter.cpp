#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e15;

int k, x, n, m;
ll c[55], bc[55], ea[55];

string build(int pos, int n) {
	string s="";
	for(int i=0;i<n;i++) s+="X";
	if(bc[pos]) s[0]='C';
	if(ea[pos]) s[n-1]='A';
	if(n==1) {
		if(bc[pos] && ea[pos]) return "";
		return s;
	}
	if(2*c[pos]==n) {
		if(bc[pos] || ea[pos]) return "";
		for(int i=0;i<n;i++) s[i] = (i%2==0 ? 'A' : 'C');
		return s;
	}
	if(2*c[pos]==n-1) {
		if(bc[pos] && ea[pos]) return "";
		for(int i=0;i<2*c[pos];i++) s[i+bc[pos]] = (i%2==0 ? 'A' : 'C');
		return s;
	}
	for(int i=0;i<2*c[pos];i++) s[i+1] = (i%2==0 ? 'A' : 'C');
	return s;
}

int valid() {
	for(int i=3;i<=k;i++) {
		bc[i] = bc[i-2];
		ea[i] = ea[i-1];
		c[i] = c[i-2] + c[i-1] + (ea[i-2] && bc[i-1]);
		if(c[i] > INF) return 0;
	}
	return c[k] == x;
}

string solve() {
	for(bc[1]=0;bc[1]<=1;bc[1]++) for(ea[1]=0;ea[1]<=1;ea[1]++)
		for(bc[2]=0;bc[2]<=1;bc[2]++) for(ea[2]=0;ea[2]<=1;ea[2]++) 
			for(c[1]=0;c[1]<=n/2;c[1]++) for(c[2]=0;c[2]<=m/2;c[2]++)
				if(valid()) {
					string s1 = build(1, n);
					string s2 = build(2, m);
					if(s1 != "" && s2 != "") return s1 + "\n" + s2;
				}
	return "Happy new year!";
}

int main() {
	cin>>k>>x>>n>>m;
	cout<<solve()<<endl;
	return 0;
}
