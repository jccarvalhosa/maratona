#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		double r, b, m;
		cin>>r>>b>>m;
		double bi = b;
		int t;
		char s[111];
		for(t=1;t<=1200;t++) {
			b += b*r/100;
			b -= m;
			sprintf(s, "%.2lf", b+1e-9);
			sscanf(s, "%lf", &b);
			if(b > bi) {
				t = 1200;
			}
			if(b < 1e-9) break;
		}
		if(t==1201) cout << "impossible" << endl;
		else cout << t << endl;
	}
	return 0;
}
