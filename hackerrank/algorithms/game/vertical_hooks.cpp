#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> v1(n), v2(n);
		for (int i=0; i < n; i++)
			cin>>v1[i];
		for (int i=0; i < n; i++)
			cin>>v2[i];
		int sum = 0;
		for (int i=0; i < n; i++)
			sum ^= abs(v1[i] - v2[i]) - 1;

		cout << (sum != 0 ? "player-2" : "player-1") << endl;
	}
	return 0;
}
