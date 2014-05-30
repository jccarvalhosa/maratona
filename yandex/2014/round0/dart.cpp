#include <bits/stdc++.h>
using namespace std;

int v[555][555];

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &v[i][j]);
	int ma=0, ii, jj;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		int sum = 8 * v[i][j];
		for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) if(dx||dy) sum += v[i+dx][j+dy];
		if(sum >= ma) {
			ma=sum;
			ii=i;
			jj=j;
		}
	}
	cout << ii << " " << jj << endl;
	return 0;
}
