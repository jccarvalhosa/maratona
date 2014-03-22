#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, p;
		cin>>n>>p;
		int k=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				cout<<i<<" "<<j<<endl;
				k++;
				if(k==2*n+p) break;
			}
			if(k==2*n+p) break;
		}
	}
	return 0;
}
