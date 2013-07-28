#include <cstdio>
#define MAX (1<<12)+1

char a[MAX];
int prime[1000], nprimes=1, p[1000], e[1000], k, ndivisors, divisor[10000], f[20000000];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a*b/gcd(a, b); }

void sieve(int d) {
    int i, j;
    for(i=2;i<MAX;i+=2) a[i]=1;
    prime[0]=2;
    for(i=3;i<MAX;i+=2) {
        if(a[i]) continue;
        prime[nprimes++]=i;
        for(j=2*i;j<MAX;j+=i) a[j]=1;
    }
}

void factor(int n) {
    k=0;
    for(int i=0;prime[i]*prime[i]<=n;i++) if(n%prime[i]==0) {
        p[k]=prime[i];
        e[k]=0;
        while(n%prime[i]==0) {
            n/=prime[i];
            e[k]++;
        }
        k++;
    }
    if(n!=1) {
        p[k]=n;
        e[k]=1;
        k++;
    }
}

void divisors() {
    int r, i, j, a;
    ndivisors=1; 
    divisor[0]=1; 
    for(i=0;i<k;i++) {
        r=ndivisors;
        for(j=0;j<e[i];j++) for(a=0;a<r;a++) divisor[ndivisors++]=p[i]*divisor[a+j*r];
    }
}

int exp(int a, int e) {
    if(e==0) return 1;
    if(e%2) return a*exp(a, e-1);
    return exp(a*a, e/2);
}

int search(int mod, int n) {
    int i, j;
    factor(n);
    divisors();
    f[0]=0;
    f[1]=1;
    for(i=1;i<ndivisors;i++) {
        for(j=2;j<divisor[i]+2;j++) f[j]=(f[j-1]+f[j-2])%mod;
        if(f[j-1]==1 && f[j-2]==0) return divisor[i];
    }
}

int period_prime(int n) {
    if(n==2) return 3;
    if(n==3) return 8;
    if(n==5) return 20;
    if((n-1)%5==0 || (n+1)%5==0) return search(n, n-1);
    return search(n, 2*n+2);
}

int period(int n) {
    int i, mmc=1, pa[10000], ea[10000], ka;
    factor(n);
    for(i=0;i<k;i++) pa[i]=p[i], ea[i]=e[i];
    ka=k;
    for(i=0;i<ka;i++) mmc=lcm(mmc, exp(pa[i], ea[i]-1)*period_prime(pa[i]));
    return mmc;
}

int main() {
    int t, i, n, j, m;
    sieve(MAX);
    while(scanf("%d", &n) && n) printf("%d %d\n", n, period(n));
    return 0;
}
