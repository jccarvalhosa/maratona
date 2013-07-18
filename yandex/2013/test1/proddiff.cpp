#include <fstream>
#define NAME "proddiff"
using namespace std;

int s[10000], ans[10000], d[10000];
int n, m, best;

void go(int n, int k, int t) {
	int i;
	if(n==1 && best<t) {
		best = t;
		for(i=0;i<best;i++) ans[i] = s[i];
	}
	for(i=k;i<m && (d[i]*d[i]<=n);i++) if(n % d[i] == 0) {
		s[t] = d[i];
		go(n/d[i], i+1, t+1);
	}
	if(n > d[k-1]) {
		s[t] = n;
		go(1, m, t+1);
	}
}

int main() {
	ifstream fin(NAME ".in");
	ofstream fout(NAME ".out");
	fin>>n;
	int i;
	best = 0;
	for(i=1;i*i<=n;i++) if(n%i==0) d[m++] = i;
	s[0] = 1;
	go(n, 1, 1);
	fout<<best<<endl;
	for(i=0;i<best;i++) fout<<ans[i]<<" ";
	fout<<endl;
	return 0;
}
