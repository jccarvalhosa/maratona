#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n;

int dif(int a, int b) { 
	if(a>b) swap(a, b);
	return min(b-a, n+a-b);
}

int main() {
	ifstream in("combo.in");
	ofstream out("combo.out");
	in>>n;
	int a[2], b[2], c[2];
	for(int i=0;i<2;i++) in>>a[i]>>b[i]>>c[i];
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) {
		int valid=0;
		for(int p=0;p<2;p++) if(dif(a[p], i) <= 2 && dif(b[p], j) <= 2 && dif(c[p], k) <= 2) valid=1;
		ans += valid;
	}
	out<<ans<<endl;
	return 0;
}
