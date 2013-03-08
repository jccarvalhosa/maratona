#include <cstdio>
#include <cstring>
#define MOD 10007
typedef long long ll;

int K=0;

struct matrix {
    int elem[100][100];
    matrix() { 
		memset(elem, 0, sizeof(elem));
		for(int i=1;i<K;i++) elem[i][0] = 1;
        for(int i=0;i<K;i++) elem[i][i+1] = 1;
    }
};

matrix mul(matrix a, matrix b) {
    int i, j, k;
    matrix m;
	memset(m.elem, 0, sizeof(m.elem));
    for(i=0;i<K;i++) for(j=0;j<K;j++) for(k=0;k<K;k++) m.elem[i][j] = (m.elem[i][j] + a.elem[i][k] * b.elem[k][j]) % MOD;
    return m;
}

matrix exp(matrix m, int n) {
	if(n == 1) return m;
	if(n == 2) return mul(m, m);
	if(n % 2 == 0) return exp(mul(m, m), n/2);
	return mul(m, exp(mul(m, m), (n-1)/2));
}

int main() {
	int T, t, n, ans, i, j;
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		printf("Case %d: ", t);
		scanf("%d%d", &n, &K);
		if(n==1) printf("2\n");
		else {
			matrix M = exp(matrix(), n-1);
			ans = 0;
			for(i=0;i<K;i++) ans = (ans + 2*M.elem[0][i]) % MOD;
			printf("%d\n", ans);
		}
	}
    return 0;
}
