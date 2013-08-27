#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;

int n, v[1111];
vector<pii> ans;

int findLeft() {
	for(int i=1;i<=n;i++) if(v[i]!=i) return i;
	return 0;
}

int findRight() {
	for(int i=n;i>=1;i--) if(v[i]!=i) return i;
	return 0;
}

int getPos(int x) { for(int i=1;i<=n;i++) if(v[i]==x) return i; }

int go(int d) {
	int l, r;
	l = findLeft();
	if(!l) return 1;
	if(d==3) return 0;
	r = getPos(l);
	reverse(v+l, v+r+1);
	if(go(d+1)) {
		ans.push_back(pii(l, r));
		return 1;
	}
	reverse(v+l, v+r+1);
	r = findRight();
	l = getPos(r);
	reverse(v+l, v+r+1);
	if(go(d+1)) {
		ans.push_back(pii(l, r));
		return 1;
	}
	reverse(v+l, v+r+1);
	return 0;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i];
	go(0);
	if(ans.empty()) printf("2\n1 2\n1 2\n");
	else {
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
