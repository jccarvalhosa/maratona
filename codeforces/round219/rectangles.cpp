#include <iostream>
#include <string>
using namespace std;

const int M=44;
int cont[M][M][M][M], valid[M][M][M], dp[M][M][M][M];
string tab[M];

int main() {
	int n, m, q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) {
		cin>>tab[i];
		tab[i] = " " + tab[i];
	}
	for(int c=1;c<=m;c++) for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {
		valid[c][i][j]=1;
		for(int k=i;k<=j;k++) if(tab[k][c]=='1') { valid[c][i][j]=0; break; }
	}
	for(int a=1;a<=n;a++) for(int c=a;c<=n;c++) for(int b=1;b<=m;b++) {
		int old=b-1;
		for(int d=b;d<=m;d++) {
			cont[a][c][b][d] = cont[a][c][b][d-1];
			if(valid[d][a][c]) cont[a][c][b][d] += d - old;
			else old = d;
		}
	}
	for(int tam=1;tam<=n;tam++) for(int b=1;b<=m;b++) for(int d=b;d<=m;d++) for(int a=1;a+tam-1<=n;a++) {
		int c = a+tam-1;
		dp[a][c][b][d] = dp[a+1][c][b][d] + dp[a][c-1][b][d] - dp[a+1][c-1][b][d] + cont[a][c][b][d];
	}
	for(int i=0;i<q;i++) {
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		cout<<dp[a][c][b][d]<<endl;
	}
	return 0;
}
