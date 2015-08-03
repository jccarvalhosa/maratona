#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n >= 6) {
		printf("YES\n");
		printf("3 - 2 = 1\n");
		printf("1 - 1 = 0\n");
		printf("5 * 0 = 0\n");
		printf("6 * 4 = 24\n");
		for(int i=7;i<=n;i++) printf("%d * 0 = 0\n", i);
		printf("0 + 24 = 24\n");
	}
	else if(n == 4) {
		printf("YES\n");
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
	}
	else if(n == 5) {
		printf("YES\n");
		printf("5 * 4 = 20\n");
		printf("20 + 3 = 23\n");
		printf("23 + 2 = 25\n");
		printf("25 - 1 = 24\n");
	}
	else printf("NO\n");
	return 0;
}
