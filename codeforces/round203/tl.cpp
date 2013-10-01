#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[111], b[111];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	sort(a, a+n);
	sort(b, b+m);
	int vmin = max(2*a[0], a[n-1]);
	if(b[0]<=vmin) cout<<-1<<endl;
	else cout<<vmin<<endl;
	return 0;
}
