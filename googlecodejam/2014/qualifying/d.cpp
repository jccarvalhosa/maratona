#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef double db;

const int N=1001;
double a[N], b[N], vis[N];
int n;

int war() {
	int w=0;
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++) {
		int ok=0;
		for(int j=0;j<n;j++) if(!vis[j] && b[j] > a[i]) {
			vis[j]=1;
			ok=1;
			break;
		}
		if(!ok) {
			w++;
			for(int j=0;j<n;j++) if(!vis[j]) {
				vis[j]=1;
				break;
			}
		}
	}
	return w;
}

int deceit() {
	for(int w=n;w>0;w--) {
		int valid=1;
		for(int i=0;i<w;i++) if(a[n-w+i] < b[i]) valid=0;
		if(valid) return w;
	}
	return 0;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a, a+n);
		for(int i=0;i<n;i++) cin>>b[i];
		sort(b, b+n);
		cout<<"Case #"<<t<<": "<<deceit()<<" "<<war()<<endl;
	}
	return 0;
}
