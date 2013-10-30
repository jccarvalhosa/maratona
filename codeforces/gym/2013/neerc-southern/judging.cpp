#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

double p[333333], pf[333333];
int ti[333333], tc[333333], tj[333333];

priority_queue <pair<int,int> > q;

int main() {
	int n, m;
	while(cin >> n >> m && !cin.eof()) {
		int j=0, t=0, tl=0;
		double ans=0;
		for(int i=0;i<n;i++) {
			cin >> ti[i] >> p[i];
			tc[i] = t+ti[i];
			tl = max(tl,tc[i]);
			tj[i] = tl;
			pf[i] = 1-p[i];
			if(i) p[i] = p[i]*p[i-1];
			if(i) pf[i] = pf[i]*p[i-1];
			q.push(make_pair(-tc[i],i));
			j++;
			if(j == m) {
				pair<int,int> k = q.top();
				q.pop();
				t = tc[k.second];
				ans += pf[k.second]*tj[k.second];
				j--;
			}
		}
		while(!q.empty()) {
			pair<int,int> k = q.top();
			q.pop();
			t = tc[k.second];
			ans += pf[k.second]*tj[k.second];
			j--;
		}
		ans += tj[n-1]*p[n-1];
		printf("%.7lf\n", ans);
	}
	return 0;
}
