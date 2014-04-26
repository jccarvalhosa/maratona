#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n, l;
		cin>>n>>l;
		vector<ll> ini(n), fim(n), aux(n);
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			ini[i]=0;
			for(int j=0;j<l;j++) if(s[j]=='1') ini[i] += 1ll<<(l-j-1);
		}
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			fim[i]=0;
			for(int j=0;j<l;j++) if(s[j]=='1') fim[i] += 1ll<<(l-j-1);
		}
		sort(fim.begin(), fim.end());
		int best = 50;
		for(int i=0;i<n;i++) {
			ll op=ini[0]^fim[i];
			for(int j=0;j<n;j++) aux[j] = ini[j]^op;
			sort(aux.begin(), aux.end());
			if(aux == fim) best = min(best, __builtin_popcountll(op));
		}
		cout << "Case #"<<t<<": ";
		if(best == 50) cout<<"NOT POSSIBLE"<<endl;
		else cout<<best<<endl;
	}
	return 0;
}
