#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> h[3];

int main() {
	int n, i, t, w, a, b, A, B, ans;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>t>>w;
		h[t].push_back(w);
	}
	sort(h[1].begin(), h[1].end());
	sort(h[2].begin(), h[2].end());
	A = h[1].size();
	B = h[2].size();
	ans=1000000000;
	for(a=0;a<=A;a++) for(b=0;b<=B;b++) {
		t = a + 2*b;
		w=0;
		for(i=0;i<A-a;i++) w += h[1][i];
		for(i=0;i<B-b;i++) w += h[2][i];
		if(w <= t) ans = min(ans, t);
	}
	cout<<ans<<endl;
	return 0;
}
