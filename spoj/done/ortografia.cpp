#include <cstdio>
#include <cstring>
int mod(int a) { return a > 0 ? a : -a; }

char d[1000][30], t[100][30];
char *a, *b;
int na, nb, vis[30][30][4], nd[1000], nt[100];

bool valid(int i, int j, int d) {
	vis[i][j][d]=1;
	if(d > 2) return false;
	if(i == na) return d+nb-j <= 2;
	if(j == nb) return d+na-i <= 2;
	if(a[i] == b[j]) return valid(i+1, j+1, d);
	if(!vis[i+1][j][d+1] && valid(i+1, j, d+1)) return true;
	if(!vis[i][j+1][d+1] && valid(i, j+1, d+1)) return true;
	if(!vis[i+1][j+1][d+1] && valid(i+1, j+1, d+1)) return true;
	return false;
}

int main() {
	int N, M, i, j, k;
	scanf("%d%d", &N, &M);
	for(i=0;i<N;i++) {
		scanf("%s", d[i]);
		nd[i] = strlen(d[i]);
	}
	for(i=0;i<M;i++) {
		scanf("%s", t[i]);
		nt[i] = strlen(t[i]);
	}
	for(i=0;i<M;i++) {
		int flag=0;
		for(j=0;j<N;j++) {
			a=t[i]; b=d[j];
			na = nt[i]; nb = nd[j];
			if(mod(na-nb) > 2) continue;
			for(int i=0;i<=na;i++) for(int j=0;j<=nb;j++) for(k=0;k<=3;k++) vis[i][j][k]=0;
			if(valid(0, 0, 0)) {
				if(flag) printf(" ");
				else flag=1;
				printf("%s", d[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
