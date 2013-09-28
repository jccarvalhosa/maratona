#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long long v[111111];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i];
	cout << max((accumulate(v, v+n, 0ll) + n - 2) / (n-1), *max_element(v, v+n)) << endl;
	return 0;
}
