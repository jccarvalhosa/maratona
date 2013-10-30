#include <iostream>
#include <cstdio>

using namespace std;

long long p[111111];

int main() {
	long long n, d, a, b;
	long long inc, dec, s;
	while(cin >> n >> d >> a >> b && !cin.eof()) {
		inc = dec = s = 0;
		for(int i=0;i<n;i++) {
			cin >> p[i];
			if(i) {
				if(p[i] > p[i-1]) {
					inc++;
					dec = 0;
				} else if(p[i] < p[i-1]){
					inc = 0;
					dec++;
				} else {
					dec = 0;
					inc = 0;
				}
			}
			if(inc > 0) {
				long long m = d/p[i];
				s += min(a*inc,m);
				d -= min(a*inc*p[i],m*p[i]);
			}
			if(dec > 0) {
				d += min(s*p[i],b*dec*p[i]);
				s -= min(s,b*dec);
			}
		}
		cout << d << " " << s << endl;
	}
	return 0;
}
