#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n, m;
int ai1, aj1;
int ai2, aj2;
int ai3, aj3;
int ai4, aj4;
double dmax=-1;
int mod(int x) { return x > 0 ? x : -x; }

void test(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4) {
	if(i1 == i2 && j1 == j2) return;
	if(i1 == i3 && j1 == j3) return;
	if(i1 == i4 && j1 == j4) return;
	if(i2 == i3 && j2 == j3) return;
	if(i2 == i4 && j2 == j4) return;
	if(i3 == i4 && j3 == j4) return;
	double dist = hypot(mod(i2-i1), mod(j2-j1))
		+ hypot(mod(i2-i3), mod(j2-j3))
		+ hypot(mod(i4-i3), mod(j4-j3));
	if(dist > dmax) {
		dmax = dist;
		ai1 = i1, aj1 = j1;
		ai2 = i2, aj2 = j2;
		ai3 = i3, aj3 = j3;
		ai4 = i4, aj4 = j4;
	}
}

void testAll() {
	double dmax=-1;
	int ai1, aj1;
	int ai2, aj2;
	int ai3, aj3;
	int ai4, aj4;
	for(int i1=0;i1<=n;i1++) for(int j1=0;j1<=m;j1++)
		for(int i2=0;i2<=n;i2++) for(int j2=0;j2<=m;j2++)
			for(int i3=0;i3<=n;i3++) for(int j3=0;j3<=m;j3++)
				for(int i4=0;i4<=n;i4++) for(int j4=0;j4<=m;j4++) {
					if(i1 == i2 && j1 == j2) continue;
					if(i1 == i3 && j1 == j3) continue;
					if(i1 == i4 && j1 == j4) continue;
					if(i2 == i3 && j2 == j3) continue;
					if(i2 == i4 && j2 == j4) continue;
					if(i3 == i4 && j3 == j4) continue;
					double dist = hypot(mod(i2-i1), mod(j2-j1))
						+ hypot(mod(i2-i3), mod(j2-j3))
						+ hypot(mod(i4-i3), mod(j4-j3));
					if(dist > dmax) {
						dmax = dist;
						ai1 = i1, aj1 = j1;
						ai2 = i2, aj2 = j2;
						ai3 = i3, aj3 = j3;
						ai4 = i4, aj4 = j4;
					}
				}
	printf("%d %d\n", ai1, aj1);
	printf("%d %d\n", ai2, aj2);
	printf("%d %d\n", ai3, aj3);
	printf("%d %d\n", ai4, aj4);
}

int main() {
	cin>>n>>m;
	if(n*m <= 20) {
		testAll();
		return 0;
	}
	test(1, 0, n, m, 0, 0, n-1, m);
	test(0, 1, 0, m, 0, 0, 0, m-1);
	test(1, 0, n, 0, 0, 0, n-1, 0);
	test(0, 1, n, m, 0, 0, n, m-1);
	test(0, 0, n, m, n, 0, 0, m);
	test(0, 0, n, m, 0, m, n, 0);
	printf("%d %d\n", ai1, aj1);
	printf("%d %d\n", ai2, aj2);
	printf("%d %d\n", ai3, aj3);
	printf("%d %d\n", ai4, aj4);
	return 0;
}
