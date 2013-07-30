#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 1e9

int n;
double ans, destx, desty;
const double sq2 = sqrt(2);

double dx[] = {10, 5*sq2,   0, -5*sq2, -10, -5*sq2,   0,  5*sq2};
double dy[] = {0, -5*sq2, -10, -5*sq2,   0,  5*sq2,  10,  5*sq2};

void go(double x, double y, int t, int pos) {
	if(t>n) return;
	if(pos >= 8) return;
	ans = min(ans, hypot(x-destx, y-desty));
	go(x + dx[pos], y + dy[pos], t+1, pos);
	go(x, y, t+1, pos+1);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>destx>>desty;
		ans=INF;
		go(0, 0, 0, 0);
		printf("%.6lf\n", ans);
	}
	return 0;
}
