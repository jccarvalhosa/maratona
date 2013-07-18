#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
	
vector<ll> v;
ll d, m;
int n, x;

int best() {
	ll ret=0, pos=0;
	while(1) {
		if(2*pos + v[x] - m >= d) return ret+1;
		if(n==x+1) n--;
		if(n==0 || v[n-1] < m-pos) return 0;
		pos = 2*pos + v[n-1] - m;
		ret++;
		n--;
		if(pos >= d) return ret;
	}
}

int main() {
	ifstream fin("taxi.in");
	ofstream fout("taxi.out");
	fin>>d>>m>>n;
	v.resize(n);
	for(int i=0;i<n;i++) fin>>v[i];
	sort(v.begin(), v.end());
	x = lower_bound(v.begin(), v.end(), d-m) - v.begin();
	if(x==n) fout<<0<<endl;
	else fout<<best()<<endl;
	return 0;
}
