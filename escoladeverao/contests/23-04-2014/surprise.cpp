#include <cstdio>
#include <algorithm>
#define INF 2000000000

using namespace std;

const int N=333;
//dp[i][j] - sum of rectangle with upper-left (1, 1) and lower-right (i, j)
//dplu[i][j] - best sum of submatrix from row 1 to row i and considering prefix up to column j
//dpru[i][j] - best sum of submatrix from row 1 to row i and considering suffix up to column j
//dplb[i][j] - best sum of submatrix from row n to row i and considering prefix up to column j
//dprb[i][j] - best sum of submatrix from row n to row i and considering suffix up to column j
int x[N][N], dp[N][N], dplu[N][N], dpru[N][N], dplb[N][N], dprb[N][N], s[N], n, m;

//Upper-left (a, b) - Lower-right (c, d)
int sum(int a, int b, int c, int d) { return dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]; }

//Build the array for Kadane's algorithm consisting of interval from row a to row b inclusively
void build(int a, int b) { for(int i=1; i<=m; i++) s[i]=sum(a, i, b, i); }

//Build the array for Kadane's algorithm consisting of interval from column a to column b inclusively
void build_column(int a, int b) { for(int i=1; i<=n; i++) s[i]=sum(i, a, i, b); }

int main() {
	int i, j, k, d, soma, maxrow, maxcolumn;
	scanf("%d %d %d", &n, &m, &d);
	for(i=1; i<=n; i++) for(j=1; j<=m; j++) {
		scanf("%d", &x[i][j]);
		dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+x[i][j];
	}
	for(i=0; i<=n+1; i++) for(j=0; j<=m+1; j++) dplu[i][j]=dpru[i][j]=dplb[i][j]=dprb[i][j]=-INF;
	//Constructing dplu and dpru
	for(i=1; i<=n; i++) for(j=i; j<=n; j++) {
		build(i, j);
		for(soma=0, k=1; k<=m; k++) {
			soma+=s[k];
			dplu[j][k]=max(max(dplu[j][k], dplu[j-1][k]), max(dplu[j][k-1], soma));
			if(soma<0) soma=0;
		}
		for(soma=0, k=m; k>=1; k--) {
			soma+=s[k];
			dpru[j][k]=max(max(dpru[j][k], dpru[j-1][k]), max(dpru[j][k+1], soma));
			if(soma<0) soma=0;
		}
	}
	//Constructing dplb and dprb
	for(i=n; i>=1; i--) for(j=i; j>=1; j--) {
		build(j, i);
		for(soma=0, k=1; k<=m; k++) {
			soma+=s[k];
			dplb[j][k]=max(max(dplb[j][k], dplb[j+1][k]), max(dplb[j][k-1], soma));
			if(soma<0) soma=0;
		}
		for(soma=0, k=m; k>=1; k--) {
			soma+=s[k];
			dprb[j][k]=max(max(dprb[j][k], dprb[j+1][k]), max(dprb[j][k+1], soma));
			if(soma<0) soma=0;
		}
	}
	int ans=-INF;
	if(d==1) printf("%d\n", dplu[n][m]);
	else if(d==2) {
		//Checking for separating rows
		for(i=1; i<n; i++) ans=max(ans, dplu[i][m]+dplb[i+1][m]);
		//Checking for separating columns
		for(i=1; i<m; i++) ans=max(ans, dplu[n][i]+dpru[n][i+1]);
		printf("%d\n", ans);
	}
	else {
		//Checking for horizontal line + vertical line
		for(i=1; i<n; i++) for(j=1; j<m; j++) {
			//vertical line above of horizontal line
			ans=max(ans, dplu[i][m]+dplb[i+1][j]+dprb[i+1][j+1]);
			//vertical line below of horizontal line
			ans=max(ans, dplb[i+1][m]+dplu[i][j]+dpru[i][j+1]);
		}
		//Checking for vertical line + horizontal line
		for(j=1; j<m; j++) for(i=1; i<n; i++) {
			//horizontal line to the right of vertical line
			ans=max(ans, dplu[n][j]+dpru[i][j+1]+dprb[i+1][j+1]);
			//horizontal line to the left of vertical line
			ans=max(ans, dplu[i][j]+dplb[i+1][j]+dpru[n][j+1]);
		}
		//Checking for two horizontal lines
		for(i=1; i<n-1; i++) {
			maxrow=-INF;
			for(j=i+1; j<n; j++) {
				build(i+1, j);
				for(soma=0, k=1; k<=m; k++) {
					soma+=s[k];
					maxrow=max(maxrow, soma);
					if(soma<0) soma=0;
				}
				ans=max(ans, dplu[i][m]+maxrow+dplb[j+1][m]);
			}
		}
		//Checking for two vertical lines
		for(i=1; i<m-1; i++) {
			maxcolumn=-INF;
			for(j=i+1; j<m; j++) {
				build_column(i+1, j);
				for(soma=0, k=1; k<=n; k++) {
					soma+=s[k];
					maxcolumn=max(maxcolumn, soma);
					if(soma<0) soma=0;
				}
				ans=max(ans, dplu[n][i]+maxcolumn+dpru[n][j+1]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
