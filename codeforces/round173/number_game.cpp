#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[300][300], t[300][300][300];

int main() {
	int i, j, k, l, n, a[3];
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	if(n==1) printf(a[0] ? "BitLGM" : "BitAryo");
	if(n==2) {
		memset(d, 0, sizeof(d));
		for(i=0;i<300;i++) for(j=0;j<300;j++) if(d[i][j] == 0) {
			int M=max(i, j);
			for(k=1;i+k<300;k++) d[i+k][j]=1;
			for(k=1;j+k<300;k++) d[i][j+k]=1;
			for(k=1;M+k<300;k++) d[i+k][j+k]=1;
		}
		printf(d[a[0]][a[1]] ? "BitLGM" : "BitAryo");
	}
	if(n==3) {
		memset(t, 0, sizeof(t));
		for(i=0;i<300;i++) for(j=0;j<300;j++) for(k=0;k<300;k++) if(t[i][j][k] == 0){
			int M=max(i, max(j, k));
			for(l=1;i+l<300;l++) t[i+l][j][k]=1;
			for(l=1;j+l<300;l++) t[i][j+l][k]=1;
			for(l=1;k+l<300;l++) t[i][j][k+l]=1;
			for(l=1;M+l<300;l++) t[i+l][j+l][k+l]=1;
		}
		printf(t[a[0]][a[1]][a[2]] ? "BitLGM" : "BitAryo");
	}
	return 0;
}
