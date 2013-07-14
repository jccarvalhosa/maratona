#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x, p, r[2], pot[2][100000];

double profit(int a, int b) {
	double prob = (pot[0][a] - pot[1][a]) / (pot[0][a+b] - pot[1][a+b]);
	return b*prob - x*a*(1-prob);
}

int main() {
	int a, b, i, j;
	double ans=0, best;
	cin>>x>>p;
	p = p/100;
	x = 1-x/100;
	if(p<0.00001) {
		cout<<0<<endl;
		return 0;
	}
	r[0] = (1 + sqrt(1-4*p*(1-p)))/2/p;
	r[1] = (1 - sqrt(1-4*p*(1-p)))/2/p;
	for(i=0;i<2;i++) {
		pot[i][0]=1;
		for(j=1;j<100000;j++) pot[i][j] = pot[i][j-1] * r[i];
	}
	for(a=1;;a++) {
		best=0;
		for(b=1;;b++) {
			if(best >= profit(a, b)) break;
			best = profit(a, b);
		}
		if(ans >= best) break;
		ans = best;
	}
	cout<<ans<<endl;
	return 0;
}
