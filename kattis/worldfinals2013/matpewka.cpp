#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

int v[500], dp[500][500], ml[500], mr[500], t[501];
int valid[500][500], best[500];

void calc(int a, int b) {
	int i, m, c;
	ml[a] = v[a];
	for(i=a+1;i<=b;i++) ml[i] = min(ml[i-1], v[i]);
	mr[b] = v[b];
	for(i=b-1;i>=a;i--) mr[i] = min(mr[i+1], v[i]);
	memset(t, 0, sizeof(t));
	for(i=a;i<=b;i++) t[v[i]]=1;
	for(i=1;i<=500;i++) t[i] += t[i-1];
	dp[a][b] = INF;
	for(i=a;i<b;i++) {
		m = max(ml[i], mr[i+1]);
		c = b-a+2-t[m];
		dp[a][b] = min(dp[a][b], dp[a][i] + dp[i+1][b] + c);
	}
}

int main() {
	int n, m, i, j;
	cin>>n;
	for(i=0;i<n;i++) cin>>v[i];
	for(i=0;i<n;i++) {
		set<int> s;
		m=0;
		for(j=i;j<n;j++) {
			if(s.count(v[j])) break;
			s.insert(v[j]);
			m = max(m, v[j]);
			if(s.size() == j-i+1 && m == j-i+1) valid[i][j]=1;
		}
	}
	for(i=0;i<n;i++) dp[i][i] = 0;
	for(i=1;i<n;i++) for(j=0;i+j<n;j++) calc(j, i+j);
	for(i=0;i<n;i++) {
		best[i]=INF;
		if(valid[0][i]) best[i]=dp[0][i];
		for(j=0;j<i;j++) if(valid[i-j][i]) best[i] = min(best[i], best[i-j-1] + dp[i-j][i]);
	}
	if(best[n-1] != INF) cout<<best[n-1]<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}
