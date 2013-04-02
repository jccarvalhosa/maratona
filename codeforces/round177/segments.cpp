#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, k, i, a, b;
	long long delta=0;
	cin>>n>>k;
	for(i=0;i<n;i++) {
		cin>>a>>b;
		delta += b-a+1;
	}
	if(delta % k == 0) cout<<0<<endl;
	else cout<< (k - (delta%k))<<endl;
}
