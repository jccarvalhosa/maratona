#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	while(scanf("%d%d", &a, &b) != EOF) {
		c = b-a+1;
		cout << ((c*(c-1))/2) << endl;
	}
	return 0;
}
