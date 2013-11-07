#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

const int M=30001;
const ll C = (ll)1e9 + 7;

ll hr[M], hl[M], pot[M];

int main() {
	pot[0]=1;
	for(int i=1;i<M;i++) pot[i] = C*pot[i-1];
	int k;
	cin>>k;
	string s;
	cin>>s;
	for(int i=0;i<k;i++) hl[0] += pot[k-i-1]*s[i];
	for(int i=1;;i++) {
		if(i+k-1 >= s.size()) break;
		hl[i] = (hl[i-1] - pot[k-1]*s[i-1])*C + s[i+k-1];
	}
	reverse(s.begin(), s.end());
	for(int i=0;i<k;i++) hr[0] += pot[k-i-1]*s[i];
	for(int i=1;;i++) {
		if(i+k-1 >= s.size()) break;
		hr[i] = (hr[i-1] - pot[k-1]*s[i-1])*C + s[i+k-1];
	}
	int ans=0;
	for(int i=0;;i++) {
		int f=i+k-1;
		if(f>=s.size()) break;
		if(hl[i] == hr[s.size()-1-f]) ans++;
	}
	cout << ans << endl;
	return 0;
}
