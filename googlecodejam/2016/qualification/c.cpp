#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int mod(int b, int e, int m) {
	if (e == 0) return 1;
	if (e & 1) return (1ll * b * mod(b, e-1, m) % m);
	return mod(1ll * b * b % m, e/2, m);
}

bool divide(int coin, int nbits, int b, int x) {
	int r = 1 + mod(b, nbits-1, x);
	for (int e = 0; e < nbits - 2; e++)
		if (coin & (1 << e))
			r += mod(b, 1+e, x);
	return r % x == 0;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t <= T; t++) {
		printf("Case #%d:\n", t);
		int nbits, len;
		cin>>nbits>>len;
		vector<vector<int> > ans;
		vector<string> bits;
		for(int coin=1; ; coin++) {
			bool ok = true;
			vector<int> v;
			for(int b=2; b <= 10; b++) {
				if (divide(coin, nbits, b, 2)) {
					v.push_back(2);
					continue;
				}
				ok = false;
				for (int x=3; x < 1000; x += 2) 
					if (divide(coin, nbits, b, x)) {
						v.push_back(x);
						ok = true;
						break;
					}
				if (!ok)
					break;
			}
			if(ok) {
				ans.push_back(v);
				string s = "";
				for (int i=nbits-3;i>=0;i--) {
					if (coin & (1 << i)) 
						s += "1";
					else
						s += "0";
				}
				bits.push_back("1" + s + "1");
				if (bits.size() == len)
					break;
			}
		}
		for(int i=0; i < len; i++) {
			cout << bits[i];
			for(int j=0;j<ans[i].size();j++) 
				cout << " " << ans[i][j];
			cout << endl;
		}
	}
	return 0;
}
