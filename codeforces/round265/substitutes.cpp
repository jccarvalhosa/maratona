#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll shift[11], add[11];
const int M=1e9+7;

const int N=1e5+1;
string t[N];

int main() {
	for(int i=0;i<10;i++) {
		shift[i] = 10;
		add[i] = i;
	}
	string s;
	cin>>s;

	int q;
	cin>>q;
	for(int i=0;i<q;i++) cin>>t[i];

	for(int i=q-1;i>=0;i--) {
		ll ns=1, na=0;

		for(int j=t[i].size()-1;j>=3;j--) {
			na = (na + add[t[i][j]-'0'] * ns) % M;
			ns = (shift[t[i][j]-'0'] * ns) % M;
		}

		int x = t[i][0] - '0';
		shift[x] = ns;
		add[x] = na;
	}
	
	ll ans=0;
	for(int i=0; i<s.size(); i++) {
		ans = (ans * shift[s[i]-'0'] + add[s[i]-'0']) % M;
	}
	cout << ans << endl;

	return 0;
}
