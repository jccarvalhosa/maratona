#include <iostream>
#include <cstdio>
using namespace std;
typedef double db;

double c, f, x;

int valid(db total) {
	db rate=2, t=0;
	while(t <= total) {
		if((total-t)*rate >= x) return 1;
		t += c/rate;
		rate += f;
	}
	return 0;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>c>>f>>x;
		db i=0, f=x/2;
		for(int tt=0;tt<500;tt++) {
			db m = (i+f)/2;
			if(valid(m)) f=m;
			else i=m;
		}
		printf("Case #%d: %.12lf\n", t, i);
	}
	return 0;
}
