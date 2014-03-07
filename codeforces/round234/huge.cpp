#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int N, M;
int n, m, x, y, z, p;

pii clock(pii a) {
	pii b;
	b.first = a.second;
	b.second = n - 1 - a.first;
	swap(n,m); 
	return b;
}

pii horiz(pii a) {
	a.second = m-1-a.second;
	return a;
}

int main() {
	cin >> N >> M >> x >> y >> z >> p;
	x %= 4;
	y %= 2;
	z %= 4;
	for(int i=0;i<p;i++) {
		int r, c;
		n = N;
		m = M;
		cin>>r>>c;r--;c--;
		pii ret(r,c);
		for(int i=0;i<x;i++) ret = clock(ret);
		for(int i=0;i<y;i++) ret = horiz(ret);
		for(int i=0;i<(4-z);i++) ret = clock(ret);
		cout << ret.first+1 << " " << ret.second+1 << endl;
	}
	return 0;
}
