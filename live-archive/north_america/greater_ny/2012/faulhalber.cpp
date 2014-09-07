#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=410;
ll num[444][444], den[444][444];

int main() {
	int t, m, k, T;
	num[0][1]=den[0][1]=1;
	for(int i=1; i<N; i++) {
		ll n=0, d=1, mdc;
		for(int j=2; j<=i+1; j++) {
			num[i][j]=1ll*i*num[i-1][j-1];
			den[i][j]=1ll*j*den[i-1][j-1];
			mdc=__gcd(abs(num[i][j]), abs(den[i][j]));
			num[i][j]/=mdc;
			den[i][j]/=mdc;
			if(den[i][j]<0) {
				den[i][j]=-den[i][j];
				num[i][j]=-num[i][j];
			}
			ll auxn=n*den[i][j]+d*num[i][j];
			ll auxd=d*den[i][j];
			n=auxn, d=auxd;
			mdc=__gcd(abs(n), abs(d));
			n/=mdc;
			d/=mdc;
		}
		n=d-n;
		mdc=__gcd(abs(n), abs(d));
		n/=mdc;
		d/=mdc;
		num[i][1]=n;
		den[i][1]=d;
		if(den[i][1]<0) {
			den[i][1]=-den[i][1];
			num[i][1]=-num[i][1];
		}
	}
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &T, &m, &k);
		printf("%d ", T);
		if(den[m][k]==1) printf("%lld\n", num[m][k]);
		else printf("%lld/%lld\n", num[m][k], den[m][k]);
	}
	return 0;
}
