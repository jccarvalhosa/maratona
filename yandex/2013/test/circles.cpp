#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> puu;

ull mdc(ull a, ull b) { return b?mdc(b, a%b):a;}
ull abs(int a, int b) { return a*a+b*b;}
int mod(int a) { return a>0?a:-a;}

int main() {
	int n, i, j, c, ans, x[3], y[3];
	ull s, num, den, m;
	ifstream fin("circles.in");
	ofstream fout("circles.out");
	fin>>n;
	vector<puu> v(n);
	for(i=0;i<n;i++) {
		for(j=0;j<3;j++) fin>>x[j]>>y[j];
		num = 1;
		for(j=0;j<3;j++) num *= abs(x[(j+1)%3] - x[j], y[(j+1)%3] - y[j]);
		s = mod(x[0]*(y[1]-y[2]) + x[1]*(y[2]-y[0]) + x[2]*(y[0]-y[1]));
		den = s*s;
		m = mdc(num, den);
		v[i] = puu(num/m, den/m);
	}
	sort(v.begin(), v.end());
	c=ans=1;
	for(i=1;i<n;i++) {
		if(v[i] == v[i-1]) {
			c++;
			ans = max(ans, c);
		}
		else c=1;
	}
	fout<<ans<<endl;
	return 0;
}
