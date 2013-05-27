#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int d[1000][1000][2] = {0};
int c[1000][1000] = {0};
int h, w, k;

void paint() {
	int i, j, p;
	if(h<w) {
		for(i=0;i<h;i++) {
			for(j=1;j<w;j++) {
				c[i][j]=c[i][j-1];
				if(d[i][j-1][0]) c[i][j]=1-c[i][j];
			}
			if(i) {
				p=0;
				for(j=0;j<w;j++) if(d[i-1][j][1] && c[i][j] == c[i-1][j]) p++;
				for(j=0;j<w;j++) if(d[i-1][j][1]==0 && c[i][j] != c[i-1][j]) p++;
				if(p > w/2) for(j=0;j<w;j++) c[i][j] = 1-c[i][j];
			}
		}
	}
	else {
		for(j=0;j<w;j++) {
			for(i=1;i<h;i++) {
				c[i][j]=c[i-1][j];
				if(d[i-1][j][1]) c[i][j]=1-c[i][j];
			}
			if(j) {
				p=0;
				for(i=0;i<h;i++) if(d[i][j-1][0] && c[i][j] == c[i][j-1]) p++;
				for(i=0;i<h;i++) if(d[i][j-1][0]==0 && c[i][j] != c[i][j-1]) p++;
				if(p > h/2) for(i=0;i<h;i++) c[i][j] = 1-c[i][j];
			}
		}
	}
}

int main() {
	int i, j, p, t;
	string s;
	cin>>h>>w>>k;
	for(i=0;i<2*h-1;i++) {
		cin>>s;
		if(i % 2 == 0) { for(j=0;j<w-1;j++) d[i/2][j][0] = (s[j]=='E'?0:1); }
		else { for(j=0;j<w;j++) d[(i-1)/2][j][1] = (s[j]=='E'?0:1); }
	}
	if(k==1) {
		t = h*(w-1) + (h-1)*w;
		p=0;
		for(i=0;i<h;i++) for(j=0;j<w-1;j++) if(d[i][j][0]) p++;
		for(i=0;i<h-1;i++) for(j=0;j<w;j++) if(d[i][j][1]) p++;
		if(4*p>t) printf("NO\n");
		else {
			printf("YES\n");
			for(i=0;i<h;i++) for(j=0;j<w;j++) printf("1%c", j==w-1?'\n':' ');
		}
	}
	else {
		k=2;
		paint();
		printf("YES\n");
		for(i=0;i<h;i++) for(j=0;j<w;j++) printf("%d%c", 1+c[i][j], j==w-1?'\n':' ');
	}
	return 0;
}
