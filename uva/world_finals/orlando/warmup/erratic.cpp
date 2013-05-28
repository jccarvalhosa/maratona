#include <cstdio>
#include <iostream>
using namespace std;

long long line(int a, int k) {
    if(a==0) return 0;
    if(k==0) return 1;
    if(a & 1) return 2*line(a/2+1, k-1);
    return line(a/2, k-1);
}

long long query(int a, int k) {
     if(a==0) return 0;
     if(k==0) return 1;
     long long ret = 3*query(a/2, k-1);
     if(a & 1) ret += 2*line(a/2+1, k-1);
     return ret;
}

int main() {
    int T, t, k, a, b;
    cin>>T;
    for(t=1;t<=T;t++) {
        cin>>k>>a>>b;
        printf("Case %d: ", t);
        cout << query(b, k) - query(a-1, k) << endl;
    }
    return 0;
}
