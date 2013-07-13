#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> h, m;

int main() {
	string s, sub;
	int i, j, n, H, M;
	long long ans=0;
	cin>>s;
	n = s.size();
	for(i=0;i<=n-5;i++) {
		sub = s.substr(i, 5);
		if(sub == "heavy") h.push_back(i);
		else if(sub == "metal") m.push_back(i);
	}
	M = m.size();
	H = h.size();
	j=0;
	for(i=0;i<H;i++) {
		while(j<M && m[j]<h[i]+5) j++;
		ans += (M-j);
	}
	cout<<ans<<endl;
	return 0;
}
