#include <algorithm>
#include <iostream>
using namespace std;

const int N=2222;
int n, m[N], t[N], h[N], vis[N];

int go(int type, int x) {
	int ii, mm=-1;
	for(int i=0;i<n;i++) if(!vis[i] && t[i] == type && h[i] <= x && m[i] > mm) {
		ii = i;
		mm = m[i];
	}
	if(mm == -1) return 0;
	vis[ii]=1;
	return 1 + go(1 - type, x + mm);
}

int main() {
	int x;
	cin>>n>>x;
	for(int i=0;i<n;i++) cin>>t[i]>>h[i]>>m[i];
	for(int i=0;i<n;i++) vis[i]=0;
	int ans1 = go(0, x);
	for(int i=0;i<n;i++) vis[i]=0;
	int ans2 = go(1, x);
	cout << max(ans1, ans2);
	return 0;
}
