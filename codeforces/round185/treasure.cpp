#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;

int k, M=0, n, c[100000], used[100000], vis[10000];
ll h, a[100000], d[10000], m[20];

void dijkstra() {
	int i, v, u;
	for(i=0;i<k;i++) {
		d[i]=h+1;
		vis[i]=0;
	}
	d[0]=0;
	priority_queue<plli> q;
	q.push(plli(0, 0));
	while(!q.empty()) {
		v = q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		for(i=0;i<M;i++) {
			u = (m[i]+v)%k;
			if(d[u] > d[v] + m[i]) {
				d[u] = d[v] + m[i];
				q.push(plli(-d[u], u));
			}
		}
	}
}

int main() {
	int i, queries, type, x, y, flag;
	priority_queue<pii> q;
	cin>>h>>n>>queries>>k;
	for(i=0;i<n;i++) {
		cin>>a[i]>>c[i]; a[i]--;
		if(a[i]%k==0) {
			q.push(pii(c[i], -i));
			used[i]=1;
		}
	}
	while(queries--) {
		cin>>type;
		if(type==1) {
			cin>>m[M++];
			dijkstra();
			for(i=0;i<n;i++) if(!used[i] && d[a[i]%k] <= a[i]) {
				q.push(pii(c[i], -i));
				used[i]=1;
			}
		}
		if(type==2) {
			cin>>x>>y;x--;
			c[x] -= y;
			if(y && used[x]) q.push(pii(c[x], -x));
		}
		if(type==3) {
			flag=0;
			while(!q.empty()) {
				pii p = q.top();
				q.pop();
				x = -p.second;
				y = p.first;
				if(c[x]==y) {
					cout<<y<<endl;
					flag=1;
					break;
				}
			}
			if(!flag) cout<<0<<endl;
		}
	}
	return 0;
}
