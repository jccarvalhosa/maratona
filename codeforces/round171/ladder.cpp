#include <cstdio>

int a[100000], ng[100000], nl[100000];

int main() {
	int i, j, n, q;
	scanf("%d%d", &n, &q);
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	i=0;
	while(i != n) {
		j=i+1;
		while(j != n && a[j] >= a[j-1]) j++;
		while(i != j) ng[i++] = j-1;
	}
	i=0;
	while(i != n) {
		j=i+1;
		while(j != n && a[j] <= a[j-1]) j++;
		while(i != j) nl[i++] = j-1;
	}
	while(q--) {
		scanf("%d%d", &i, &j);
		i--; j--;
		if(nl[ng[i]] >= j) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
