#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;

char sa[21], sb[21];
int len, vis[22][2][2][3][3];
ull dp[22][2][2][3][3];

ull go(int pos, bool ga, bool lb, int ca, int cb) {
	ull& ret = dp[pos][ga][lb][ca][cb];
	if(vis[pos][ga][lb][ca][cb]) return ret;
	vis[pos][ga][lb][ca][cb]=1;
	if(pos==len) return ret=(ca >= 1 && cb <= 1);
	ret=0;
	for(char c=(pos==0 ? '1' : '0');c<='9';c++) {
		if(!ga && c < sa[pos]) continue;
		if(!lb && c > sb[pos]) continue;
		char a = sa[len-pos-1];
		char b = sb[len-pos-1];
		ret += go(pos+1, ga || (c > sa[pos]), lb || (c < sb[pos]), c==a ? ca : 2*(c>a), c==b ? cb : 2*(c>b));
	}
	return ret;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		ull a, b;
		cin>>a>>b;
		sprintf(sa,"%llu",a);
		sprintf(sb,"%llu",b);
		int lena = strlen(sa);
		int lenb = strlen(sb);
		ull ans=0;
		for(len=lena;len<=lenb;len++) {
			memset(vis, 0, sizeof(vis));
			if(len == lenb) sprintf(sb,"%llu",b);
			else memset(sb, '9', sizeof(sb));
			ans += go(0, 0, 0, 1, 1);
			sa[len]='0';
			rotate(sa, sa+len, sa+len+1);
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
