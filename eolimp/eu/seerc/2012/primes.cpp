#include <iostream>
using namespace std;

const int N = 1e7+1;
int sum[N], vis[N];

int main() {
	for(int i=2;i<N;i++) if(!vis[i]) for(int j=2*i;j<N;j+=i) vis[j]=1;
	for(int i=2;i<N;i++) sum[i] = sum[i-1] + (!vis[i]);
	int a, b;
	for(int i=0;cin>>a>>b && !cin.eof();i++) {
		if(i) cout<<endl;
		cout << sum[b] - sum[a-1] << endl;
	}
	return 0;
}
