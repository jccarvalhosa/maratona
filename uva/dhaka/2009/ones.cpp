#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<int, ll> vis;

ll go(int n) {
    if(n<=0) return 0;
    if(vis.count(n)) return vis[n];
    int p = 1<<(31-__builtin_clz(n));
    return vis[n] = n-p+1 + go(n-p) + go(p-1);
}

int main() {
    int a, b, t=1;
    while(1) {
        cin>>a>>b;
        if(a==0 && b==0) break;
        printf("Case %d: ", t++);
        cout << go(b) - go(a-1) << endl;
    }
    return 0;
}
