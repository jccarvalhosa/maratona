#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, v[555555];

int valid(int m) {
	int pos = n-m;
	for(int i=0;i<n-m;i++) {
		while(pos != n && v[pos] < 2*v[i]) pos++;
		if(pos == n) return 0;
		pos++;
	}
	return 1;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v, v+n);
	int i=0, f=n;
	while(i<f-1) {
		int m = (i+f)/2;
		if(valid(m)) f=m;
		else i=m;
	}
	cout<<f<<endl;
	return 0;
}
