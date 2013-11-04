#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M;
pii g[111111];
pii gn[111111], gm[111111];
vector<pii> v;

int build2() {
	for(int i=0;i<M;i++) {
		sort(gn, gn+N, greater<pii>());
		if(gm[i].first==0) continue;
		for(int j=0;j<N;j++) {
			if(gn[j].first==0) continue;
			gm[i].first--;
			gn[j].first--;
			v.push_back(pii(gm[i].second, gn[j].second));
			if(!gm[i].first) break;
		}
		if(gm[i].first) return 0;
	}
	for(int j=0;j<N;j++) if(gn[j].first) return 0;
	return 1;
}

int build1(int n) {
	for(int i=0;i<n;i++) {
		sort(g+i, g+n, greater<pii>());
		if(g[i].first==0) continue;
		for(int j=i+1;j<n;j++) if(g[j].first) {
			g[i].first--;
			g[j].first--;
			v.push_back(pii(g[i].second, g[j].second));
			if(!g[i].first) break;
		}
		if(g[i].first) return 0;
	}
	return 1;
}

int main() {
	ifstream in("kids.in");
	ofstream out("kids.out");
	int a, b, c, d;
	while(in >> a >> b >> c >> d && !in.eof()) {
		int n = b/__gcd(b, c);
		int m = c/__gcd(b, c);
		for(int i=1;;i++) {
			v.clear();
			N = n*i;
			M = m*i;
			if(M <= a || N <= d) continue;
			for(int i=0;i<M;i++) g[i] = pii(a, i+1);
			if(!build1(M)) continue;
			for(int i=0;i<N;i++) g[i] = pii(d, M+i+1);
			if(!build1(N)) continue;
			for(int i=0;i<M;i++) gm[i] = pii(b, i+1);
			for(int i=0;i<N;i++) gn[i] = pii(c, M+i+1);
			if(!build2()) continue;
			break;
		}
		out << M << " " << N << endl;
		for(int i=0;i<v.size();i++) out << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}
