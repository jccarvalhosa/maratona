#include <cstdio>

int v[100001];

int main() {
	int i, f, n;
	scanf("%d", &n);
	if(n%4 == 2 || n%4 == 3) printf("-1\n");
	else {
		if(n%4 == 1) v[(n+1)/2] = (n+1)/2;
		i=1;
		f=n;
		while(i<f) {
			v[i]=f-1;
			v[f-1]=f;
			v[f]=i+1;
			v[i+1]=i;
			i+=2;
			f-=2;
		}
		for(i=1;i<=n;i++) printf("%d%c", v[i], i!=n?' ':'\n');
	}
	return 0;	
}
