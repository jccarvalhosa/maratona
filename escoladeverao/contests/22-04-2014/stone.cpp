#include <iostream>
#include <cstdio>
using namespace std;

int valid(int x) {
	if(x&1) return 0;
	return 1-valid(x/2);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int x;
		scanf("%d", &x);
		printf("%s\n", valid(x) ? "TAK" : "NIE");
	}
	return 0;
}
