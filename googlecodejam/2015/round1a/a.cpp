#include <iostream>
#include <algorithm>
using namespace std;

int v[1111];

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int n;
		cin>>n;
		int v1=0, v2=0, m=0;
		for(int i=1;i<=n;i++) {
			cin>>v[i];
			if(v[i] < v[i-1]) {
				v1 += v[i-1]-v[i];
				if(i > 1) m = max(m, v[i-1]-v[i]);
			}
		}
		for(int i=n-1;i>0;i--) {
			v2 += max(min(m, v[i]), v[i] - v[i+1]);
		}
		cout << "Case #"<<t<<": "<<v1<<" "<<v2<<endl; 
	}
	return 0;
}
