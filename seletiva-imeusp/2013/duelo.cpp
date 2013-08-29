#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n[2], v[2];
double p[2][33][55], dp[2][390][390];

int main() {
    while(scanf("%d %d %d %d", &v[0], &v[1], &n[0], &n[1]) != EOF) {
		int cont[2][12] = {0};
        for(int ind=0;ind<2;ind++) {
            for(int i=0;i<n[ind];i++) {
				int d;
				cin>>d;
				int c[55]={0}, l[5]={0};
                for(int j=0;j<d;j++) {
					cin>>l[j];
					cont[ind][i] += l[j];
				}
				double f[11][55] = {0};
				f[0][0]=1;
				for(int k=1;k<=d;k++) for(int j=1;j<=l[k-1];j++) for(int s=j;s<=cont[ind][i];s++) f[k][s] += f[k-1][s-j]/l[k-1];
                for(int l=1;l<=cont[ind][i];l++) p[ind][i][l] = f[d][l];
            }
        }
        int vmax = max(v[0], v[1]); 
        for(int sum=1;sum<=2*vmax;sum++) for(int i=1;i<=vmax;i++) {
			int j = sum-i;
			if(j>vmax || j<0) continue; 
            dp[0][i][0]=dp[1][i][0] = 1;
            for(int k=0;k<2;k++) {
                dp[k][i][j]=0;
				if(i>v[k] || j>v[1-k]) continue;
                for(int s=0;s<n[k];s++) {
                    double P=0;
                    for(int l=1;l<=cont[k][s];l++) {
                        if(l>=j) P += p[k][s][l];
                        else P += p[k][s][l] * (1 - dp[1-k][j-l][i]);
                    }
                    dp[k][i][j] = max(dp[k][i][j], P);
                }
            }
        }
        printf("%.3lf\n", dp[0][v[0]][v[1]]);
    }
    return 0;
}
