#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=1e6;
int vis[N];
int my[N];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d", &x);
		vis[x-1] = 1;
	}
	int sum=0, sz=0;
	for(int i=0;i<N/2;i++) {
		if(vis[i] && vis[N-1-i]) {
			sum++;
		}
		else if(vis[i]) {
			vis[N-1-i] = 1;
			my[sz++] = N-i;
		}
		else if(vis[N-1-i]) {
			vis[i] = 1;
			my[sz++] = i+1;
		}
	}
	for(int i=0;i<N/2;i++) {
		if(sum==0) break;
		if(!vis[i] && !vis[N-1-i]) {
			my[sz++] = i+1;
			my[sz++] = N-i;
			sum--;
		}
	}
	printf("%d\n", sz);
	printf("%d", my[0]);
	for(int i=1;i<sz;i++) printf(" %d", my[i]);
	printf("\n");
	return 0;
}
