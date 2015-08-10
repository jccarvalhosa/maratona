#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=2e5+10;

char a[N], b[N];

void sort(char *v, int n) {
	if(n&1) return;
	sort(v, n/2);
	sort(v+n/2, n/2);
	for(int i=0;i<n/2;i++) {
		if(v[i] < v[n/2+i]) break;
		if(v[i] > v[n/2+i]) {
			for(int j=0;j<n/2;j++) {
				swap(v[j], v[n/2+j]);
			}
			break;
		}
	}
}

int main() {
	scanf("%s %s", a, b);
	int n = strlen(a);
	sort(a, n);
	sort(b, n);
	printf("%s\n", strcmp(a, b) ? "NO" : "YES");
	return 0;
}
