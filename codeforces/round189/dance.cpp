#include <cstdio>
#include <iostream>
#include <string>
#define M 1000000007
using namespace std;

long long ans, pot[101];

int main() {
	int i, n;
	string s;
	cin>>s;
	pot[0]=1;
	for(i=1;i<=100;i++) pot[i] = (2*pot[i-1])%M;
	n = s.size();
	for(i=0;i<n;i++) if(s[i]=='1') {
		ans = (ans + pot[i]*((pot[n-i-1]*pot[n-i-1])%M))%M;
	}
	cout<<ans<<endl;
	return 0;
}
