#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

double m[2];
double x[N], y[N];

int main() {
	int t = 1, n, k;
	while(cin >> n >> k && n) {
		for(int i=0;i<n;i++) {
			cin >> x[i] >> y[i];
		}
		printf("Case %d: ", t++);
		m[0] = m[1] = 1e9;
		if(k == 0) printf("Acceptable as proposed\n");
		else {
			double krad = k*M_PI/180;
			// clock
			for(int i=0;i<=18000; i+=1) {
				double delta = 1.0*i/100.0;
				double arad = delta*M_PI/180.0;
				double cur = 0;
				int j;
				for(j=0;j<n;j++) {
					double nx = x[j]*cos(-arad)-y[j]*sin(-arad);
					if(nx < cur - 1e-6) break;
					cur = nx;
				}
				if(j == n) {
					m[0] = delta;
					break;
				}
			}
			// counter
			for(int i=0;i<=18000;i+=1) {
				double delta = 1.0*i/100.0;
				double arad = delta*M_PI/180.0;
				double cur = 0;
				int j;
				for(j=0;j<n;j++) {
					double nx = x[j]*cos(arad)-y[j]*sin(arad);
					if(nx < cur - 1e-6) break;
					cur = nx;
				}
				if(j == n) {
					m[1] = delta;
					break;
				}
			}
			if(m[0] > 1e8 &&  m[1] > 1e8) printf("Unacceptable\n");
			else {
				if(m[0] <= m[1]) printf("Acceptable after clockwise rotation of %.2lf degrees\n", m[0]);
				else printf("Acceptable after counterclockwise rotation of %.2lf degrees\n", m[1]);
			}
		}
		printf("\n");
	}
	return 0;
}
