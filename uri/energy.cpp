#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		double y1, y2, v1, v2;
		cin>>y1>>v1>>y2>>v2;
		double ans = (v2-v1)/(y2-y1);
		long long ansl = ans*100;
		printf("%lld,%.2lld\n", ansl/100, ansl%100);
	}
	return 0;
}
