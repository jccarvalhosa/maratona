#include <iostream>
using namespace std;

const int M=50;
int n, a[55], v[55], dp[55];

int check(int k) {
	for(int i=1;i<=M;i++) dp[i]=0;
	dp[0]=1;
	for(int i=0;i<k;i++) for(int j=M;j>=v[i];j--) dp[j] |= dp[j-v[i]];
	for(int i=0;i<n;i++) if(dp[a[i]]==0) return 0;
	return 1;
}

int go(int x, int pos, int k) {
	v[pos] = x;
	if(pos == k-1) return check(k);
	for(int i=x;i>=1;i--) if(go(i, pos+1, k)) return 1;
	return 0;
}

int valid(int k) {
	for(int i=1;i<=M;i++) if(go(i, 0, k)) return 1;
	return 0;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int k=1;;k++) if(valid(k)) {
		cout << k << endl;
		return 0;
	}
}
