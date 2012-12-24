#include <cstdio>
#include <cstring>
#define MAX 1500

bool T[MAX+3][MAX+3];

int main() {
	int N, i, j, X, Y, L, C, a, p;
	while(scanf("%d", &N) && N) {
		memset(T, 0, sizeof(T));
		while(N--) {
			scanf("%d%d%d%d", &X, &Y, &L, &C);
			X++; Y++; L; C;
			for(i=X;i<X+L;i++) for(j=Y;j<Y+C;j++) T[i][j]=1;
		}
		a=p=0;
		for(i=1;i<MAX+2;i++) for(j=1;j<MAX+2;j++) if(T[i][j]) {
			a++;
			if(!T[i-1][j]) p++;
			if(!T[i+1][j]) p++;
			if(!T[i][j-1]) p++;
			if(!T[i][j+1]) p++;
		}
		printf("%d %d\n", a, p);
	}
	return 0;
}
