#include <stdio.h>
#include <math.h>
#define EPS 0.0000000001

int main()
{
	int i, t, A[3], B[3], C[3], D[3];
	int v1[3], v2[3], v3[3];
	double v4[3];
	double a, b, c, d1, d2, p, S, H, V, norma;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d", &A[0], &A[1], &A[2]);
		scanf("%d%d%d", &B[0], &B[1], &B[2]);
		scanf("%d%d%d", &C[0], &C[1], &C[2]);
		scanf("%d%d%d", &D[0], &D[1], &D[2]);
		a = sqrt((B[0]-C[0])*(B[0]-C[0]) + (B[1]-C[1])*(B[1]-C[1]) + (B[2]-C[2])*(B[2]-C[2]));
		b = sqrt((A[0]-C[0])*(A[0]-C[0]) + (A[1]-C[1])*(A[1]-C[1]) + (A[2]-C[2])*(A[2]-C[2]));
		c = sqrt((A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]) + (A[2]-B[2])*(A[2]-B[2]));
		p = (a + b + c) / 2;
		S = sqrt(p * (p-a) * (p-b) * (p-c));
		v1[0] = B[0]-A[0];
		v1[1] = B[1]-A[1];
		v1[2] = B[2]-A[2];
		v2[0] = C[0]-A[0];
		v2[1] = C[1]-A[1];
		v2[2] = C[2]-A[2];
		v3[0] = D[0]-A[0];
		v3[1] = D[1]-A[1];
		v3[2] = D[2]-A[2];
		v4[0] = (v1[1]*v2[2] - v1[2]*v2[1]) / 10000.;
		v4[1] = (v1[2]*v2[0] - v1[0]*v2[2]) / 10000.;
		v4[2] = (v1[0]*v2[1] - v1[1]*v2[0]) / 10000.;
		norma = sqrt(v4[0]*v4[0] + v4[1]*v4[1] + v4[2]*v4[2]);
		H = fabs(norma) > EPS ? fabs(v3[0]*v4[0] + v3[1]*v4[1] + v3[2]*v4[2]) / norma : 0;
		V = S * H / 3;
		printf("%.6lf\n", V);
	}
	return 0;
}
