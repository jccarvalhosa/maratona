#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n, m, total, dx=1, dy=1;
set<pii> vis;

void save(int x, int y) {
	if(!vis.count(pii(x, y))) {
		vis.insert(pii(x, y));
		total++;
	}
	if(x==1) dx=1;
	if(x==n) dx=-1;
	if(y==1) dy=1;
	if(y==m) dy=-1;
}

int main() {
	int t, i, x, y;
	string s;
	long long ans=1;
	cin>>n>>m;
	cin>>x>>y>>s;
	if(s[0]=='U') dx=-1;
	if(s[1]=='L') dy=-1;
	save(x, y);
	for(i=0;i<2*(n+m);i++) {
		t = min(dx==1?n-x:x-1, dy==1?m-y:y-1);
		ans += t;
		x += t*dx;
		y += t*dy;
		save(x, y);
		if(total == m+n-2) {
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
