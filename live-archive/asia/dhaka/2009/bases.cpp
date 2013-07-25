#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
#define M 100000007

int q, n, m, t;
ll e[1111111];

ll prod(int t) {
    ll ret=1;
    for(int i=0;i<q;i++) {
        ret = (ret*(e[i]/t + 1))%M;
    }
    return ret;
}

int main() {
    int T=1;
    while(1) {
        cin>>n>>m>>t;
        if(n==0) break;
        printf("Case %d: ", T++);
        q=0;
        for(int i=2;i*i<=n;i++) if(n % i == 0) {
            e[q]=0;
            while(n % i == 0) {
                n/=i;
                e[q]++;
            }
            q++;
        }
        if(n!=1) e[q++] = 1;
        for(int i=0;i<q;i++) e[i] *= m;
        cout << (prod(t) - prod(t+1) + M)%M <<endl;
    }
    return 0;
}
