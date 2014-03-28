#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e6+10;
char s[N];
int l[N], r[N], p[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	p[0]=0;
	l[0]=N, r[0]=-N;
	for(int i=1;i<=n;i++) {
		l[i] = min(l[i-1], p[i-1]);
		r[i] = max(r[i-1], p[i-1]);
		if(s[i-1]=='L') p[i] = p[i-1]-1;
		else p[i] = p[i-1]+1;
	}
	if(p[n] > r[n] || p[n] < l[n]) printf("1\n");
	else {
		int ans=0;
		int m = -N;
		for(int i=0;i<n;i++) m = max(m, p[i]-l[i]);
		if(p[n]-l[n] > m) {
			for(int i=l[n];i<0;i++) {
				if(p[n]-l[n]+i+1 > r[n]) {
					ans++;
				}
			}
		}
		m = N;
		for(int i=0;i<n;i++) m = min(m, p[i]-r[i]);
		if(p[n]-r[n] < m) {
			for(int i=r[n];i>0;i--) {
				if(p[n]-r[n]+i-1 < l[n]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
