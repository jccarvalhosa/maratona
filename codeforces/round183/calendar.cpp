#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y) {
	if(y % 4 != 0) return 0;
	if(y % 400 == 0) return 1;
	if(y % 100 == 0) return 0;
	return 1;
}

int dist(int y, int m, int d) {
	int i, ret=0;
	for(i=1900;i<y;i++) {
		if(leap(i)) ret += 366;
		else ret += 365;
	}
	for(i=1;i<m;i++) {
		ret += days[i-1];
		if(leap(y) && i == 2) ret++;
	}
	ret += d;
	return ret;
}

int mod(int a) { return a > 0 ? a : -a; }

int main() {
	string a, b;
	int y[2], m[2], d[2], v[2];
	cin>>a>>b;
	y[0] = 1000 * (a[0]-'0') + 100 * (a[1]-'0') + 10 * (a[2]-'0') + a[3]-'0';
	y[1] = 1000 * (b[0]-'0') + 100 * (b[1]-'0') + 10 * (b[2]-'0') + b[3]-'0';
	m[0] = 10 * (a[5]-'0') + a[6]-'0';
	m[1] = 10 * (b[5]-'0') + b[6]-'0';
	d[0] = 10 * (a[8]-'0') + a[9]-'0';
	d[1] = 10 * (b[8]-'0') + b[9]-'0';
	v[0] = dist(y[0], m[0], d[0]);
	v[1] = dist(y[1], m[1], d[1]);
	cout << mod(v[0]-v[1]) << endl;
	return 0;
}
