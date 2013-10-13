#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, v[11111], sum[11111];

int valid() {
	sort(v, v+n, greater<int>());
	sum[0]=v[0];
	for(int i=1;i<n;i++) sum[i] = sum[i-1] + v[i];
	if(sum[n-1]%2) return 0;
	for(ll k=1;k<=n;k++) {
		int pk = lower_bound(v, v+n, k, greater<int>()) - v;
		if(pk<k) pk=k;
		if(sum[k-1] > k*(pk-1) + sum[n-1] - sum[pk-1]) return 0;
	}
	return 1;
}

int main() {
	string s;
	while(getline(cin, s) && !cin.eof()) {
		stringstream ss(s);
		for(n=0;ss>>v[n];n++);
		if(valid()) cout<<"ok"<<endl;
		else cout<<"fail"<<endl;
		cout<<endl;
	}
	return 0;
}
