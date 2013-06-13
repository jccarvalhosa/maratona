#include <iostream>
using namespace std;

int main() {
	int n;
	while(cin>>n && n) cout << (n+2)*(n+1)*(n)*(n-1)/24 << endl;
	return 0;
}
