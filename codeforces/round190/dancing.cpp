#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, m, i, j;
	cin>>n>>m;
	cout << n+m-1 << endl;
	for(i=1;i<=n;i++) cout << i << " " << 1 << endl;
	for(i=2;i<=m;i++) cout << 1 << " " << i << endl;
	return 0;
}
