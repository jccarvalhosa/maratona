#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const int N = 111111;
int n, m, cmax;
pp stud[N];
pii bug[N];
int vis[N], pos[N];

int valid(int days) {
	for(int i=0;i<n;i++) vis[i]=0;
	set<pii> s;
	int pbug=0, pstud=0, cost=0;
	while(pbug < m) {
		while(pstud < n && stud[pstud].first >= bug[pbug].first) s.insert(stud[pstud++].second);
		int found=0;
		pii p;
		while(!s.empty()) {
			p = *(s.begin());
			s.erase(p);
			if(vis[p.second]) continue;
			vis[p.second]=1;
			found=1;
			break;
		}
		if(!found) return 0;
		cost += p.first;
		if(cost > cmax) return 0;
		for(int i=0;i<days;i++) {
			pos[bug[pbug++].second] = p.second+1;
			if(pbug == m) break;
		}
	}
	return 1;
}

int main() {
	cin>>n>>m>>cmax;
	for(int i=0;i<m;i++) {
		cin>>bug[i].first;
		bug[i].second=i;
	}
	sort(bug, bug+m);
	reverse(bug, bug+m);
	for(int i=0;i<n;i++) cin>>stud[i].first;
	for(int i=0;i<n;i++) {
		cin>>stud[i].second.first;
		stud[i].second.second=i;
	}
	sort(stud, stud+n);
	reverse(stud, stud+n);
	if(!valid(m)) {
		cout<<"NO"<<endl;
		return 0;
	}
	int l=0, r=m;
	while(l<r-1) {
		int mid=(l+r)/2;
		if(valid(mid)) r=mid;
		else l=mid;
	}
	valid(r);
	cout<<"YES"<<endl;
	for(int i=0;i<m-1;i++) cout<<pos[i]<<" "; cout<<pos[m-1]<<endl;
	return 0;
}
