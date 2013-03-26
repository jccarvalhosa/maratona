#include <cstdio>

int p[1000001], s[1000001], v[1000001];

int main() {
	int n, t, i, top;
	scanf("%d", &n);
	for(i=1;i<=n;i++) {
		scanf("%d", v+i);
		s[i]=1;
	}
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &i);
		s[i]=-1;
	}
	top=0;
	for(i=n;i>0;i--) {
		if(s[i] == -1 || top==0 || p[top] != v[i]) {
			p[++top] = v[i];
			s[i] = -1;
		}
		else top--;
	}
	if(top) printf("NO\n");
	else {
		printf("YES\n");
		for(i=1;i<=n;i++) printf("%d%c", v[i]*s[i], i!=n?' ':'\n');
	}
	return 0;
}
