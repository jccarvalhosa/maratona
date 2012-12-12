#include <stdio.h>
#include <string.h>
#define MOD 1000000009

typedef long long ll;

struct matrix {
    ll elem[3][3];
    matrix() { 
        ll aux[][3] = {1, 1, 1, 1, 0, 0, 0, 1, 0};
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) elem[i][j] = aux[i][j];
    }
    matrix(int i) { 
        memset(elem, 0, sizeof(elem));
        if(i == 1) elem[0][0] = elem[1][1] = elem[2][2] = 1;
    }
};

matrix mul(matrix a, matrix b) {
    int i, j, k;
    matrix c(0);
    for(i=0;i<3;i++) for(j=0;j<3;j++) for(k=0;k<3;k++) c.elem[i][j] = (c.elem[i][j] + a.elem[i][k] * b.elem[k][j]) % MOD;
    return c;
}

int main() {
    ll n;
    matrix m[54];
    for(int i=1;i<54;i++) m[i] = mul(m[i-1], m[i-1]);
    while(scanf("%lld", &n) && n) {
        if(n < 3) printf("%lld\n", n-1);
        else {
            matrix resp = matrix(1);
            n -= 3;
            for(int i=0;i<54;i++, n /= 2) if(n & 1) resp = mul(resp, m[i]);
            printf("%lld\n", (2*resp.elem[0][0] + resp.elem[0][1]) % MOD);
        }
    }
    return 0;
}
