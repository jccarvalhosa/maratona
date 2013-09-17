#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<int> v, c;

int mdc(int a, int b) { return a % b ? mdc(b, a % b) : b; }

void divisores(int n) {
    int i;
    v.clear();
    v.push_back(1);
    for(i=2;i*i<n;i++) if(n % i == 0) {
		v.push_back(i);
		v.push_back(n/i);
    }
    if(i*i == n) v.push_back(i);
    if(n != 1) v.push_back(n);
}

int main() {
    int i, j, f, t, k, m, r, cmin, ini, fim;
    unsigned long long total;
    while(scanf("%d", &f) && f) {
        c.clear();
        for(i=0;i<f;i++) scanf("%d", &j), c.push_back(j);
        m = cmin = c[0];
        r = c[0] % f;
        for(i=1;i<f;i++) {
            if(c[i] % f != r) break;
            if(cmin > c[i]) cmin = c[i];
            m = mdc(m, c[i]);
        }
        if(i != f) printf("0\n");
        else {
            divisores(m);
            total = 0;
            for(i=0;i<v.size();i++) {
                t = v[i];
                r = (c[0]/t) % f;
                for(j=1;j<f;j++) if((c[j] / t) % f != r) break;
                if(j != f) continue;
                fim = cmin/t - f;
                if(fim <= 0) continue;
                ini = (cmin/t) % f;
                if(ini == 0) ini += f;
                if(ini <= fim) total += (fim - ini) / f + 1;
            }
            printf("%llu\n", total);
        }
    }
    return 0;
}
