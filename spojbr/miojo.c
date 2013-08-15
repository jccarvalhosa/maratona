#include <stdio.h>

int mdc(int n1, int n2){
	int resto; 
	resto=n1%n2;
    while(resto!=0){
         n1    = n2;
         n2    = resto;
         resto = n1%n2;        
    }
    return n2;
}
    
int inv(int n2, int n1){
	int i;
	for(i=0; i<n1;i++){
		if((n2 * i) % n1 == 1) return i;
	}
}

int main(){
	int k1, k2, a, b, n, aux;
	scanf("%d%d%d", &n, &k1, &k2);
	printf("mdc = %d\n", mdc(k1,k2));
	aux = mdc(k1,k2);
	k1 = k1 / aux;
	k2 = k2 / aux;
	n = n / aux;
	if(k2 > k1){
		aux = k1;
		k1 = k2;
		k2 = aux;
	}
	printf("n = %d\n", n);
	printf("k1 = %d\n", k1);
	printf("k2 = %d\n", k2);
	printf("inverso = %d\n", inv(k2,k1));
	b = ((n % k1) * inv(k2, k1)) % k1;
	a = (n - k1*b) / k1;
	printf("a = %d\nb = %d\n", a, b);
	printf("n = %d\n", a*k1 + b*k2);
	return 0;
}
	
