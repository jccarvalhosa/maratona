#include <iostream>
using namespace std;

int main() {
	unsigned long long a, b;
	int i;
	cin >> a >> b;
	for(i=63;i>=0;i--) if((b & (1ull<<i)) != 0 && (a & (1ull<<i)) == 0) break;
	cout << (1ull<<(i+1))-1 << endl;
	return 0;
}
