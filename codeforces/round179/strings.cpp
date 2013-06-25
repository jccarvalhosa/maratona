#include <iostream>
#include <string>
#define M 1000000007
using namespace std;

int main() {
	int n, i, j=0;
	long long v[4][2]={0ll};
	string a, b;
	cin>>n;
	cin>>a>>b;
	a='0'+a;
	b='0'+b;
	v[0][j]=1;
	for(i=1;i<=n;i++) {
		j=1-j;
		if(a[i] == '?' && b[i] == '?') {
			v[0][j] = (v[0][1-j]*10)%M;
			v[1][j] = (v[0][1-j]*45 + v[1][1-j]*55)%M;
			v[2][j] = (v[0][1-j]*45 + v[2][1-j]*55)%M;
			v[3][j] = ((v[1][1-j]+v[2][1-j])*45 + v[3][1-j]*100)%M;
		}
		if(a[i] == '?' && b[i] != '?') {
			v[0][j] = (v[0][1-j]*1)%M;
			v[1][j] = (v[0][1-j]*('9'-b[i]) + v[1][1-j]*('9'-b[i]+1))%M;
			v[2][j] = (v[0][1-j]*(b[i]-'0') + v[2][1-j]*(b[i]-'0'+1))%M;
			v[3][j] = (v[1][1-j]*(b[i]-'0') + v[2][1-j]*('9'-b[i]) + v[3][1-j]*10)%M;
		}
		if(a[i] != '?' && b[i] == '?') {
			v[0][j] = (v[0][1-j]*1)%M;
			v[1][j] = (v[0][1-j]*(a[i]-'0') + v[1][1-j]*(a[i]-'0'+1))%M;
			v[2][j] = (v[0][1-j]*('9'-a[i]) + v[2][1-j]*('9'-a[i]+1))%M;
			v[3][j] = (v[1][1-j]*('9'-a[i]) + v[2][1-j]*(a[i]-'0') + v[3][1-j]*10)%M;
		}
		if(a[i] != '?' && b[i] != '?') {
			if(a[i]-'0' > b[i]-'0') {
				v[0][j] = 0;
				v[1][j] = (v[0][1-j] + v[1][1-j]) % M;
				v[2][j] = 0;
				v[3][j] = (v[3][1-j] + v[2][1-j]) % M;
			}
			if(a[i]-'0' < b[i]-'0') {
				v[0][j] = 0;
				v[1][j] = 0;
				v[2][j] = (v[2][1-j] + v[0][1-j]) % M;
				v[3][j] = (v[3][1-j] + v[1][1-j]) % M;
			}
			if(a[i]-'0' == b[i]-'0') {
				v[0][j] = v[0][1-j];
				v[1][j] = v[1][1-j];
				v[2][j] = v[2][1-j];
				v[3][j] = v[3][1-j];
			}
		}
	}
	cout << v[3][j] << endl;
	return 0;
}