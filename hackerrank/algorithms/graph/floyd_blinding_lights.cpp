#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int d[401][401];

int main() {
	int n, m, q;
	cin>>n>>m;

	for (int i=0; i < n; i++) 
		for (int j=0; j < n; j++)    
			d[i][j] = 1e9;

	for (int i=0; i < n; i++)
		d[i][i] = 0;

	for (int i=0; i < m; i++) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r); x--; y--;
		d[x][y] = r;
	}

	for (int k=0; k < n; k++) 
		for (int i=0; i < n; i++) 
			for(int j=0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	cin>>q;

	for(int i=0; i < q; i++) {
		int x, y;
		scanf("%d%d", &x, &y); x--; y--;
		printf("%d\n", d[x][y] == 1e9 ? -1 : d[x][y]);
	}

	return 0;
}

