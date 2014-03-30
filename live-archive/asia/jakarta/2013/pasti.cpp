#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef long long ll;

ll base = 1234567;
const ll mod = (ll)1e9+7;
ll pot[55555];

int main() {
	int T;
	string str;
	cin >> T;
	pot[0] = 1;
	for(int i=1;i<55000;i++) pot[i] = (pot[i-1]*base)%mod;
	for(int t=1;t<=T;t++) 
	{
		cin >> str;
		int s = 0, e = str.size()-1;
		ll hs = 0, he = 0;
		int tam = 1, ans = 0;
		while(1) {
			if(s == e) {
				ans++;
				break;
			}
			hs = (hs+str[s++]*pot[tam-1])%mod;
			he = ((he*pot[1])+str[e--])%mod;
			if(he == hs) {
				ans += 2;
				he = 0;
				hs = 0;
				tam = 0;
				if(s > e) break;
			}
			if(s > e) {
				ans++;
				break;
			}
			tam++;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
