#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1<<30

char s[1500];
int dp[1500][2];

int dynamic() {
	dp[24*60][0]=0;
	dp[24*60][1]=INF;
	for(int t=24*60-1;t>=0;t--) {
		if(s[t]=='.') {
			dp[t][0] = min(dp[t+1][0], dp[t+1][1]);
			dp[t][1] = INF;
		}
		if(s[t]=='U') {
			dp[t][0] = 28 + min(dp[t+1][0], dp[t+1][1]);
			dp[t][1] = 44;
			int tf;
			for(tf=t+1;tf<=t+90 && tf<24*60;tf++) if(s[tf]=='U') break;
			dp[t][1] += min(dp[tf][0], dp[tf][1]);
		}
		if(s[t]=='S') {
			dp[t][0] = 26 + min(dp[t+1][0], dp[t+1][1]);
			dp[t][1] = 44;
			int tf, train=0;
			for(tf=t+1;tf<=t+90 && tf<24*60;tf++) if(s[tf]=='U') {
				if(train) break;
				else train=1;
			}
			dp[t][1] += min(dp[tf][0], dp[tf][1]);
		}
	}
	return min(dp[0][0], dp[0][1]);
}

int greedy() {
	int ret=0, hasplan=0, train=0, oldtime=-1000;
	char c;
	for(int t=0;t<24*60;t++) {
		if(hasplan && (t - oldtime) > 90) hasplan=0;
		if(s[t]=='U') {
			if(c == 'U') {
				ret += 28;
				oldtime = t;
				hasplan=0;
				continue;
			}
			c='U';
			if(hasplan) {
				if(!train) train=1;
				else {
					oldtime = t;
					ret += 28;
					hasplan = 0;
				}
			}
			else if(t-oldtime <= 90) {
				hasplan=1;
				train=1;
				ret += 44 - 26;
			}
			else {
				oldtime = t;
				ret += 28;
			}
		}
		if(s[t]=='S') {
			if(!hasplan) {
				if((t - oldtime) <= 90) {
					hasplan=1;
					if(c == 'U') {
						ret += 44 - 28;
						train=1;
					}
					else {
						ret += 44 - 26;
						train=0;
					}
				}
				else {
					oldtime = t;
					ret += 26;
				}
			}
			c = 'S';
		}
	}
	return ret;
}

int main() {
	int n;
	while(cin>>n && !cin.eof()) {
		memset(s, '.', sizeof(s));
		for(int i=0;i<n;i++) {
			int h, m;
			char c;
			scanf("%d:%d %c", &h, &m, &c);
			s[h*60 + m]=c;
		}
		cout << greedy() << " " << dynamic() << endl;
	}
	return 0;
}
