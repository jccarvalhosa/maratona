#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, r[20], val[1<<20];
vector<int> good[21];

int find(int h, int i, int v) {
	if(h==20) {
		if(!good[h][i]) return -1;
		good[h][i]=0;
		return v;
	}
	int ret=-1;
	if(!good[h+1][2*i]) ret = find(h+1, 2*i+1, v + (1<<(19-h)));
	else if(!good[h+1][2*i+1]) ret = find(h+1, 2*i, v);
	else if(r[h]) ret=find(h+1, 2*i+1, v + (1<<(19-h)));
	else ret = find(h+1, 2*i, v);
	if(!good[h+1][2*i] && !good[h+1][2*i+1]) good[h][i]=0;
	return ret;
}

int main() {
	int i, j;
	long long sum=0;
	for(i=0;i<=20;i++) good[i].resize(1<<i, 1);
	cin>>n;
	for(j=n+1;j<(1<<20);j++) good[20][j]=0;
	for(i=19;i>=0;i--) {
		for(j=0;j<(1<<i);j++) if(!good[i+1][2*j] && !good[i+1][2*j+1]) good[i][j]=0;
	}
	for(i=0;i<=n;i++) {
		for(j=0;j<20;j++) r[j] = (i & (1<<(19-j))) ? 0 : 1;
		val[i] = find(0, 0, 0);
		sum += i ^ val[i];
	}
	cout<<sum<<endl;
	for(i=0;i<=n;i++) printf("%d%c", val[i], i==n?'\n':' ');
	return 0;
}
