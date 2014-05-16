#include <bits/stdc++.h>
using namespace std;

const int N=1111;
int card[N];
double dp[N][N];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		m--;
		int pos=m;
		int fim; 
		for(int i=0;i<pos;i++) card[i]=0;
		for(int i=0;i<n;i++) {
			string s;
			cin>>s;
			if(s.size() == 2) card[pos]=10;
			else if(s[0] == 'A') card[pos]=11;
			else if(isdigit(s[0])) card[pos]=s[0]-'0';
			else card[pos]=10;
			for(int i=1;i<card[pos];i++) card[pos+i]=0;
			fim=pos;
			pos += card[pos];
		}
		double ans=0;
		for(int x=1;x<card[fim];x++) {
			pos = fim+x;
			for(int i=0;i<pos;i++) for(int j=0;j<pos;j++) dp[i][j]=0;
			dp[pos-1][pos-1]=1;
			for(int a=pos-2;a>=0;a--) {
				if(card[a]) {
					if(a+card[a] >= pos) {
						dp[a][a]=1;
					}
					else {
						for(int i=a+card[a];i<pos;i++) dp[a][i] = dp[a+card[a]][i];
					}
				}
				else {
					for(int i=2;i<=11;i++) {
						double P = 1.0/13;
						if(i==10) P *= 4;
						if(a+i >= pos) dp[a][a] += P;
						else {
							for(int j=a+i;j<pos;j++) dp[a][j] += P*dp[a+i][j];
						}
					}
				}
			}
			double aux=0;
			for(int i=0;i<10;i++) for(int j=0;j<pos;j++) aux += 1.0/10 * dp[m][j] * dp[i][j];
			ans += aux/(card[fim]-1);
		}
		printf("%.15lf\n", ans);
	}
	return 0;
}
