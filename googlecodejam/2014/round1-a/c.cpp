#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int v[1111];

int main() {
	srand(time(NULL));
	int n=1000;
	int T=1000;
	int mbad=0;
	for(int tt=0;tt<T;tt++) {
		for(int i=0;i<n;i++) v[i]=i;
		for(int i=0;i<n;i++) {
			int p = rand() % n;
			swap(v[i], v[p]);
		}
		for(int i=0;i<n;i++) if(v[i] <= i) mbad++;
	}
	mbad /= T;
	int mgood=0;
	for(int tt=0;tt<T;tt++) {
		for(int i=0;i<n;i++) v[i]=i;
		for(int i=0;i<n;i++) {
			int p = i + rand() % (n-i);
			swap(v[i], v[p]);
		}
		for(int i=0;i<n;i++) if(v[i] <= i) mgood++;
	}
	mgood /= T;
	int mid = (mbad + mgood)/2;
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>v[i];
		int cont=0;
		for(int i=0;i<n;i++) if(v[i] <= i) cont++;
		cout << "Case #"<<t<<": ";
		if(cont <= mid) cout<<"BAD"<<endl;
		else cout<<"GOOD"<<endl;
	}
	return 0;
}
