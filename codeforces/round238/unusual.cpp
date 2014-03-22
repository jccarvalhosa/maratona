#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=1e3+10;
int m[N][N];

int main() {
	int ans, n, q;
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &m[i][j]);
	for(int i=0;i<n;i++) ans += m[i][i];
	ans %= 2;
	cin>>q;
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t==1 || t == 2) {
			int x;
			scanf("%d", &x);
			ans = 1 - ans;
		}
		if(t==3) {
			printf("%d", ans);
		}
	}
	printf("\n");
	return 0;
}
