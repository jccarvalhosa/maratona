#include <cstdio>
#include <cstring>

int main() {
	int t, n, i, cont;
	char v[10001];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", v);
		n = strlen(v);
		if(v[0] == 'W' || v[n-1] == 'B') printf("IMPOSSIBLE\n");
		else {
			for(i=1;i<n;i++) if(v[i] == 'B' && v[i-1] == 'W') break;
			if(i == n) {
				printf("1\n%d", n);
				for(i=0;i<n;i++) printf(" %d", i+1);
				printf("\n");
			}
			else {
				printf("2\n");
				cont=1;
				for(i=1;i<n-1;i++) if(v[i] == 'W') cont++;
				printf("%d %d", cont, 1);
				for(i=1;i<n-1;i++) if(v[i] == 'W') printf(" %d", i+1);
				printf("\n%d", n-cont);
				for(i=1;i<n-1;i++) if(v[i] == 'B') printf(" %d", i+1);
				printf(" %d\n", n);
			}
		}
	}
	return 0;
}
