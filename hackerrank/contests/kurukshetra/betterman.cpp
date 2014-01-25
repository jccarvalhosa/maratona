#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=110;
int n, t[N][N][N];

void add(int x, int y, int z, int v) {
	for(;x<=n;x+=x&-x)
		for(int y1=y;y1<=n;y1+=y1&-y1)
			for(int z1=z;z1<=n;z1+=z1&-z1)
				t[x][y1][z1]+=v;
}

int sum(int x, int y, int z) {
	int ret=0;
	for(;x;x-=x&-x)
		for(int y1=y;y1;y1-=y1&-y1)
			for(int z1=z;z1;z1-=z1&-z1)
				ret+=t[x][y1][z1];
	return ret;
}

int sum(int x1, int y1, int z1, int x2, int y2, int z2) {
	x1--;y1--;z1--;
	return sum(x2,y2,z2) 
		- sum(x1, y2, z2) - sum(x2, y1, z2) - sum(x2, y2, z1) 
		+ sum(x1,y2,z1) + sum(x2,y1,z1) + sum(x1,y1,z2)
		- sum(x1,y1,z1);           
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		while(1) {
			int A;
			scanf("%d", &A);
			if(A==3) break;
			if(A==1) {
				int x, y, z, val;
				scanf("%d %d %d %d", &x, &y, &z, &val);
				x++;y++;z++;
				add(x,y,z, val);
			}
			if(A==2) {
				int x1, y1, z1, x2, y2, z2;
				scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
				x1++;y1++;z1++;x2++;y2++;z2++;
				printf("%d\n", sum(x1, y1, z1, x2, y2, z2));
			}
		}
		memset(t, 0, sizeof(t));
	}
	return 0;
}


