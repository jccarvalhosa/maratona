#include <stdio.h>
#include <math.h>


int main(){
	
	int ev1, ev2, at, d, n1, n2;
	float x1, x2, resposta;
	double  A, B, p, q;
	while(1){
		scanf("%d%d%d%d", &ev1, &ev2, &at, &d);
		if(ev1 == 0 && ev2 == 0 && at == 0 && d == 0) return 0;
		p = at / 6.0;
		q = 1 - p;
		if(ev1 % d != 0)  n2 = ev1 / d + 1;
		else n2 = ev1 / d;
		if(ev2 % d != 0)  n1 = ev2 / d + 1;
		else n1 = ev2 / d;
		if(p == q){
			A = 1;
			B = -1.0 / (n1 + n2);
			resposta = 100 * (1 - (float)n1 / (n1 + n2));
		}
		else{
			x1 = (float)(1 + sqrt(1 - 4 * p * q))/ (2 * q);
			x2 = 1.0 / q - x1;
			A = 1.0 / (1 - pow(x2, n1 + n2) / pow(x1, n1 + n2));
			B = 1 - A;
			resposta = 100 * (A * pow(x2, n1) + B * pow(x1, n1));
		}
		printf("%.1f\n", resposta);
	}
}
