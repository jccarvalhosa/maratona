#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string s;

int main() {
	int n, i, v;
	scanf("%d", &n);
	v=0;
	for(i=0;i<n;i++) {
		cin >> s;
		if(s[0] == '+' || s[2] == '+') v++;
		else v--;
	}
	printf("%d\n", v);
	return 0;
}
