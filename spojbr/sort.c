#include <stdio.h>

int main(){
	int l, c, r1, r2, i, cont=0, cabe[10000];
	do{
	scanf("%d",&l);
	scanf("%d",&c);
	scanf("%d",&r1);
	scanf("%d",&r2);			
	if(2 * r1 > l || 2 * r1 > c || 2 * r2 > l || 2 * r2 > c) cabe[cont] = 0;
	else if((l - r1 - r2) * (l - r1 - r2) + (c - r1 - r2) * (c - r1 - r2) >= (r1 + r2) * (r1 + r2)) cabe[cont] = 1;
	else if((l - r1 - r2) * (l - r1 - r2) + (r1 - r2) * (r1 - r2) >= (r1 + r2) * (r1 + r2)) cabe[cont] = 1;
	else if((l - r1 - r2) * (l - r1 - r2) + (r1 - r2) * (r1 - r2) >= (r1 + r2) * (r1 + r2)) cabe[cont] = 1;
	else if((c - r1 - r2) * (c - r1 - r2) + (r1 - r2) * (r1 - r2) >= (r1 + r2) * (r1 + r2)) cabe[cont] = 1;
	else cabe[cont] = 0;
	cont++;
	}while(l != 0 && c != 0 && r1 != 0 && r2 != 0);
	for(i=0;i<cont -1;i++){
		if(cabe[i] == 1) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
