#include <stdio.h>
#include <string.h>

int main(){
int i, t, n, total, pontos;
char frase[10];
while(1){
	scanf("%d%d", &t, &n);
	if(t == 0 && n == 0) return 0;
	total=0;
	for(i=0;i<t;i++){
		scanf("%s %d",frase, &pontos);
		total += pontos;
		}
	printf("%d\n", 3 * n - total);
}
}
