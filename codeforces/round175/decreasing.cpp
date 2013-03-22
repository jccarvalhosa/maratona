#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, k, i;
	cin >> n >> k;
	for(i=0;i<k;i++) cout << n-i << " ";
	for(i=1;i<=n-k;i++) cout << i << " ";
	cout << endl;
	return 0;
}
