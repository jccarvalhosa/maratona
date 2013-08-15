#include <stdio.h>
#include <string.h>
#define MOD 1300031

int fatorial[2000001], inv[MOD];


int inverso(int a, int n){
	int exp=1;
	while(n > 0){		
		if(n % 2 == 1) exp = (long long)(exp * a) % MOD;
		a = (long long)(a * a) % MOD;
		n /= 2;
	}
	return exp;
}

int main(){
		memset(inv, 0, sizeof(inv));
		int i, t, c, n, aux;
		for(i=1;i<10;i++)   printf("%d\n",(inverso(i, MOD - 2)));
		fatorial[0] = 1;
		inv[0] = 1;		
		for(i=1;i<1300031;i++){
			if(inv[i] == 0){
			aux = inverso(i, MOD - 2);
			inv[i] = aux;
			inv[aux] = i;
			}
		}
		for(i=1;i<2000001;i++)	fatorial[i] = (long long)(fatorial[i-1] * i) % MOD;
		scanf("%d", &t);
		for(i=0;i<t;i++){
			scanf("%d%d", &n, &c);
			n = n + c - 1;
			c = n - c;
			aux = (long long)(fatorial[n] * inv[fatorial[c]] * inv[fatorial[n - c]]) % MOD;
			printf("%d\n", aux);
		}
		return 0;
}
		
		
