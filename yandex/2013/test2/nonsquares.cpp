#include <iostream>
#include <algorithm>
using namespace std;

int vis[100000];

int valid(int n, int k) {
	if(n==1) return k%2 != 1;
	if(k>=2) return 1;
	for(int i=2;;i++) {
		if(i*i==n) return 0;
		if(i*i>n) return 1;
	}
}

int main() {
	int t, n, m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		cout<<(valid(n, m)?"YES":"NO")<<endl;
	}
	return 0;
}
