#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 111111

int prime[8888];
int vis[M];

int exp(int a, int e, int m) {
    if(e==0) return 1;
    if(e%2==0) return exp((a*a)%m, e/2, m);
    return (a*exp(a, e-1, m))%m;
}

int main() {
    for(int i=2;i<8888;i++) prime[i]=1;
    for(int i=2;i<8888;i++) if(prime[i]) for(int j=2*i;j<8888;j+=i) prime[j]=0;
    int n, p;
    while(1) {
        cin>>n>>p;
        if(n==p && n==0) return 0;
        memset(vis, 0, sizeof(vis));
        for(int i=2;i<=p;i++) if(prime[i]) {
            int m = exp(10, n-1, i);
            int s=0;
            if(m!=0) s = i-m;
            while(s<M) {
                vis[s]=1;
                s += i;
            }
        }
        for(int i=0;i<M-2;i++) if(!vis[i] && !vis[i+2]) {
            int aux=i, d=0;
            while(aux) {
                d++;
                aux /= 10;
            }
            printf("1");
            for(int j=0;j<n-d-1;j++) printf("0");
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
